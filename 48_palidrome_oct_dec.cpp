#include "basic.h"

inline bool check_palidrome(string str){
	int a = 0;
	int b = str.size()-1;
	while(a<b){
		if(str[a] != str[b])
			return false;
		a++;
		b--;
	}
	return true;
}


inline bool check_both(int num){
	//print(num);
	//print(dec2oct(num));
	return check_palidrome(to_string(num)) && check_palidrome(to_string(dec2oct(num)));
}


int main(int argc,char* argv[]){
	/* ------ intput part ------*/
 	int x = atoi(argv[1]);
    //string str(argv[1]);
    //float num = atof(argv[1]);


	//int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	//int len = sizeof(x)/sizeof(x[0]);
	//vector<int> nums = getVector(x,len);
  	for(int i=0;i<x;i++)
  		if(check_both(i)) print(i);

    return 0;
}