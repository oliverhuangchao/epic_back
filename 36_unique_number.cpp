#include "basic.h"

/*
 Unique Number 
Write, efficient code for extracting uniqueelements from a sorted list of array. e.g. (1, 1, 3, 3, 
3, 5, 5, 5, 9, 9, 9, 9)-> (1, 3, 5, 9). 
*/

void remove_duplicate(vector<int> &nums){
     int curr = nums[0];
     int i=1;
     while(i<nums.size()){
          if(nums[i] == curr){
               nums.erase(nums.begin()+i);
          }
          else{
               curr = nums[i++];
          }
     }
     print(nums);
}

int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    //string str(argv[1]);
   	//string weekday(argv[2]);
    //float num = atof(argv[1]);	

	int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);
    remove_duplicate(nums);
    return 0;
}