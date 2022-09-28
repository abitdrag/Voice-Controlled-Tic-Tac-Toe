// This file will generate the observation sequence
#pragma once
#include "constants.h"
#include "stdafx.h"
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// This function will normalize the input from first file and write it to the second file
// The limit of normalization chosen here is 5000
void normalize_input(FILE *input, FILE *output, int limit = 5000){
	double max = 0, dcShift = 0, sampleCount = 0;
	char singleLine[100];

	//calculate DC shift
	while(!feof(input)){
		fgets(singleLine, 100, input);
		if(!isalpha(singleLine[0])){
			double x = atof(singleLine);
			dcShift += x;
			sampleCount ++;
		}
	}
	sampleCount--;
	dcShift /= (sampleCount);
	//calculate normalization factor
	rewind(input);
	while(!feof(input)){
		fgets(singleLine, 100, input);
		if(!isalpha(singleLine[0])){
			double x = atof(singleLine);
			if(max < abs(x)){
				max = abs(x);
			}
		}
	}
	double normalizationFactor = abs(max - limit)/(max * 1.0);
	rewind(input);
	while(!feof(input)){
		fgets(singleLine, 100, input);
		if(!isalpha(singleLine[0])){
			double x = atof(singleLine);
			double normalized_output = (x-dcShift) * normalizationFactor;
			/*if(normalized_output > 100){
				printf("%lf\n", normalized_output);
			}*/
			fprintf(output, "%g\n", normalized_output);
		}
	}
}

// This function skips the frames
long skipFrames(FILE *input, long skipFrameCnt = 25*N){
	long cnt = 0, pos;
	char singleLine[100];
	while(!feof(input)){
		fgets(singleLine, 100, input);
		if(!isalpha(singleLine[0]))
			cnt ++;
		if(cnt > skipFrameCnt){
			pos = ftell(input);
			break;
		}
	}
	return pos;
}


//This function finds the steady frames and stores them in s
void skip_frames(FILE *input, long double stable_frames[TOTAL_FRAMES+1][SAMPLES_PER_FRAME+1]){
	char singleLine[100];
	long double samples[TOTAL_FRAMES+1][SAMPLES_PER_FRAME+1] = {{0}}, energy[TOTAL_FRAMES+1] = {0};
	int sampleCnt = 0, frameCnt = 0, pos = 0;
	
	//reading the entire input and dividing them into frames and saving it in a
	//matrix (samples) of size number of frames x 320 (N)
	rewind(input);
	while(!feof(input) && frameCnt<TOTAL_FRAMES){
		fgets(singleLine, 100, input);
		if(!isalpha(singleLine[0])){
			samples[frameCnt][sampleCnt] = atof(singleLine);
			if(sampleCnt >= SAMPLES_PER_FRAME){
				sampleCnt = 0;
				frameCnt ++;
			}
			else{
				sampleCnt++;
			}
			// if(samples[frameCnt][sampleCnt] > 1000)
				// printf("%lf ", samples[frameCnt][sampleCnt]);
		}
	} 

	//calculating STE for each of the frames and saving it in an array
	for(int i=0; i<TOTAL_FRAMES; i++){
		long double sum = 0;
		for(int j=0; j<SAMPLES_PER_FRAME; j++){
			sum += (samples[i][j] * samples[i][j]);
		}
		energy[i] = sum/((long double)SAMPLES_PER_FRAME);
		// printf("%lf\n", energy[i]);
	}

	//finding out the frame with max STE and saving it in pos
	long double maxEnergy = DBL_MIN;
	for(int i=0; i<TOTAL_FRAMES; i++){
		if(energy[i] > maxEnergy){
			maxEnergy = energy[i];
			pos = i;
		}
	}

	for(int i=0; i<TOTAL_FRAMES; ++i){
		for(int j=0; j<SAMPLES_PER_FRAME; ++j){
			stable_frames[i][j] = samples[i][j];
		}
		i++;
	}
}

// This function applies hamming window on the sample data
double hammingWindow(int m){
	return (0.54-0.46*cos(2*3.14*m/N-1));
}


// This function applies hamming window on all stable frames passed as parameter
void applyHamming(long double s[TOTAL_FRAMES+1][SAMPLES_PER_FRAME+1]){
	for(int i=0; i<TOTAL_FRAMES; ++i){
		for(int j=0; j<SAMPLES_PER_FRAME; ++j){
			s[i][j] *= hammingWindow(s[i][j]);
		}
	}

}

// This function calculates R and stores it in r array
void calculateR(long double s[TOTAL_FRAMES+1][SAMPLES_PER_FRAME+1], long double r[TOTAL_FRAMES+1][p+1]){
	for(int f=0; f<TOTAL_FRAMES; ++f){
		for(int k=0; k<=p; ++k){
			for(int m=0; m<=SAMPLES_PER_FRAME-k-1; ++m){
				r[f][k] += s[f][m]*s[f][m+k];
			}
		}
	}
}

// This function calculates A and stores it in array a
void calculateA(long double r[TOTAL_FRAMES+1][p+1], long double a[TOTAL_FRAMES+1][p+1]){
	for(int f=0; f<TOTAL_FRAMES; ++f){
		double e[p+1] = {0}, k[p+1] = {0},  alpha[p+1][p+1] = {{0}};
		e[0] = r[f][0];
		for(int i=1; i<=p; ++i){
			double sum = 0;
			for(int j=1; j<=i-1; ++j){
				sum += alpha[i-1][j]*r[f][i-j];
			}
			k[i] = (r[f][i] - sum)/e[i-1];
			alpha[i][i] = k[i];
			for(int j=1; j<=i-1; ++j){
				alpha[i][j] = alpha[i-1][j] - k[i] * alpha[i-1][i-j];
			}
			e[i] = (1-k[i]*k[i])*e[i-1];
		}
		for(int i=1; i<=p; ++i){
			a[f][i] = alpha[p][i];
		}
	}
}

// This function applys the raised sin window on Ci's
double raisedSin(int m){
	return 1+(p*1.0/2)*sin(3.14*m/12);
}

// This function generates the C matrix
void calculateC(long double r[TOTAL_FRAMES+1][p+1], long double a[TOTAL_FRAMES+1][p+1], long double c[TOTAL_FRAMES+1][p+1]){
	for(int f=0; f<TOTAL_FRAMES; ++f){
		double sigma = r[f][0];
		c[f][0] = log10(sigma*sigma);
		for(int m=1; m<=p; ++m){
			double sum = 0;
			for(int k=1; k<=m-1; ++k){
				sum += (k/(m*1.0))*c[f][k]*a[f][m-k];
			}
			c[f][m] = a[f][m] + sum;
		}
	}

	//applying raised sin
	for(int i=0; i<TOTAL_FRAMES; ++i){
		for(int j=1; j<=p; ++j){
			c[i][j] *= raisedSin(j);
		}
	}
}

// This function calculates the tokhura distance between two ci's 
long double tokhura_distance(long double ci[p+1], long double codebook[p+1], long double weight[p]){
	long double distance = 0;
	for(int i=1; i<p+1; i++){
		long double prod = weight[i-1]*(ci[i]-codebook[i])*(ci[i]-codebook[i]);
		distance = distance + prod;
	}
	return distance;
}

// This function generates an observation sequence for a digit for given sequence number
// The result is stored in the array Observation_sequence
void generate_observation_sequence(long double codebook[M+1][p+1], char *samples_filename, int seq, long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], long double weight[p]){
	// get file pointers
	FILE *input = fopen(samples_filename, "r");
	if(!input){
		printf("Cannot open file %s!", samples_filename);
		return;
	}
	FILE *input_normalized = fopen("normalized_input.txt", "w+");
	if(!input_normalized){
		printf("Cannot open file normalized_input.txt!");
		return;
	}
	// Initialize other variables
	long double stable_frames[TOTAL_FRAMES+1][SAMPLES_PER_FRAME+1], r[TOTAL_FRAMES+1][p+1] = {{0}}, a[TOTAL_FRAMES+1][p+1] = {{0}}, c[TOTAL_FRAMES+1][p+1] = {{0}};
	// write the normalized input in normalized_input.txt file
	normalize_input(input, input_normalized);

	// skip the frames and find the stable frames
	skip_frames(input_normalized, stable_frames);
	// applying hamming window on stable frames
	applyHamming(stable_frames);
	// calculating R matrix
	calculateR(stable_frames, r);
	// calculating A matrix
	calculateA(r, a);
	// calculating C matrix
	calculateC(r, a, c);
	// This function will calculate the tokhura distance
	for(int i=1; i<=T; ++i){
		long double min_distance = DBL_MAX;
		int min_index = -1;
		for(int j=1; j<=M; ++j){
			long double distance = tokhura_distance(c[i], codebook[j], weight);
			//printf("Distance: %g Frame:%d Sequence:%d\n", distance, i, seq);
			if(min_distance > distance){
				min_distance = distance;
				min_index = j;
			}
		}
		// update the observation sequence 
		Observation_sequence[seq][i] = min_index;
	}
	fclose(input);
	fclose(input_normalized);
}

// This function writes the observation sequences for a word to the file
void write_observation_sequence_to_file(long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], char *filename){
	FILE *observation_sequence_file = fopen(filename, "w");
	if(!observation_sequence_file){
		printf("Cannot open file %s!", filename);
		return;
	}
	for(int i=1; i<TRAINING_SEQUENCES+1; i++){
		for(int j=1; j<T+1; j++){
			fprintf(observation_sequence_file, "%d ", Observation_sequence[i][j]);
		}
		fprintf(observation_sequence_file, "\n");
	}
	fclose(observation_sequence_file);
}

// This function writes the observation sequences of test files for a word to the file
void write_observation_sequence_to_file_test(long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], char *filename){
	FILE *observation_sequence_file = fopen(filename, "w");
	if(!observation_sequence_file){
		printf("Cannot open file %s!", filename);
		return;
	}
	for(int i=1; i<TESTING_SEQUENCES+1; i++){
		for(int j=1; j<T+1; j++){
			fprintf(observation_sequence_file, "%d ", Observation_sequence[i][j]);
		}
		fprintf(observation_sequence_file, "\n");
	}
	fclose(observation_sequence_file);
}
