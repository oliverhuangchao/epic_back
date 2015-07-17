#include "basic.h"
#include <time.h>
/*
Substring Addition 
Write a program to add the substring. eg :say you have alist {1 7 6 3 5 8 9 } and user is 
entering a sum 16. Output should display(2-4) that is {7 6 3} cause 7+6+3=16. 
*/

void print_string(){
	int x[] = {1,7,6,3,5,8,9};
	int len=sizeof(x)/sizeof(x[0]);
	print(x,len);
	//vector<int> nums = getVector(x,7);
	vector<int> z(len,x[0]);
	unordered_map<int,int> check;
	check.insert({x[0],0});
	int target = 16;
	for(int i=1;i<len;i++){
		z[i] = z[i-1]+x[i];
		check.insert({z[i],i});
	}
	print(z);
	for(int i=0;i<len;i++){
		if(check.find(target+z[i]) != check.end()){
			print(to_string(i+2) + " - " + to_string(check[target+z[i]]+1));
			//key point: pay attention to the index number
			return;
		}
	}
	print("not find");

}
int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    //string str(argv[1]);
   	//string weekday(argv[2]);
    //float actual = atof(argv[1]);	

	print_string();
    return 0;
}