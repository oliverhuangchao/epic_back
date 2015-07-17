#include "basic.h"

/*
 Find Max/Min Number 
Take a series of integers as input till a zero is entered. Among these given integers, find the 
maximum of the odd numbers and the minimum of the even integers (not including zero) 
and print them. 
*/

void printMaxMin(){
	priority_queue<int> maxheap;
	priority_queue<int,vector<int>,greater<int>> minheap;
	while(1){
		int x;
		cin>>x;
		if(x == 0) break;
		if(x % 2 == 0)
			minheap.push(x);
		else
			maxheap.push(x);
	}
	print("max odd number is "+ to_string(maxheap.top()));
	print("min even number is "+ to_string(minheap.top()));
	return;

}

int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    //string x(argv[1]);
    //float actual = atof(argv[1]);
    printMaxMin();
}