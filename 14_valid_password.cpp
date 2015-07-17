#include "basic.h"
 /* Valid Password 
In 1-9 keypad one key is not working. If someone enters a password then not working key 
will not be entered. You have givenexpected password and entered password. Check that 
entered password is valid ornot. Ex: entered 164, expected 18684 (you need to take care as 
when u enter 18684 and 164 only both will be taken as 164 input) */


bool checkValid(string &whole,string &wrong){
    unordered_map<char,int> check;
    for(char x: wrong){
        if(check.find(x) == check.end())
            check.insert({x,1});
        else
            ++check[x];
    }
    char tmp = '?';
    for(char x:whole){
        if(check.find(x) == check.end()){
            if(tmp == '?')
                tmp = x;
            else
                if(x != tmp) return false;
        }
        else{
            --check[x];
        }
    }

    for(auto x = check.begin();x!=check.end();x++)
        if(x->second != 0)
            return false;
    return true;
}


int main(int argc,char* argv[]){
    /*int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);*/
    string whole(argv[1]);
    string wrong(argv[2]);
    print(checkValid(whole,wrong));
}