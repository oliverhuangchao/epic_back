#include "basic.h"
#include <time.h>
/*
  Continuous Alphabets 
Printcontinuous alphabets from a sequence of arbitrary alphabets  
For example:  
Input: abcdefljdflsjflmnopflsjflasjftuvwxyz  
Output: abcdef; mnop; tuvwxyz 
Input: AbcDefljdflsjflmnopflsjflasjftuvWxYz  
Output: abcdef; mnop; tuvwxyz 
*/

string print_string(string& str){
	if(str.size()<2) return str;
	int a = 0;
	int b = 1;
	char c = str[a];
	vector<string> z;
	while(b<str.size()){
		if(str[b] != c+1){
			z.push_back(str.substr(a,b-a));
			a = b;
		}
		c = str[b++];
	}
	//do not forget to put the last string
	z.push_back(str.substr(a,b-a));
	return joinVector(z,';');
}
int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    string str(argv[1]);
   	//string weekday(argv[2]);
    //float actual = atof(argv[1]);	
    print(print_string(str));
    return 0;
}