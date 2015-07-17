#include "basic.h"
/*
 Jump Chess 
There’sa N*N board, two players join the jump game. The chess could go vertically 
andhorizontally. If the adjacent chess is opponent player’s and the spot besidethat is empty, then 
the chess could jump to that spot. One chess could not beenjumped twice. Given the position of 
the spot on the board, write the program tocount the longest length that chess could go. 

*/
//similar to find max point

void dfs(vector<vector<char>> &matrix,int &maxvalue,int step,int i,int j,char target){
	//four direction
	matrix[i][j] == 'x';
	dfs(matrix,maxvlue,step+1,i+1,j+1,target);
	matrix[i][j] == target;
}

int main(int argc,char* argv[]){
	/* ------ intput part ------*/
 	//int x = atoi(argv[1]);
    string str(argv[1]);
    //float num = atof(argv[1]);


	//int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	//int len = sizeof(x)/sizeof(x[0]);
	//vector<int> nums = getVector(x,len);
  
  //print(check_equation(str));
    print_equation(str);
    return 0;
}