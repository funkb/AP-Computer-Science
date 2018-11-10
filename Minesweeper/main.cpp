#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int GRID_SIZE = 5;
const int MINES = 2;
bool running = true;

void print_menu(int& input);
void fill_map(char (&arr)[GRID_SIZE][GRID_SIZE], char fill);
void populate(char (&arr)[GRID_SIZE][GRID_SIZE]);
void place_mine(char (&arr)[GRID_SIZE][GRID_SIZE]);
void print_array(char (&arr)[GRID_SIZE][GRID_SIZE]);
void generate_adjacent(char (&arr)[GRID_SIZE][GRID_SIZE]);
int get_surr(char (&arr)[GRID_SIZE][GRID_SIZE], int x, int y);
void reveal_square(char (&arr_vis)[GRID_SIZE][GRID_SIZE], char (&arr_guide)[GRID_SIZE][GRID_SIZE]);
bool place_flag(char (&arr_vis)[GRID_SIZE][GRID_SIZE], char(&arr_guide)[GRID_SIZE][GRID_SIZE]);
bool in_grid(int x, int y);
void get_path(char (&arr_guide)[GRID_SIZE][GRID_SIZE], char(&arr_vis)[GRID_SIZE][GRID_SIZE], int x, int y);
void remove_flag(char (&arr_vis)[GRID_SIZE][GRID_SIZE]);

int main(){
	srand(time(NULL));
	rand();
	
	char map_visable[GRID_SIZE][GRID_SIZE];
	char map_guide[GRID_SIZE][GRID_SIZE];
	
	fill_map(map_visable, '#');
	fill_map(map_guide, '.');
	populate(map_guide);
	
	while (running){
		system("CLS");
		int option=0;
		print_array(map_visable);
		print_menu(option);
		if(!(option==1 || option==2 || option==3)){
			cout << "Not a valid option!" << endl;
			continue;
		}else{
			switch(option){
				case 1:
					reveal_square(map_visable, map_guide);
					break;
				case 2:
					if(place_flag(map_visable,map_guide)) return 0;
					break;
				case 3:
					remove_flag(map_visable);
					break;
				case 4:
					cout << "Thanks for playing!" << endl; 
					running=false;
					break;
				default:
					cout << "Something went wrong!" << endl;
					running=false;
					break;
			}
			
		}

	}
	
	return 0;
	
}

void print_menu(int& input){
	cout << "====================" << endl;
	cout << "1. Reveal Square\n2. Place Flag\n3. Remove Flag\n4. Quit" << endl;
	cout << "====================" << endl;
	cout << ">";
	cin >> input;
}

void fill_map(char (&arr)[GRID_SIZE][GRID_SIZE], char fill){
	for(int i = 0; i < GRID_SIZE; i++){
		for (int j = 0; j < GRID_SIZE; j++){
			arr[i][j] = fill;
		}
	}
}

void populate(char (&arr)[GRID_SIZE][GRID_SIZE]){
	int count = MINES;
	while (count > 0){
		place_mine(arr);
		count--;
	}
	generate_adjacent(arr);
}

void place_mine(char (&arr)[GRID_SIZE][GRID_SIZE]){
	int x = rand() % GRID_SIZE;
	int y = rand() % GRID_SIZE;
	if (arr[x][y] == '@'){
		place_mine(arr);
	}else{
		arr[x][y] = '@';
	}
}

void print_array(char (&arr)[GRID_SIZE][GRID_SIZE]){
	for(int i = 0; i < GRID_SIZE; i++){
		for (int j = 0; j < GRID_SIZE; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void generate_adjacent(char (&arr)[GRID_SIZE][GRID_SIZE]){
	for(int i = 0; i < GRID_SIZE; i++){
		for (int j = 0; j < GRID_SIZE; j++){
			if(!(arr[i][j] == '@'))
				arr[i][j] = '0' + get_surr(arr, i,j);
				if(arr[i][j] == '0') {
					arr[i][j] = '.';
				}
		}
	}
}

int get_surr(char (&arr)[GRID_SIZE][GRID_SIZE],int x, int y){
	int count = 0;
	for(int i=x-1; i <= x+1; i++){
		for(int j = y-1; j <= y+1; j++){
			if( in_grid(i,j) && arr[i][j] == '@'){
				count++;
			}
		}
	}
	return count;
}

bool in_grid(int x, int y){
	return (x>=0 && x<GRID_SIZE && y>=0 && y<GRID_SIZE);
}

void reveal_square(char (&arr_vis)[GRID_SIZE][GRID_SIZE], char (&arr_guide)[GRID_SIZE][GRID_SIZE]){
	int x,y;
	cout << "Which square would you like to reveal? (1-10) (x y)> ";
	cin >> y >> x;
	x-=1;
	y-=1;
	if(in_grid(x,y)){
		arr_vis[x][y] = arr_guide[x][y];
		if(arr_vis[x][y] == '.'){
			get_path(arr_guide, arr_vis, x,y);
		}
		if(arr_vis[x][y] == '@'){
			print_array(arr_vis);
			cout << "\nYou Lose!" << endl;
			running=false;
		}
	}else{
		cout << "That point does not exist!" << endl;
	}
}

void get_path(char (&arr_guide)[GRID_SIZE][GRID_SIZE], char(&arr_vis)[GRID_SIZE][GRID_SIZE], int x, int y){

	if(in_grid(x-1, y) && arr_guide[x-1][y] == '.' && arr_vis[x-1][y] != '.'){
		arr_vis[x-1][y] = '.';
		get_path(arr_guide,arr_vis,x-1,y);
	} 
	if(in_grid(x+1, y) && arr_guide[x+1][y] == '.'  && arr_vis[x+1][y] != '.'){
		arr_vis[x+1][y] = '.';
		get_path(arr_guide,arr_vis,x+1,y);
	} 
	if(in_grid(x, y-1) && arr_guide[x][y-1] == '.'  && arr_vis[x][y-1] != '.'){
		arr_vis[x][y-1] = '.';
		get_path(arr_guide,arr_vis,x,y-1);
	} 
	if(in_grid(x, y+1) && arr_guide[x][y+1] == '.' && arr_vis[x][y+1] != '.'){
		arr_vis[x][y+1] = '.';
		get_path(arr_guide,arr_vis,x,y+1);
	}
	
}

bool place_flag(char (&arr_vis)[GRID_SIZE][GRID_SIZE], char(&arr_guide)[GRID_SIZE][GRID_SIZE]){
	int x,y;
	int count = 0;
	cout << "Which square would you like to reveal? (1-10) (x y)> ";
	cin >> y >> x;
	x-=1;
	y-=1;
	if(in_grid(x,y)){
		arr_vis[x][y] = 'F';
		for(int i = 0; i < GRID_SIZE; i++){
			for(int j = 0; j < GRID_SIZE; j++){
				if(arr_vis[i][j] == 'F' && arr_guide[i][j] == '@')
					count++;
			}
		}
		if (count == MINES){
			system("CLS");
			cout << "You Win!" << endl;
			return true;
		}
		
	}else{
		cout << "That point does not exist!" << endl;
	}
	return false;
}

void remove_flag(char (&arr_vis)[GRID_SIZE][GRID_SIZE]){
	int x,y;
	cout << "Which square would you like to reveal? (1-10) (x y)> ";
	cin >> y >> x;
	x-=1;
	y-=1;
	if(in_grid(x,y) && arr_vis[x][y] == 'F'){
		arr_vis[x][y] == '#';
	}else{
		cout << "That is not a flag!" << endl;
	}
}

