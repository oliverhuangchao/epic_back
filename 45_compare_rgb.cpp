#include "basic.h"

/*
RGBCompare 
Given a string of RGB value (rr, gg, bb)which represents in hexadecimal. Compare if rr or gg 
or bb is the biggest, ortwo of those values are equal and larger than the third one, or three 
valuesare equal with each other. 
*/


//0xFFAABB

unordered_map<char,int> check({{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}});

void print_max(string str){
	vector<char> z = splitString(str);
	//int count = 0;
	vector<int> res;
	int count = 0;
	for(int i=0;i<z.size();i++){
		if(z[i] <='9' && z[i] >= '0'){
			if(i%2 == 1){
				count *= 10;
				count += (int)(z[i]-48);
				res.push_back(count);
				count = 0;
			}else{
				count += (int)(z[i]-48);
			}
		}
		else{
			if(i%2 == 1){
				count *= 16;
				count += check[z[i]];
				res.push_back(count);
				count = 0;
			}else{
				count += check[z[i]];
			}
		}
	}
	print(res);
	sort(res.begin(),res.end());
	int back = res.back();
	print(res.back());
	res.pop_back();
	while(!res.empty() && back == res.back()){
		print(res.back());
		res.pop_back();
	}
}

int main(int argc,char* argv[]){
	/* ------ intput part ------*/
// 	int x = atoi(argv[1]);
    string str(argv[1]);
    //float num = atof(argv[1]);


	//int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	//int len = sizeof(x)/sizeof(x[0]);
	//vector<int> nums = getVector(x,len);
  	print_max(str);
    return 0;
}