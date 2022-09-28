#pragma once
#include "stdafx.h"
#include "constants.h"
#include <stdlib.h>
#include <string.h>

void calculate_xai(bool is_xai_prined, int x, long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], long double alpha[T+1][N+1], long double beta[T+1][N+1], long double xai[T+1][N+1][N+1]);
void calculate_gamma(bool is_gamma_printed, int x, long double alpha[T+1][N+1], long double beta[T+1][N+1], long double gamma[T+1][N+1]);
void print_gamma(long double gamma[T+1][N+1]);
void find_pibar(bool is_pi_bar_printed, int x, long double gamma[T+1][N+1], long double Pi_BAR[N+1]);
void find_abar(bool is_abar_printed, int x, long double A_BAR[N+1][N+1], long double xai[T+1][N+1][N+1], long double gamma[T+1][N+1]);
void print_a_bar(long double A_BAR[N+1][N+1]);
void find_bbar(bool is_bbar_prined, int x, long double B_BAR[N+1][M+1], long double xai[T+1][N+1][N+1], long double gamma[T+1][N+1], long int Observarion_sequence[TRAINING_SEQUENCES+1][T+1]);


void reestimation(long double A[N+1][N+1],
					long double B[N+1][M+1],
					long double Pi[N+1],
					long int Observation_sequence[TRAINING_SEQUENCES+1][T+1],
					long double alpha[T+1][N+1],
					long double beta[T+1][N+1],
					long double delta[N+1][T+1],
					long double psi[N+1][T+1],
					long double *P_star,
					int Q_star[T+1],
					long double xai[T+1][N+1][N+1],
					long double gamma[T+1][N+1],
					long double A_BAR[N+1][N+1],
					long double B_BAR[N+1][M+1],
					long double Pi_BAR[N+1], int x){
						calculate_xai(false, x, A, B, Pi, Observation_sequence, alpha, beta, xai);
						find_pibar(false, x, gamma, Pi);
						find_abar(false, x, A_BAR, xai, gamma);
						find_bbar(false, x, B_BAR, xai, gamma, Observation_sequence);
}

void calculate_xai(bool is_xai_prined, int seq, long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], long double alpha[T+1][N+1], long double beta[T+1][N+1], long double xai[T+1][N+1][N+1]){
	for(int t=1; t<T; t++){
		long double probability_of_given_lambda = 0;
		for(int i=1; i<N+1; i++){
			for(int j=1; j<N+1; j++){
				probability_of_given_lambda += (alpha[t][i] * A[i][j] * B[j][Observation_sequence[seq][t+1]] * beta[t+1][j]);
				// printf("\nprob: %g", probability_of_of_given_lambda);
			}
		}
		for(int i=1; i<N+1; i++){
			for(int j=1; j<N+1 ;j++){
				xai[t][i][j] = (alpha[t][i] * A[i][j] * B[j][Observation_sequence[seq][t+1]] * beta[t+1][j]) / probability_of_given_lambda;
				if(t==1 && is_xai_prined){
					printf("%g ", xai[t][i][j]);
				}
			}
			if(t==1 && is_xai_prined){
				printf("\n");
			}
		}
	}
}

// calculate the values of gamma
void calculate_gamma(bool is_gamma_printed, int seq, long double alpha[T+1][N+1], long double beta[T+1][N+1], long double gamma[T+1][N+1]){
	for(int t=1; t<T+1; t++){
		long double sum = 0;
		for(int i=1; i<N+1; i++){
			sum += (alpha[t][i] * beta[t][i]);
		}
		for(int i=1; i<N+1; i++){
			gamma[t][i] = (alpha[t][i] * beta[t][i]) / sum;
		}
	}

	if(is_gamma_printed){
		print_gamma(gamma);
	}
}

// This function prints the gamma value
void print_gamma(long double gamma[T+1][N+1]){
	printf("\nPrinting gamma:\n");
	for(int t=1; t<T+1; t++){
		for(int i=1; i<N+1; i++){
			printf("%g ",gamma[t][i]);
		}
		printf("\n");
	}
}

// This function finds the new values for pi
void find_pibar(bool is_pi_bar_printed, int x, long double gamma[T+1][N+1], long double Pi_BAR[N+1]){
	if(is_pi_bar_printed)
		printf("\nNew PI:\n");
	for(int i=1; i<N+1; i++){
		Pi_BAR[i] = (int)gamma[1][i];
		if(is_pi_bar_printed)
			printf("%g ", Pi_BAR[i]);
	}
	if(is_pi_bar_printed)
		printf("\n");
}

// This function finds the A bar
void find_abar(bool is_abar_printed, int x, long double A_BAR[N+1][N+1], long double xai[T+1][N+1][N+1], long double gamma[T+1][N+1]){
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			long double num = 0, den = 0;
			for(int t=1; t<=T-1; t++){
				num += xai[t][i][j];
				den += gamma[t][i];
			}
			A_BAR[i][j] = num/den;
		}
	}
	if(is_abar_printed){
		print_a_bar(A_BAR);
	}
}

// This function prints the A bar
void print_a_bar(long double A_BAR[N+1][N+1]){
	printf("\nA bar:\n");
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			printf("%g ", A_BAR[i][j]);
		}
		printf("\n");
	}
}

// This function finds the value of B bar
void find_bbar(bool is_bbar_prined, int seq, long double B_BAR[N+1][M+1], long double xai[T+1][N+1][N+1], long double gamma[T+1][N+1], long int Observarion_sequence[TRAINING_SEQUENCES+1][T+1]){
	if(is_bbar_prined)
			printf("\nB bar:\n");
	for(int j=1; j<N+1; j++){
		for(int k=1; k<M+1; k++){
			long double num = 0, den = 0;
			for(int t=1; t<T+1; t++){
				if(Observarion_sequence[seq][t] == k)
					num += gamma[t][j];
				den += gamma[t][j];
			}
			B_BAR[j][k] = num/den;
		}
	}

	/*
	// refine B_BAR
	for(int j=1;j<=N;j++){
		long double row_sum = 0;
		int max_index = 0;
		for(int k=1;k<=M;k++){
			if(B_BAR[j][k] == 0)
				B_BAR[j][k] = 1e-030;
			if(B_BAR[j][k] > B_BAR[j][max_index])
				max_index = k;
			row_sum += B_BAR[j][k];
		}
		B_BAR[j][max_index] -= (row_sum-1); 
	}

	for(int j=1;j<=N;j++){
		for(int k=1;k<=M;k++){
			if(is_bbar_prined)
				printf("%g ",B_BAR[j][k]);
		}
		if(is_bbar_prined)
			printf("\n");
	}
	*/
}