#include "basic.h"


/*
split a number vector using a vector
*/

void split_vector(int num){
	int count = 1;
	while(num>0){
		int tmp = (int)pow(10,count);
		int first = num / tmp ;
		if(first == 0) break;//key point, this should be the ending condition
		int second = num % tmp;
		print(to_string(first)+'-'+to_string(second));
		count++;
		//num /= tmp;
	}
}

int main(int argc,char* argv[]){
	/* ------ intput part ------*/
 	int x = atoi(argv[1]);
    //string str(argv[1]);
    //float num = atof(argv[1]);


	/*int x[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);*/
  
  	split_vector(x);
    return 0;
}