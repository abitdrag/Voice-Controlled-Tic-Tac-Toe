#pragma once
#include "stdafx.h"
#include "constants.h"

void read_codebook(bool is_codebook_printed, char *filename, long double codebook[M+1][p+1]){
	FILE *codebook_file = fopen(filename, "r");
	if(!codebook_file){
		printf("Cannot open the file!\n");
		return;
	}
 
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= p; ++j)
			fscanf(codebook_file,"%lf", &codebook[i][j]);
	fclose(codebook_file);
	
	if(is_codebook_printed){
		printf("\n-----------CODEBOOK-----------\n");
		for(int i=1; i<M+1; ++i){
			for(int j=1; j<p+1; ++j){
				printf("%g ", codebook[i][j]);
			}
			printf("\n");
		}
	}
}