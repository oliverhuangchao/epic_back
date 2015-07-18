#include "basic.h"

/*
	leep day
*/

inline bool check_year(int year){
	if(year % 4 != 0) return false;
	else{
		if(year %200 == 0 && year % 1000 != 0) return false;
		return true;
	}
}

bool check(string date){
	vector<string> z = splitString(date,'/');
	int month = stoi(z[0]);
	int day = stoi(z[1]);
	int year = stoi(z[2]);
	if(month == 1){
		if(check_year(year)) print();
		else pring()
	}
	if(month == 2){
		if()
	}
	if(month != 2) return day <= 31;
	else{
		if(check_year(year)) return day <= 30;
		return day <= 29;
	}
}



int main(int argc,char* argv[]){
    int s = atoi(argv[1]);
   /* string whole(argv[1]);
    string wrong(argv[2]);*/
	print_magic(s);
}