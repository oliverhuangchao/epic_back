#include "basic.h"
/*  Spiral Matrix 
Given aNXN matrix, starting from the upper right corner of the matrix start printingvalues in a 
counter-clockwise fashion.  
E.g.: Consider N = 4  
Matrix= {a, b, c, d,  
        e, f, g, h,  
        i, j, k, l, . visit 1point3acres.com for more. 
        m, n, o, p}  */

vector<int> sprialMatrix(vector<vector<int>> matrix){
    vector<int> res;
    while(!matrix.empty()){
        res.insert(res.end(),matrix[0].begin(),matrix[0].end());
        matrix.erase(matrix.begin());
        if(matrix.empty()) return res; //pay attention to this exception
        for(auto &each : matrix){
            res.push_back(each.back());
            each.pop_back();
        }
        if(matrix.empty()) return res;
        reverse(matrix.back().begin(),matrix.back().end());
        res.insert(res.end(),matrix.back().begin(),matrix.back().end());
        matrix.pop_back();
        if(matrix.empty()) return res;
        for(auto &each: matrix){
            res.push_back(each[0]);
            each.erase(each.begin());
        }
    }
    return res;
}


int main(int argc,char* argv[]){
    /*int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);*/
    int x[] = {1,2,3,8,9,4,7,6,5};
    vector<vector<int>> matrix = getMatrix(x,3,3);
    //vector<int> nums = getVector(x,9);
    print(sprialMatrix(matrix));
    /*priority_queue<int,vector<int>,less<int>> q;
    q.push(3);
    q.push(2);
    print(q.top());*/
    //sms();
}