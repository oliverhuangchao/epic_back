#include "basic.h"

/*
 Matrix Position 
Given an NxN matrix with unique integers :Find and print positions of all numbers such that 
it is the biggest in its row and also the smallest in its column . e.g. : In 3 x 3 with elements  
1 2 3  
4 5 6  
7 8 9 
the number is 3 and position (1,3)  
*/

// there should be only one answer
int printall(){
	int x[] = {1,2,3,4,5,6,7,8,9};
	vector<vector<int>> matrix = getMatrix(x,3,3);
	print(matrix);
	unordered_set<string> z;
	for(int i=0;i<matrix.size();i++){
		int tmp = INT_MIN;
		int col = -1;
		int j=0;
		for(j;j<matrix[0].size();j++){
			if(tmp < matrix[i][j]);{
				col = j;
				tmp = matrix[i][j];
			}
		}
		z.insert(to_string(i)+"-"+to_string(col));
	}
	print(z);

	for(int j=0;j<matrix[0].size();j++){
		int tmp = INT_MAX;
		int col = -1;
		//int i=0;
		for(int i=0;i<matrix.size();i++){
			if(tmp > matrix[i][j]){
				col = i;
				tmp = matrix[i][j];
			}
		}
		string check = to_string(col)+"-"+to_string(j);
		if(z.find(check) != z.end())
			return matrix[col][j];
	}
	return -1;
}

int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    //string x(argv[1]);
    //float actual = atof(argv[1]);
    print(printall());

}