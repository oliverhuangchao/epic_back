#include "basic.h"
/*
  Security Keypad 
There is a security keypad at the entrance ofa building. It has 9 numbers 1 - 9 in a 3x3 
matrix format.  
1 2 3  
4 5 6  
7 8 9  
The security has decided to allow one digit error for a person but that digit should be 
horizontal or vertical. Example: for 5 the user is allowed to enter2, 4, 6, 8 or for 4 the user is 
allowed to enter 1, 5, 7. IF the security codeto enter is 1478 and if the user enters 1178 he 
should be allowed. Write afunction to take security code from the user and print out if he 
should beallowed or not.  
*/

bool iscorrect(string correct,string wrong){
	char x[] = {'1','2','3','4','5','6','7','8','9'};
	vector<vector<char>> matrix = getMatrix(x,3,3);
	vector<char> nums = getVector(x,9);
	unordered_map<char,unordered_set<char>> check;
	unordered_set<char> tmp;
	for(int i=0;i<matrix.size();i++){
		int j = 0;
		for(j;j<matrix[0].size();j++){
				if(j != matrix[0].size()-1)
					tmp.insert(matrix[i][j+1]);
				if(i != matrix.size()-1)
					tmp.insert(matrix[i+1][j]);
				if(j != 0)
					tmp.insert(matrix[i][j-1]);
				if(i != 0)
					tmp.insert(matrix[i-1][j]);
				check.insert({matrix[i][j],tmp});
				//print(tmp);
				tmp.clear();
		}
//		tmp.clear();
//		print(tmp);
	}
	print(matrix);
	//print(check);
	int count = 0;
	for(int i=0;i<correct.size();i++){
		if(wrong[i] != correct[i]){
			count ++;
			if(check[correct[i]].find(wrong[i]) == check[correct[i]].end())
				return false;
		}
		if(count == 2)
			return false;
	}
	return true;
}

int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    string x(argv[1]);
    string y(argv[2]);
    //float actual = atof(argv[1]);	
    print(iscorrect(x,y));
}