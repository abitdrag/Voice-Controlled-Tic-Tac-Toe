// This function stores the values entered by user
char square_values[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int player = 1;


// This function returns 0 when game is over and there is no result
// This function returns 1 when game is over with result
// This function returns -1 when game is still in progress
int check_winner(){
	if (square_values[1] == square_values[2] && square_values[2] == square_values[3])
        return 1;
        
    else if (square_values[4] == square_values[5] && square_values[5] == square_values[6])
        return 1;
        
    else if (square_values[7] == square_values[8] && square_values[8] == square_values[9])
        return 1;
        
    else if (square_values[1] == square_values[4] && square_values[4] == square_values[7])
        return 1;
        
    else if (square_values[2] == square_values[5] && square_values[5] == square_values[8])
        return 1;
        
    else if (square_values[3] == square_values[6] && square_values[6] == square_values[9])
        return 1;
        
    else if (square_values[1] == square_values[5] && square_values[5] == square_values[9])
        return 1;
        
    else if (square_values[3] == square_values[5] && square_values[5] == square_values[7])
        return 1;
        
    else if (square_values[1] != '1' && square_values[2] != '2' && square_values[3] != '3' &&
        square_values[4] != '4' && square_values[5] != '5' && square_values[6] != '6' && square_values[7] 
        != '7' && square_values[8] != '8' && square_values[9] != '9')
        return 0;
    else
        return  - 1;
};

// This function returns 1 if the mark is correct and board is to be updated
// This function returns 0 if the mark is incorrect
int mark_on_game(int position){
	char mark = (player == 1) ? 'X' : 'O';
	if(position == 1 && square_values[1] == '1'){
		square_values[1] = mark;
	}
	else if(position == 2 && square_values[2] == '2'){
		square_values[2] = mark;
	}
	else if(position == 3 && square_values[3] == '3'){
		square_values[3] = mark;
	}
	else if(position == 4 && square_values[4] == '4'){
		square_values[4] = mark;
	}
	else if(position == 5 && square_values[5] == '5'){
		square_values[5] = mark;
	}
	else if(position == 6 && square_values[6] == '6'){
		square_values[6] = mark;
	}
	else if(position == 7 && square_values[7] == '7'){
		square_values[7] = mark;
	}
	else if(position == 8 && square_values[8] == '8'){
		square_values[8] = mark;
	}
	else if(position == 9 && square_values[9] == '9'){
		square_values[9] = mark;
	}
	else{
		// invalid move
		return 0;
	}
	// valid move
	// change the player
	if(player == 1){
		player = 2;
	}
	else{
		player = 1;
	}
	return 1;
};


// This function resets the game
void reset_game(){
	square_values[0] = 'o';
	square_values[1] = '1';
	square_values[2] = '2';
	square_values[3] = '3';
	square_values[4] = '4';
	square_values[5] = '5';
	square_values[6] = '6';
	square_values[7] = '7';
	square_values[8] = '8';
	square_values[9] = '9';
	player = 1;
};