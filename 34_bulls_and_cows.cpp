#include "basic.h"
#include <time.h>
/*
bulls and cows problem
bulls: position and value is right
cows: only value is right
*/


unordered_map<char,unordered_set<int>> z;
bool check(string s,string p){
    for(int i=0;i<s.size();i++){
        if(z.find(s[i]) == z.end()){
            z.insert({s[i],unordered_set<int>({i})});
        }
        else{
            z[s[i]].insert(i);
        }
    }
    int bulls = 0;
    int cows = 0;
    for(int i=0;i<p.size();i++){
        if(z.find(p[i]) != z.end()){
            if(z[p[i]].find(i) != z[p[i]].end())
                bulls++;
            else
                cows++;
        }
    }

    print("bulls is"+to_string(bulls));
    print("cows is"+to_string(cows));
}

int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    string s(argv[1]);
   	string p(argv[2]);
    //float actual = atof(argv[1]);	
    print(check(s,p));
    return 0;
}