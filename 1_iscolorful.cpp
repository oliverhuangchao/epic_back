/*
    colorful number
*/
#include "basic.h"

bool isColorful(int n){
    unordered_set<int> check;
    vector<char> nums = splitString(to_string(n));
    check.insert(nums[0]-48);
    vector<int> tmp;
    for(int i=1;i<nums.size();i++){
        int digit = nums[i]-48;
        if(check.find(digit) != check.end())
            return false;
        for(auto item : check){
            int x = digit*item;
            if(check.find(x) != check.end())
                return false;
            else
                tmp.push_back(x);
        }
        for(int x : tmp){
            check.insert(x);
        }
        tmp.clear();
    }
    return true;
}

int main(int argc,char* argv[]){
    //string str = "hello//world/chaoh";
    //string str = "0123456789";
    //str.erase(str.begin()+1,str.begin()+5);
    
    int str = 3214;
    print(isColorful(str));

}