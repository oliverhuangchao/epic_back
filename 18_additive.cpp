#include "basic.h"

/*
 Additive Number 
Anadditive sequence is 1,2,3,5,8,13 where T(n) = T(n -1) + T(n - 2). A numberrange is given to 
you. Find the additive sequence number in that range. 
Given the start and an ending integer as user input, generate all integers with the following 
property. 
*/
// almost o(N2) solution
vector<int> create(int start,int end){
    vector<int> res;
    res.push_back(start);
    for(int i=start+1;i<end;i++){
        res.push_back(i);
        while(res.back()<end){
            int tmp = res.size()-1;
            res.push_back(res[tmp]+res[tmp-1]);
        }
        if(res.back() == end)
            return res;
        else{
            res.clear();
            res.push_back(start);
        }
    }
    res.pop_back();
    return res;
}


int main(int argc,char* argv[]){
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    //string wrong(argv[2]);

    vector<int> res = create(start,end);
    print(res);
}