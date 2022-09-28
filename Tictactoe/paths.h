#pragma once
#include "constants.h"
#include <string.h>
#include <stdio.h>
#include "globals.h"
/*// paths to A matrix
char *A_1 = "inputs/A_1.txt";
char *A_7 = "inputs/A_7.txt";
char *A_8 = "inputs/A_8.txt";

// paths to B matrix
char *B_1 = "inputs/B_1.txt";
char *B_7 = "inputs/B_7.txt";
char *B_8 = "inputs/B_8.txt";

// paths to pi vector
char *Pi_1 = "inputs/PI_1.txt";
char *Pi_7 = "inputs/PI_7.txt";
char *Pi_8 = "inputs/PI_8.txt";

// paths to observation sequence
char *Observation_sequence_1 = "inputs/OBS_SEQ_1.txt";
char *Observation_sequence_7 = "inputs/OBS_SEQ_7.txt";
char *Observation_sequence_8 = "inputs/OBS_SEQ_8.txt";
*/

// This function generates the dynamic file paths for all files of digits 0 to 9
void generate_paths(){

	// generate dynamic paths
	for(int i=0; i<word_count; i++){

		// initialize the initial fine name
		char A_filename_train[60] = "Allfiles/train/lambda/A_";
		char B_filename_train[60] = "Allfiles/train/lambda/B_";
		char Pi_filename_train[60] = "Allfiles/train/lambda/Pi_";
		char OS_filename_train[60] = "Allfiles/train/Observations/OBS_SEQ_";
		char A_filename_test[60] = "Allfiles/test/lambda/A_";
		char B_filename_test[60] = "Allfiles/test/lambda/B_";
		char Pi_filename_test[60] = "Allfiles/test/lambda/Pi_";
		char OS_filename_test[60] = "Allfiles/test/Observations/OBS_SEQ_";
		char fileend[30] = ".txt";
		char middle[10] = "/";

		// generating path for A files
		// train files
		strcat(A_filename_train, words[i]);
		strcat(A_filename_train, fileend);
		strcat(A_file_paths_train[i], A_filename_train);
		// test files
		strcat(A_filename_test, words[i]);
		strcat(A_filename_test, fileend);
		strcat(A_file_paths_test[i], A_filename_test);
		
		// generating path for B files
		strcat(B_filename_train, words[i]);
		strcat(B_filename_train, fileend);
		strcat(B_file_paths_train[i], B_filename_train);
		strcat(B_filename_test, words[i]);
		strcat(B_filename_test, fileend);
		strcat(B_file_paths_test[i], B_filename_test);
		// printf("%s\n", B_file_paths[i]);

		// generating path for Pi files
		strcat(Pi_filename_train, words[i]);
		strcat(Pi_filename_train, fileend);
		strcat(Pi_file_paths_train[i], Pi_filename_train);
		strcat(Pi_filename_test, words[i]);
		strcat(Pi_filename_test, fileend);
		strcat(Pi_file_paths_test[i], Pi_filename_test);
		// printf("%s\n", Pi_file_paths[i]);

		// generating path for Observation sequence files
		strcat(OS_filename_train, words[i]);
		strcat(OS_filename_train, fileend);
		strcat(Observation_sequence_file_paths_train[i], OS_filename_train);
		strcat(OS_filename_test, words[i]);
		strcat(OS_filename_test, fileend);
		strcat(Observation_sequence_file_paths_test[i], OS_filename_test);
		// printf("%s\n", Observation_sequence_file_paths[i]);

		// generating the path for the training files
		for(int j=1; j<TRAINING_SEQUENCES+1; j++){
			char sample_train_filename[50] = "Allfiles/train/";
			char str[10];
			strcat(sample_train_filename, words[i]);
			strcat(sample_train_filename, middle);
			strcat(sample_train_filename, "obs_");
			strcat(sample_train_filename, itoa(j, str, 10));
			strcat(sample_train_filename, fileend);
			strcat(sample_files_train[i][j], sample_train_filename);
		}

		// generating the path for the testing files
		for(int j=1; j<TESTING_SEQUENCES+1; j++){
			char sample_test_filename[50] = "Allfiles/test/";
			char str[10];
			strcat(sample_test_filename, words[i]);
			strcat(sample_test_filename, middle);
			strcat(sample_test_filename, "obs_");
			strcat(sample_test_filename, itoa(j, str, 10));
			strcat(sample_test_filename, fileend);
			strcat(sample_files_test[i][j], sample_test_filename);
		}
	}
}

