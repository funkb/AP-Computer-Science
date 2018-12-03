#ifndef FUNC_H
#define FUNC_H
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
char get_symbol(int num);
void populate_board(int** board, int size);
void print_board(int** board, int size);
void print_intro();
void play_lane_player(int lane, int** board);
void play_lane_comp(int** board);

#endif
