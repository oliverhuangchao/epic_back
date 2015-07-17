#include "basic.h"
/*
  Plus Equal Number 
Given a number find whether the digits in the number can be used to form an equation with 
+ and '='. That is if the number is123, we can have a equation of 1+2=3. But even the 
number 17512 also forms the equation 12+5=17. 
*/


// suppost there is just one '+' and one '-'
// so the algorithm should go starting from two sides
//


// check "17=5+12"
inline bool check_equation(const string &str){
	vector<string> z = splitString(str,'=');
	string result;
	string add;
	if(z[0].size()> z[1].size()){
		result = z[1];
		add = z[0];
	}else{
		result = z[0];
		add = z[1];
	}
	vector<string> num_list = splitString(add,'+');
	int count = 0;
	for(string item:num_list)
		count += stoi(item);
	return count == stoi(result);
}


void print_equation(string str){
	vector<char> nums = splitString(str);
	vector<string> res;
	for(int i=1;i<nums.size();i++){
		nums.insert(nums.begin()+i,'=');
		for(int j=1;j<nums.size()+1;j++){
			if(j ==i || j == i+1) continue; //key point: do not forget this case
			nums.insert(nums.begin()+j,'+');
			string tmp = joinVector(nums);
			if(check_equation(tmp)){
				res.push_back(tmp);
			}
			nums.erase(nums.begin()+j);
		}
		nums.erase(nums.begin()+i);
	}
	print(res);
}


int main(int argc,char* argv[]){
	/* ------ intput part ------*/
 	//int x = atoi(argv[1]);
    string str(argv[1]);
    //float num = atof(argv[1]);


	//int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	//int len = sizeof(x)/sizeof(x[0]);
	//vector<int> nums = getVector(x,len);
  
  //print(check_equation(str));
    print_equation(str);
    return 0;
}