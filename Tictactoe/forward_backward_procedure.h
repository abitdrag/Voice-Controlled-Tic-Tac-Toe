#pragma once
#include "stdafx.h"
#include "constants.h"

long double generate_alpha(bool is_print_alpha, bool is_print_prob_result, int x, long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], long double alpha[T+1][N+1]);
void print_probability(long double alpha[T+1][N+1]);
void generate_beta(bool is_print_beta, int x, long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int Observation_sequence[T+1], long double beta[T+1][N+1]);
void print_beta(long double beta[T+1][N+1]);
void print_alpha(long double alpha[T+1][N+1]);

// This function uses forward procedure to generate the matrix alpha
// INPUTS: If is_print_alpha is true then this funcion prints alpha matrix
//		   If is_print_probabiliy_result is true then this function prints the probability calculated using alpha
// OUTPUTS: Sets the values of alpha and returns the forward probability
long double generate_alpha(bool is_print_alpha, bool is_print_prob_result, int seq, long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], long double alpha[T+1][N+1]){
	print_A(A);
	print_B(B);
	print_Pi(Pi);
	// Initialization using Pi - initial probability
	for(int i=1; i<N+1; i++){
		alpha[1][i] = Pi[i] * B[i][Observation_sequence[seq][1]];
	}

	// Recursively finding ALPHA
	long double temp_sum = 0;
	for(int t=2; t<T+1; t++){
		for(int j=1; j<N+1; j++){
			temp_sum  = 0.0;
			for(int i=1; i<N+1; i++){
				temp_sum += (alpha[t-1][i] * A[i][j]);
			}
			alpha[t][j] = temp_sum * B[j][Observation_sequence[seq][t]];
		}
	}

	// check if alpha needs to be printed or not
	if(is_print_alpha){
		print_alpha(alpha);
	}

	// check if resulting probability using alpha needs to be printed
	if(is_print_prob_result){
		print_probability(alpha);
	}

	// return result
	// calculating probability
	long double prob=0;
	for(int i=1; i<N+1; i++){
		prob += alpha[T][i];
	}
	return prob;
}


// This function calculates and prints the probability of an observation sequence for given model using forward procedure
void print_probability(long double alpha[T+1][N+1]){
	// calculating probability
	long double temp_sum=0;
	for(int i=1; i<N+1; i++){
		temp_sum += alpha[T][i];
	}
	printf("\nP(O|lambda) = %Le\n", temp_sum);
}

// This function prints the alpha matrix
// This function prints beta matrix
void print_alpha(long double alpha[T+1][N+1]){
	printf("\nAlpha matrix:\n");
	for(int i=1;i<T+1;i++){
		for(int j=1;j<N+1;j++){
			printf("%Le\t", alpha[i][j]);
		}
		printf("\n");
	}
}

// This function uses backward procedure to calculate beta
// INPUT: if is_print_beta is true then this function will print beta matrix too
void generate_beta(bool is_print_beta, int seq, long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], long double beta[T+1][N+1]){
	// Initialization
	for(int i=1; i<N+1; i++){
		beta[T][i] = 1;
	}

	// Recrusviely calculating beta
	for(int t=T-1; t>=1; t--){
		for(int i=1; i<N+1; i++){
			long double temp_sum = 0;
			for(int j=1; j<N+1; j++){
				temp_sum += (A[i][j] * B[j][Observation_sequence[seq][t+1]] * beta[t+1][j]);
			}
			beta[t][i] = temp_sum;
		}
	}

	// check if result needs to be printed
	if(is_print_beta){
		print_beta(beta);
	}
}

// This function prints beta matrix
void print_beta(long double beta[T+1][N+1]){
	printf("\nBeta matrix:\n");
	for(int i=1;i<T+1;i++){
		for(int j=1;j<N+1;j++){
			printf("%g\t", beta[i][j]);
		}
		printf("\n");
	}
}