#include "basic.h"

/*
19.     Fibbonaci Number 
There is one kind of numbers call Fibbonaci Number, which satisfy the following situation: 
A. can be spilt into several numbers; 
B. The first two number are the same, the next number is equal to the sum of previous two 
eg. 112 (2 = 1 + 1), 12,122,436(12 + 12 = 24,12 + 24 = 36) 
*/


// still not finished 
vector<string> create(int start,int end){
    vector<string> res;
    for(int i = 1;i<end;i++){
        string tmp = "";
        int first = i;
        int second = i;
        tmp.append(to_string(first));
        tmp.append(to_string(second));
        if(stoi(tmp) > end)//key here, we need to stop all their is no need to continue
            break;
        while(1){
            int third = first + second;
            string mid = tmp+to_string(third);
            if(stoi(mid) > end){
                if(stoi(tmp) >= start) res.push_back(tmp);
                break;  
            }
            tmp.append(to_string(third));
            first = second;
            second = third;
        }
    }

    return res;
}


int main(int argc,char* argv[]){
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    //string wrong(argv[2]);

    vector<string> res = create(start,end);
    print(res);
}