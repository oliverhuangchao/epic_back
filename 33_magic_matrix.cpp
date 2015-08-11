#include "basic.h"

/*
	create a matrix matrix using number N

*/

void print_magic(int num){
	if(num % 2 == 0){
		print("input should be a odd number");
		return;
	}
	vector<vector<int>> matrix(num,vector<int>(num,0));
	int count = 1;
	int i = 0;
	int j = num/2;
	while(count <= num*num){
		matrix[i][j] = count++;
		int tmp_i = (i-1+num)%num;// key part
		int tmp_j = (j+1)%num;//key part
		if(matrix[tmp_i][tmp_j] != 0){
			tmp_i = (i+1)%num;
			tmp_j = j;
		}
		i = tmp_i;
		j = tmp_j;
	}
	print(matrix);
}

int main(int argc,char* argv[]){
    int s = atoi(argv[1]);
   /* string whole(argv[1]);
    string wrong(argv[2]);*/

	print_magic(s);
}