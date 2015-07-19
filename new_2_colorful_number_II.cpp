#include "basic.h"
#include <time.h>
/*
 ***Colorful Number II 
If given a number find a number if it is colorful. A number is said to be colorful if all its possible 
unique permutations multiplication result different. EX. If n=1234 then permutations are 
(1,2),(1,3),(1,4),(2,3),(2,4),(3,4),(1,2,3),(1,2,4),(2,3,4). That’s it, no other combination and if any 
of them repeats then number is not colorful. 
(Find if given set of elements 2, 4, 3 form a colorful number?) 
*/




void dfs(const vector<char> &z, vector<vector<int>> &result,vector<int> &path,int pos){
    for(int i=pos;i<z.size();i++){
        path.push_back((int)(z[i]-48));
        if(path.size()>1)
            result.push_back(path);
        dfs(z,result,path,i+1);
        path.pop_back();
    }
}


inline int getMultiply(const vector<int> &a){
    int x = 1;
    for(int item :a){
        x *= item;
    }
    return x;
}

bool isColorful(int num){
    vector<char> z = splitString(to_string(num));
    print(z);
    vector<vector<int>> result;
    vector<int> path;
    dfs(z,result,path,0);
    print(result);
    unordered_set<int> check;
    for(auto item : result){
        int tmp = getMultiply(item);
        if(check.find(tmp) != check.end()) return false;
        check.insert(tmp);
    }
    return true;
}


int main(int argc,char* argv[]){
    int start = atoi(argv[1]);
    //string day(argv[1]);
   	//string weekday(argv[2]);
    //float actual = atof(argv[1]);	
	print(isColorful(start));
    return 0;
}