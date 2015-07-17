#include "basic.h"
/*
A number is called 'desirable' if all thedigits are strictly ascending eg: 159 as 1<5<9. You 
know that your rivalhas a strictly numeric password that is 'desirable'. Your close ally has 
given you the number of digits (N) in your rival's password. WAP th\hjtat takes in'N' as input 
and prints out all possible 'desirable' numbers that can be formed with N digits. 
*/

void dfs(vector<string> &result, string &path,int step, const int &N, int pos){
    if(step == N){
        result.push_back(path);
        return;
    }
    for(int i=pos;i<10;i++){
        path.push_back((char)(i+48));
        dfs(result,path,step+1,N,i+1);
        path.pop_back();
    }
    return;
}


void get_desirable(int N){
    vector<string> result;
    string path;
    dfs(result,path,0,N,0);
    print(result);
    print(result.size());
}


int main(int argc,char* argv[]){
    int n = atoi((argv[1]));
    get_desirable(n);
}