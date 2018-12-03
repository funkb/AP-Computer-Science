#include <iostream>
#include "baf0125HW4func.h"

using namespace std;

int main(){
	const int SIZE = 7;
	int **board;
	board = new int *[SIZE];
	for(int i = 0; i < SIZE; i++)
		board[i] = new int[SIZE];
	
	cout << "+----------------------------------------------+" << endl;
    cout << "|       Computer Science and Engineering       |" << endl;
    cout << "|       CSCE 1030 - Computer Science I         |" << endl;
    cout << "|  Brandon Funk  BAF0125  baf0125@my.unt.edu   |" << endl;
    cout << "+----------------------------------------------+" << endl;
    
    populate_board(board, SIZE);
	
	print_intro();
	bool quit = false;
	int option;
	while(!quit){
		print_board(board, SIZE);
		while (true){
			cout << "Please choose a lane: 1 - 7 or type -1 to quit: ";
			cin >> option;
			if(option == -1){
				cout << "Thanks for playing!";
				quit = true;
				break;
			}else if(option <= 7 && option >= 1){
				play_lane_player(option, board);
				break;
			}else{
				cout << "That is not a valid lane!" << endl;
			}
		}
	}
	
	return 0;
}
