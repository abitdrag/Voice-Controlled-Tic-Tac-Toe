#pragma once
#include "stdafx.h"
#include "constants.h"

void viterbi_algorithm(bool is_print_result, int seq, long double A[N+1][N+1], long double B[N+1][M+1], long double Pi[N+1], long int Observation_sequence[TRAINING_SEQUENCES+1][T+1], long double delta[N+1][T+1], long double psi[N+1][T+1], int Q_star[T+1], long double *p_star){
	// Initialization
	for(int i=1; i<N+1; i++){
		delta[i][1] = Pi[i] * B[i][Observation_sequence[seq][1]];
		psi[i][1] = 0;
	}

	long double max=0;
	int index=0;
	// Iteration
	for(int t=2; t<T+1; t++){
		for(int j=1; j<N+1; j++){
			// set the initial values
			max = 0;
			for(int i=1; i<N+1; i++){
				if((delta[i][t-1] * A[i][j]) > max){
					// change the index for max value
					max = delta[i][t-1] * A[i][j];
					index = i;
				}
			}
			// set the results
			delta[j][t] = max * B[j][Observation_sequence[seq][t]];
			psi[j][t] = index;

		}
	}

	// Terminating
	long double p_s = 0;
	for(int i=1; i<N+1; i++){
		// compare with max to get max
		if(delta[i][T] > p_s){
			p_s = delta[i][T];
			Q_star[T] = i;
		}
	}
	// set p*
	*p_star = p_s;

	// finding state sequence
	for(int t=T-1; t>0; t--){
		Q_star[t] = psi[Q_star[t+1]][t+1];
	}

	// checking print result condition
	if(is_print_result){
		printf("P_star = %g\n", *p_star);
		printf("Q_star:\n");
		for(int i=1; i<T+1; i++){
			printf("%d ", Q_star[i]);
		}
	}
}