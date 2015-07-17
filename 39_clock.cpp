#include "basic.h"
#include <time.h>
/*
Clock Angle 
We are given a specific time(like 02:23), weneed to get the angle between hour and 
minute(less than 180) 
*/

int show_angle(string str){
	vector<string> z = splitString(str,':');
	int hour = stoi(z[0]);
	int minute = stoi(z[1]);
	int minute_angle = minute*6;
	int hour_angle = hour*30+(int)(minute*0.5);
	int res = abs(minute_angle-hour_angle);
	print(hour_angle);
	print(minute_angle);
	if(res > 180)
		return 360-res;
	else
		return res;
}



int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    string str(argv[1]);
   	//string weekday(argv[2]);
    //float actual = atof(argv[1]);	
    print(show_angle(str));
    return 0;
}