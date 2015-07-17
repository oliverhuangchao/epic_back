#include "basic.h"
/*
 two primes
 Goldbach's conjecture : Every even integer greater than 2 can be expressed as the sum of 
two primes. Write a functionwhich takes a number as input, verify if is an even number 
greater than 2 and also print at least one pair of prime numbers. 
*/

bool isPrime(vector<int> &primelist,int n){
    int mid = sqrt(n);
    if(n == 2){
        primelist.push_back(2);
        return true;
    }
    for(int item : primelist){
        if(item > mid) break;
        if(n % item == 0)
            return false;
    }
    primelist.push_back(n);
    return true;
}

vector<int> sum_2(vector<int> &nums,int target){
    int a = 0;
    int b = nums.size()-1;
    vector<int> res;
    while(a<b){
        int temp = nums[a]+nums[b];
        if(temp == target){
            print(a);
            res.push_back(nums[a]);
            res.push_back(nums[b]);
            return res;
        }
        else{
            if(temp<target) a++;
            else b--;
        }
    }
    return res;
}


void Goldbach(int n){
    vector<int> primelist(1,2);
    for(int i=3;i<=n;i++){
        isPrime(primelist,i);
    }
    print(primelist);
    primelist.insert(primelist.begin()+0,1);
    vector<int> res = sum_2(primelist,n);
    print(res);

}



int main(int argc,char* argv[]){
    int n = atoi((argv[1]));
    Goldbach(n);
}