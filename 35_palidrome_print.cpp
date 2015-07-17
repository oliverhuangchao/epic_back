#include "basic.h"

 /*Palindromes 
Print all palindromes of size greater than orequal to 3 of a given string. (How to do it with 
DP)? */

	
void print_palidrome(string str){
	int size = str.size();
	vector<vector<bool>> check(size, vector<bool>(size,false));
	for(int i=size-1;i>=0;i--){
	     for(int j=i;j<size;j++){
	          //if(i == j) check[i][j] = true;
	          //if(j-i == 1) check[i][j] = str[i] == str[j];
	         check[i][j] = (str[i] == str[j]) && (i == j || check[i+1][j-1] );
	     }
	}

	print(check);
	vector<string> res;

	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			if(check[i][j] && j-i>=2)
				res.push_back(str.substr(i,j-i+1));
		}
	}

	print(res);
}


int main(int argc,char* argv[]){
	/* ------ intput part ------*/
    //int start = atoi(argv[1]);
    string str(argv[1]);
   	//string weekday(argv[2]);
    //float num = atof(argv[1]);	
	//int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	//int len = sizeof(x)/sizeof(x[0]);
	//vector<int> nums = getVector(x,len);
    


	print_palidrome(str);
    return 0;
}