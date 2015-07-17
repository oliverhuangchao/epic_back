#include "basic.h"
#include <time.h>
 /*Seeds Number 
Find the seed of a number.  
Eg : 1716 = 143*1*4*3 =1716 so 143 is the seed of 1716. find all possible seedfor a given 
number. */


void findseed(int n){
	vector<int> res;
	for(int i=0;i<n;i++){
		vector<char> tmp = splitString(to_string(i));
		//print(tmp);
		int count = 1;
		for( char item:tmp){
			count *= (int)(item-48);
		}
		if(count*i == n)
			res.push_back(i);
		//if(count*i > n)
		//	break;
	}
	print(res);
}


int main(int argc,char* argv[]){
    int start = atoi(argv[1]);
    //string day(argv[1]);
   	//string weekday(argv[2]);
    //float actual = atof(argv[1]);	
	findseed(start);
    return 0;
}