#include "basic.h"

/*
Decimal Number 
Let the user enter a decimal number. Therange allowed is 0.0001 to 0.9999. Only four 
decimal places are allowed. Theoutput should be an irreducible fraction. E.g.: If the user 
enters 0.35,the irreducible fraction will be 7/20. 
*/

int find_common(int x,int y){
	if(x<y) return find_common(y,x);
	if(x % y == 0) return y;
	return find_common(y,x%y); 
}


void print_decimal(string x){
	vector<string> z = splitString(x,'.');
	int up = stoi(z[1]);

	int down = (int)pow(10,z[1].size());
	int common = find_common(up,down);
	print(up);
	print(down);
	up /= common;
	down /= common;

	print(common);
	print((float)up/(float)down);
	print(to_string(up)+'/'+to_string(down));
}



int main(int argc,char* argv[]){
	/* ------ intput part ------*/
// 	int x = atoi(argv[1]);
    string str(argv[1]);
    //float num = atof(argv[1]);


	//int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	//int len = sizeof(x)/sizeof(x[0]);
	//vector<int> nums = getVector(x,len);
    print(find_common(100,35));
   	print_decimal(str);
    return 0;
}