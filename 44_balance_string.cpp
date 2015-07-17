#include "basic.h"
#include <time.h>
/*
Balanced String 
Given a string that has{},[],() and characters.Check if the string is balanced. E.g. {a[(b)]} is 
balanced. {a[(b])} isunbalanced. 
*/

bool isBalance(string str){
	stack<char> z;
	for(char item : str){
		if(item == '(' || item == '{' || item == '[')
			z.push(item);
		if(item == ')'){
			if(z.empty() || z.top() != '(') return false;
			else z.pop();
		}
		if(item == ']'){
			if(z.empty() || z.top() != '[') return false;
			else z.pop();
		}
		if(item == '}'){
			if(z.empty() || z.top() != '{') return false;
			else z.pop();
		}
	}
	return z.empty();
}



int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    string str(argv[1]);
   	//string weekday(argv[2]);
    //float actual = atof(argv[1]);	
    print(isBalance(str));
    return 0;
}