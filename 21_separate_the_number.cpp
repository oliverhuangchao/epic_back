#include "basic.h"

/*
 Separate the number 
Print the sequences from the input given bythe user separated by semicolon  
e.g.: 4678912356012356  
output: 4;6789;123;56;0123;56;
*/

string seperate(string str){
	if(str.size()<2) return str;
	vector<string> z;
	int start=0;
	int end = 1;
	int value = (int)(str[start]);// - 48);
	while(end<str.size()){
		if(str[end] != value+1){
			z.push_back(str.substr(start,end-start));
			start = end;
		}
		value = (int)str[end];
		end++;
	}
	z.push_back(str.substr(start,end-start));
	return joinVector(z,';');
}






int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    string x(argv[1]);
    //float actual = atof(argv[1]);
    print(seperate(x));


   
}