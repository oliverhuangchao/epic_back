#include "basic.h"
#include <time.h>
 /*
 Tic Tac Toe 
N*N matrix is given with input red or black.You can move horizontally, vertically or 
diagonally. If 3 consecutive samecolor found, that color will get 1 point. So if 4 red are 
vertically then pointis 2. Find the winner. 
 */

void dfs(vector<vector<char>> &matrix,int i, int j,int &score,char value){
	int rows = matrix.size();
	int cols = matrix[0].size();
	if(j != cols-1 && matrix[i][j+1] == value){
		matrix[i][j+1] = 'x';
		dfs(matrix,i,j+1,++score,value);
	}
	if(j != cols-1 && i!= rows-1 && matrix[i+1][j+1] == value){
		matrix[i+1][j+1] = 'x';
		dfs(matrix,i+1,j+1,++score,value);
	}
	if(i!= rows-1 && matrix[i+1][j] == value){
		matrix[i+1][j] = 'x';
		dfs(matrix,i+1,j,++score,value);
	}
	if(i!= rows-1 && j!= 0 && matrix[i+1][j-1] == value){
		matrix[i+1][j-1] = 'x';
		dfs(matrix,i+1,j-1,++score,value);
	}
	if(j!=0 && matrix[i][j-1] == value){
		matrix[i][j-1] = 'x';
		dfs(matrix,i,j-1,++score,value);
	}
	if(i!=0 && j!=0 && matrix[i-1][j-1] == value){
		matrix[i-1][j-1] = 'x';
		dfs(matrix,i-1,j-1,++score,value);
	}
	if(i!= 0 && matrix[i-1][j] == value){
		matrix[i-1][j] = 'x';
		dfs(matrix,i-1,j,++score,value);
	}
	if(i!= 0 && j!=cols-1 && matrix[i-1][j+1] == value){
		matrix[i-1][j+1] = 'x';
		dfs(matrix,i-1,j+1,++score,value);
	}
}



void getValue(){
	char x[] = {'r','r','b','b','b','b','b','r','b','b','r','r','r','b','b'};
	vector<vector<char>> matrix = getMatrix(x,3,5);
	print(matrix);
	int red_count = 0;
	int black_count = 0;
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++){
			if(matrix[i][j] == 'r'){
				matrix[i][j] = 'x';// key point: we need to change the current position also!!
				int score = -1;
				dfs(matrix,i,j,score,'r');
				if(score > 0)
					red_count += score;
			}
			if(matrix[i][j] == 'b'){
				int score = -1;
				matrix[i][j] = 'x';
				dfs(matrix,i,j,score,'b');
				if(score > 0)
					black_count += score;
			}
		}
	}
	print(black_count);
	print(red_count);
	if(black_count > red_count)
		print("black wins");
	else
		print("red wins");

}





int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    //string day(argv[1]);
   	//string weekday(argv[2]);
    //float actual = atof(argv[1]);	
    getValue();
    return 0;
}