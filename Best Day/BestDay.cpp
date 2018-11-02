#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream scan;
	int sales[7];
	int max=0;
	int maxIn=0;
	string days[7] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
	int loops;
	
	scan.open("bestday.dat");
	//scan.open("/home/brandon/Downloads/UILCS2013_RegProg/JudgeData/bestday.dat");
	if(!scan.is_open()) { 
		cout << "Could not open file." << endl;
		return 1;
	}
	
	scan >> loops;
	for (int i = 0; i < loops; i++){
		for (int j = 0; j < 7; j++){
			scan >> sales[j];
			if(sales[j] > max){
				max = sales[j];
				maxIn = j;
			}
		}
		cout << days[maxIn] << endl;
		max = 0;
		maxIn = 0;
	}
	scan.close();
	return 0;
}
