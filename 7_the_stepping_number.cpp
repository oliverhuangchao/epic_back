#include "basic.h"
/*Thestepping number:  
A number is called as a stepping number if the adjacent digits are having adifference of 1. 
For eg. 8,343,545 are stepping numbers. While 890, 098 arenot. The difference between a 
‘9’ and ‘0’ should not be considered as1. Given start number(s) and an end number (e) your 
function should listout all the stepping numbers in the range including both the numbers s & 
e. */

void dfs(vector<string> &result,string &path, char last,int size,int step){
    if(step >= size)
        return;
    char current = path.back();
    if((current-1 == last || current+1 == last) && step < size){
        string tmp = path;
        tmp.push_back(last);
        result.push_back(tmp);
        //return;
        //pay attention: there is no return here
    }
    path.push_back(current+1);
    dfs(result,path,last,size,step+1);
    path.pop_back();
    path.push_back(current-1);
    dfs(result,path,last,size,step+1);
    path.pop_back();
    return;
}


void create_trapping_number(int s,int e,int size){
    vector<string> result;
    string path(to_string(s));
    dfs(result,path,(char)(e+48),size,1);
    print(result);
}


int main(int argc,char* argv[]){
    int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);
    create_trapping_number(s,e,size);
    







}