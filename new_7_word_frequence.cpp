#include "basic.h"

/*
merge two list
*/
void print_triangle(vector<int> &nums){
	vector<int> nextlevel;
	print(nums);
	while(nums.size() > 1){
		for(int i=1;i<nums.size();i++){
			nextlevel.push_back(nums[i]+nums[i-1]);
		}
		print(nextlevel);
		nums.clear();
		nums = nextlevel;
		nextlevel.clear();
	}
}


int main(int argc,char* argv[]){
	/* ------ intput part ------*/
 	//int x = atoi(argv[1]);
    //string str(argv[1]);
    //float num = atof(argv[1]);


	int x[] = {5,6,23,45};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);
  
	print_triangle(nums);
    return 0;
}