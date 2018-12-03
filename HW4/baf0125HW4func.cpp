#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

enum Color {RED, BLUE};
enum Type {CROSS, HORIZONTAL, VERTICAL, LOCKED, EMPTY};

struct Tile{
	Color color;
	Type type;
	int lane;
};

char get_symbol(int num){
	switch (num){
		case (0):
			return '+';
		case (1):
			return '-';
		case (2):
			return '|';
		case (3):
			return 'X';
		case (4):
			return ' ';
		default:
			return '@';
	}
}


void populate_board(int** board, int size){
	
	char file_name[256];
	cout << "Name of file >";
	cin.getline(file_name,256);
	
	ifstream file;
	
	file.open(file_name);
	
	if(!file.is_open()){
		cout << "Could not get file!" << endl;
		return;
	}
	
	int row = 0;
	int col = 0;
	while(!file.eof()){
		char temp = file.get();
		switch(temp){
			case ('X'):
				board[row][col] = LOCKED;
				col++;
				break;
			case (' '):
				board[row][col] = EMPTY;
				col++;
				break;
			case ('\n'):
				row++;
				col=0;
				break;
		}
	}
}

void print_board(int** board, int size){
	cout << "   1 2 3 4 5 6 7" << endl;
	cout << "  ***************" << endl;
	for(int i = 0; i < size; i++){
		cout << i+1 << " *";
		for(int j = 0; j < size-1; j++){
			cout << get_symbol(board[i][j]) << " ";
		}
		cout << get_symbol(board[i][size-1]) << "*" << endl;
	}
	cout << "  ***************" << endl;
}

void print_intro(){
	cout << "********************The aMAZEing Labyrinth********************" << endl << endl << "                           Rules" << endl << endl;
	cout << "The aMAZEing Labyrinth is a two player game in which players take turns sliding tiles, marked with |, -, or +, into lanes from their side of the board. The goal is to have at least one lane that has a straight, connected path from one player's side of the board to the opposite side. This game is as much about offense as it is defense, as you will have to try to extend your path while blocking your opponent's progress." << endl << "                         Good Luck!" << endl << "**************************************************************" << endl;
}

void play_lane_player(int lane, int** board){
	char option;
	cout << "Please choose a tile to add: -, |, or +: ";
	cin >> option;
	if(option == '-' || option == '|' || option == '+'){
		if()
	}
}

void play_lane_comp(int** board){
	
}

