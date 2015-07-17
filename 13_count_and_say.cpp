#include "basic.h"
/*Count And Say 
First,let user input a number, say 1. Then, the function will generate the next 10numbers which 
satisfy this condition:  
1, 11,21,1211,111221,312211...  
explanation: first number 1, second number is one 1, so 11. Third number is two1(previous 
number), so 21. next number one 2 one 1, so 1211 and so on... */


string sayNext(string curr){
    int start = 0;
    int end = 0;
    char c = curr[start];
    string res = "";
    while(start<curr.size()){
        while(curr[end] == c){
            ++end;
        }
        int count = end-start;
        res.append(to_string(count));res.push_back(c);
        start = end;
        c = curr[start];
    }
    return res;
}


int main(int argc,char* argv[]){
    /*int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);*/
    vector<string> res;
    string x(argv[1]);
    res.push_back(x);
    for(int i=0;i<10;i++){
        x = sayNext(x);
        res.push_back(x);
    }
    print(res);
}