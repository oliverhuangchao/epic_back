#include "basic.h"
/*Advisered Average Number 
Write aprogram to display the advisered average for the list of numbers my omittingthe three 
largest number in the series. 
E.g:3,6,12,55,289,600,534,900,172.  avg=(3+6+12+55+289+172) /6and 
eliminating534,900,600 */

int sum(const vector<int> &x){
    int res = 0;
    for(auto item : x)
        res += item;
    return res;
}


int average(vector<int> nums){
    priority_queue<int,vector<int>,greater<int>> q;
    if(nums.size()<=3) return sum(nums);
    for(int i=0;i<3;i++){
        q.push(nums[i]);
    }
    int res = 0;
    for(int i=3;i<nums.size();i++){
        if(nums[i] > q.top()){
            res += q.top();
            print(q.top());
            q.pop();
            q.push(nums[i]);
        }
        else{
            res += nums[i];
        }
    }
    return res/(nums.size()-3);
}

int main(int argc,char* argv[]){
    /*int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);*/
    int x[] = {3,6,12,55,289,600,534,900,172};
    vector<int> nums = getVector(x,9);
    print(average(nums));
    /*priority_queue<int,vector<int>,less<int>> q;
    q.push(3);
    q.push(2);
    print(q.top());*/
    //sms();
}