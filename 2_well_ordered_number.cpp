/*
    well order string
    You knowa password is well-ordered string. Well-ordered string means that the order ofthe 
characters is in an alphabetical increasing order. Like “abEm” is awell-ordered number. However, 
“abmE” is not a well-order number. Given an input# that tells you also how many digits are in 
the password, print all possiblepasswords.
*/

#include "basic.h"

void dfs(vector<string> &result,string &path,int step,int N,int pos){
    if(step == N){
        result.push_back(path);
        return;
    }
    for(int i=pos;i<='z';i++){
        path.push_back(char(i));
        dfs(result,path,step+1,N,i+1);
        path.pop_back();
        path.push_back(char(i-32));
        dfs(result,path,step+1,N,i+1);
        path.pop_back();
    }
    return;
}


void get_well_order(int N){
    vector<string> result;
    string path;
    dfs(result,path,0,N,'a');
    print(result);
}


int main(int argc,char* argv[]){
    //string str = "hello//world/chaoh";
    //string str = "0123456789";
    //str.erase(str.begin()+1,str.begin()+5);
    int n = atoi((argv[1]));
    get_well_order(n);
}