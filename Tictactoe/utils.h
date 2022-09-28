#pragma once
#include "stdafx.h"
#include "constants.h"
#include <stdlib.h>
#include <string.h>

// This function sets all the array elements to 0
void clean_arrays(long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int observation_sequence[TRAINING_SEQUENCES+1][T+1], long double alpha[T+1][N+1], long double beta[T+1][N+1],
					long double delta[N+1][T+1], long double psi[N+1][T+1], int Q_star[T+1], long double *p_star){
	// Cleaning A matrix
	for(int i=0; i<N+1; i++){
		for(int j=0; j<N+1; j++){
			A[i][j] = 0;
		}
	}

	// Cleaning B matrix
	for(int i=0; i<N+1; i++){
		for(int j=0; j<M+1; j++){
			B[i][j] = 0;
		}
	}

	// Cleaning Pi vector
	for(int i=0; i<N+1; i++){
		Pi[i] = 0;
	}

	// Cleaning observation sequence
	for(int i=0; i<TRAINING_SEQUENCES+1; i++){
		for(int j=0; j<T+1; j++){
			observation_sequence[i][j] = 0;
		}
	}

	// Cleaning alpha
	for(int i=0; i<T+1; i++){
		for(int j=0; j<N+1; j++){
			alpha[i][j] = 0;
		}
	}

	// Cleaning beta
	for(int i=0; i<T+1; i++){
		for(int j=0; j<N+1; j++){
			beta[i][j] = 0;
		}
	}

	// Cleaning delta
	for(int i=0; i<N+1; i++){
		for(int j=0; j<T+1; j++){
			delta[i][j] = 0;
		}
	}

	// Cleaning psi
	for(int i=0; i<N+1; i++){
		for(int j=0; j<T+1; j++){
			psi[i][j] = 0;
		}
	}

	// Cleaning p_star
	*p_star = 0;

	// Cleaning q_star
	for(int i=0; i<T+1; i++){
		Q_star[i] = 0;
	}

}

// This function reads the matrix A from file and write it to the 2D array
void read_A(char *filename, long double A[N+1][N+1]){
	FILE *fptr;
	char line[1024];
	char *temp, *token;
	int counter = 1;

	// opening file
	if((fptr = fopen(filename, "r")) == NULL){
		printf("ERROR: Can not open file %s.", filename);
		return;
	}

	// Read file line by line
	while(fgets(line, 1024, fptr)){
		token = strtok(line, "\t");
		for(int i=1; i<N+1; i++){
			// store the number 
			A[counter][i] = strtod(token, &temp);
			// get the next token
			token = strtok(NULL, "\t");
		}
		counter++;
	}
	fclose(fptr);
}

// This function prints the array A on the console. 
void print_A(long double A[N+1][N+1]){
	printf("\nA matrix:\n");
	for(int i = 1; i < N+1; i++){
		for(int j = 1; j < N+1; j++)
			printf("%g ", A[i][j]);
		printf("\n");
	}
	printf("\n");
}

// This function reads the matrix B from the file and stores it to array B
void read_B(char *filename, long double B[N+1][M+1]){
	FILE *fptr;
	char line[1024];
	char *temp, *token;
	int counter = 1;

	// opening file
	if((fptr = fopen(filename, "r")) == NULL && counter <= N){
		printf("ERROR: Can not open file %s.", filename);
		return;
	}

	// Read file line by line
	while(fgets(line, 1024, fptr)){
		token = strtok(line, "\t");
		for(int i=1; i<M+1; i++){
			// store the number 
			B[counter][i] = strtod(token, &temp);
			// get the next token
			token = strtok(NULL, "\t");
		}
		counter++;
	}
	fclose(fptr);
}

// This function prints the matrix B on the console
void print_B(long double B[N+1][M+1]){
	printf("\nB matrix:\n");
	for(int i = 1; i < N+1; i++){
		for(int j = 1; j < M+1; j++)
			printf("%g ", B[i][j]);
		printf("\n");
	}
	printf("\n");
}

// This function reads the vector PI from the file and stores it in array
void read_Pi(char *filename, long double Pi[N+1]){
	FILE *fptr;
	char line[1024];
	char *temp, *token;

	// opening file
	if((fptr = fopen(filename, "r")) == NULL){
		printf("ERROR: Can not open file %s.", filename);
		return;
	}

	// Read file
	fgets(line, 1024, fptr);
	token = strtok(line, "\t");
	for(int i=1; i<N+1; i++){
		// store the number 
		Pi[i] = strtod(token, &temp);
		// get the next token
		token = strtok(NULL, "\t");
	}
	fclose(fptr);
}

// This function prints the pi vector on the console
void print_Pi(long double Pi[N+1]){
	printf("\nPi vector:\n");
	for(int i=1; i<N+1; i++){
		printf("%g ", Pi[i]);
		printf("\n");
	}
	printf("\n");
}

// This function reads the observation sequence into matrix
void read_Observation_sequence(char *filename, long int Observation_sequence[TRAINING_SEQUENCES+1][T+1]){
	FILE *fptr;
	char line[1024];
	char *temp;
	int counter = 1;

	// opening file
	if((fptr = fopen(filename, "r")) == NULL){
		printf("ERROR: Can not open file %s.", filename);
		return;
	}

	char *token;
	int l=1;
	while(fgets(line, 1024, fptr)){
		// printf("%s\n", line);
		token = strtok(line, " ");
		for(int i=1; i<T+1; i++){
			// store the number 
			Observation_sequence[l][i] = strtol(token, &temp, 10);
			// get the next token
			token = strtok(NULL, " ");
		}
		l++;
	}
	fclose(fptr);
}

// This function prints the observation sequence
void print_Observation_sequence(long int Observation_sequence[TRAINING_SEQUENCES+1][T+1]){
	printf("Observation  Matrix-----------------------\n");
	for(int a = 1; a<TRAINING_SEQUENCES+1; a++){
		for(int b = 1;b<=T;b++)
			printf("%ld ", Observation_sequence[a][b]);
		printf("\n");
	}
}

// This function prints one observation sequence
void print_Observation_sequence(long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], int seq){
	printf("\nObservation sequence for sequence number %d:\n", seq);
	for(int b = 1; b<T+1; b++)
			printf("%ld ", Observation_sequence[seq][b]);
}

// THis function finds the average lambda model
void average_lambda(long double collect_A[TRAINING_SEQUENCES+1][N+1][N+1], long double collect_B[TRAINING_SEQUENCES+1][N+1][M+1], long double A[N+1][N+1], long double B[N+1][M+1]){
	for(int i=0; i<N+1; i++){
		for(int j=0; j<N+1; j++){
			A[i][j] = 0;
		}
	}
	for(int i=0; i<N+1; i++){
		for(int j=0; j<M+1; j++){
			B[i][j] = 0;
		}
	}
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			for(int k=1; k < TRAINING_SEQUENCES+1; k++){
				A[i][j] += collect_A[k][i][j];
			}
			A[i][j] /= (TRAINING_SEQUENCES * 1.0);
		}
	}

	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			for(int k=1; k < TRAINING_SEQUENCES+1; k++){
				B[i][j] += collect_B[k][i][j];
			}
			B[i][j] /= (TRAINING_SEQUENCES * 1.0);
		}
	}
}

// This function prints the lambda to file
void print_lambda_to_file(long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], char *Afilename, char *Bfilename, char *pifilename){
	FILE *output_A = fopen(Afilename, "w");
	if(!output_A){
		printf("Cannot open file!\n");
		exit(0);
	}
 
	FILE *output_B = fopen(Bfilename, "w");
	if(!output_B){
		printf("Cannot open file!\n");
		exit(0);
	}
 
	FILE *output_pi = fopen(pifilename, "w");
	if(!output_pi){
		printf("Cannot open file!\n");
		exit(0);
	}
 
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; ++j){
			fprintf(output_A, "%g ", A[i][j]);
		}
 
		for(int j=1; j<M+1; ++j){
			fprintf(output_B, "%g ", B[i][j]);
		}
 
		fprintf(output_pi, "%g ", Pi[i]);
		fprintf(output_A, "\n");
		fprintf(output_B, "\n");
	}
 
	fclose(output_A);
	fclose(output_B);
	fclose(output_pi);
}

// This function finds the average lambda
void collect_lambda(int seq, long double collect_A[TRAINING_SEQUENCES+1][N+1][N+1], long double collect_B[TRAINING_SEQUENCES+1][N+1][M+1], long double A[N+1][N+1], long double B[N+1][M+1]){
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			collect_A[seq][i][j] = A[i][j];
		}
	}

	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			collect_B[seq][i][j] = B[i][j];
		}
	}
}

// This function replaces the A with A_BAR and B with B_BAR
void replace_with_new_A_and_B(long double A[N+1][N+1], long double B[N+1][M+1], long double A_BAR[N+1][N+1], long double B_BAR[N+1][M+1], long double Pi[N+1], long double Pi_BAR[N+1]){
	// change the values of A and B
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			A[i][j] = A_BAR[i][j];
		}
	}

	// change the values of B
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			B[i][j] = B_BAR[i][j];
		}
	}

	// change the values of Pi
	for(int i=1; i<N+1; i++){
		Pi_BAR[i] = Pi[i];
	}
}

// making the matrices stochastic
void makestochastic(long double A[N+1][N+1], long double B[N+1][M+1]){
	for(int i=1; i<N+1; i++){
		long double sum_row = 0, max_row = -1e-30;
		// for each row
		int max_pos = -1;
		for(int j=1; j<=N; ++j){
			sum_row += A[i][j];
			if(max_row < A[i][j]){ max_row = A[i][j]; max_pos = j; }
		}
		A[i][max_pos] -= sum_row - 1;
	}

	for(int i=1; i<N+1; i++){
		long double row_sum = 0, cnt = 0;
		int row_max_index = 1;
		// for each row
		for(int j=1; j<M+1; j++){
			cnt += !B[i][j];
			B[i][j] = !B[i][j] ? 1e-30 : B[i][j];
			// find the maximum 
			row_sum += B[i][j];
			if(B[i][row_max_index] > B[i][j]){
				row_max_index = j;
			}
		}
		B[i][row_max_index] -= ((row_sum - (cnt * 1e-30)) - 1);
	}
	// check_for_stochastic_matrix(A, B);
	
}

// This function checks whether the passed matrix is stochastic or not
void check_for_stochastic_matrix(long double A[N+1][N+1], long double B[N+1][M+1]){
	// check row sum for 1
	for(int i=1; i<N+1; i++){
		long double sum = 0;
		for(int j=1; j<N+1; j++){
			sum += A[i][j];
		}
		if(sum != 1){
			printf("\nSum = %lf(A is invalid)", sum);
		}
		else{
			printf("\nSum = %lf(A is valid here)", sum);
		}
	}

	for(int i=1; i<N+1; i++){
		long double sum = 0;
		for(int j=1; j<M+1; j++){
			sum += B[i][j];
		}
		if(sum != 1){
			printf("\nSum = %lf(B is invalid)", sum);
		}
		else{
			printf("\nSum = %lf(B is valid here)", sum);
		}
	}
}

void initialize_bakis(long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1]){
	// Initializing pi
	Pi[1] = 1;
	for(int i=2; i<N+1; i++){
		Pi[i] = 0;
	}

	// Initializing A
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			A[i][j] = 0;
			if(i == j && j!=N){
				A[i][j] = 0.8;
			}
			if(i == j-1 && i!=N){
				A[i][j] = 0.2;
			}
		}
	}
	A[N][N] = 1;

	// Initializing B
	long double val = 1/(long double)M;
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			B[i][j] = val;
		}
	}
}

// This function will print the lambda to file
void print_lambda(long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1]){
	printf("\nConverged Lambda: \nA matrix:\n");
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			printf("%Le ", A[i][j]);
		}
		printf("\n");
	}

	printf("\nB matrix:\n");
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			printf("%Le ", B[i][j]);
		}
		printf("\n");
	}

	printf("\nPi matrix:\n");
	for(int i=1; i<N+1; i++){
		printf("%Le ", Pi[i]);
	}
}

// This function reads the lambda from the file to variables
void load_lambda(long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], char* A_file_paths_train, char* B_file_paths_train, char* Pi_file_paths_train){
	FILE* input_A = fopen(A_file_paths_train, "r");
	if(!input_A){
		printf("Cannot read file %s!\n", A_file_paths_train);
		exit(0);
	}
 
	FILE* input_B = fopen(B_file_paths_train, "r");
	if(!input_B){
		printf("Cannot read file %s!\n", B_file_paths_train);
		exit(0);
	}
 
	FILE *input_pi = fopen(Pi_file_paths_train, "r");
	if(!input_pi){
		printf("Cannot read file %s!\n", Pi_file_paths_train);
		exit(0);
	}
 
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			fscanf(input_A, "%lf", &A[i][j]);
		}
		for(int j=1; j<=M; ++j){
			fscanf(input_B, "%lf", &B[i][j]);
		}
		fscanf(input_pi, "%d", &Pi[i]);
	}
 
	//print_lambda();
	fclose(input_A);
	fclose(input_B);
	fclose(input_pi);
}

/*
// This function prints the lambda to file
void print_lambda_to_file(){
	FILE *output_A = fopen("output/A.txt", "w");
	if(!output_A){

	}
}
*/
