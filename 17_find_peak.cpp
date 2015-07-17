#include "basic.h"

/*
Mountain Point 
Given a M * N matrix, if the element in thematrix is larger than other 8 elements who stay 
around it, then named thatelement be mountain point. Print all the mountain points. 
*/

bool checkPeak(vector<vector<int>> &matrix,int i,int j){
    int value = matrix[i][j];
    int x[] = {-1,-1,-1,0,0,0,1,1,1};
    int y[] = {-1,0,1,-1,0,1,-1,0,1};
    for(int k=0;k<8;k++){
        if(value < matrix[i+x[k]][j+y[k]])
            return false;
    }
    return true;
}


void find_Peak(){
    int x[] = {7, 3, 2, 6, 8, -9, 1, 1, -1, 2, 1, 5, 0, 1, 9};
    vector<vector<int>> matrix = getMatrix(x,3,5);
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> neg(cols,INT_MIN);
    matrix.insert(matrix.begin(),neg);
    matrix.push_back(neg);
    for(int i=0;i<matrix.size();i++){
        matrix[i].insert(matrix[i].begin(),INT_MIN);
        matrix[i].push_back(INT_MIN);
    }
    print(matrix);
    vector<int> res;

    for(int i=1;i<=rows;i++){//pay attention to the '=' simbol
        for(int j=1;j<=cols;j++){
            if(checkPeak(matrix,i,j))
                res.push_back(matrix[i][j]);
        }
    }
    print(res);
    return;
}

int main(int argc,char* argv[]){
    /*int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);*/
   /* string whole(argv[1]);
    string wrong(argv[2]);*/

    //findmax();
    find_Peak();
}