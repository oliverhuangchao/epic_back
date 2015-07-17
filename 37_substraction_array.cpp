#include "basic.h"

/*
 Subtraction of two Arrays 
Suppose you want to do the subtraction of twonumbers. Each digit of the numbers is divided 
and put in an array. Like A=[1,2, 3, 4, 5], B=[4, 5, 3, 5]. You should output an array C=[7, 
8, 1, 0].Remember that your machine can’t hand numbers larger than 20. 
*/

void substraction(int x,int y){

	vector<int> first = splitNum(x);
	vector<int> second = splitNum(y);

	if(first.size()<second.size())
		print("wrong input");
	reverse(first.begin(),first.end());
	reverse(second.begin(),second.end());
	//print(first);
	//print(second);
	int size = second.size();
	int flag = 0;
	vector<int> res;
	int i = 0;
	for(i;i<size;i++){
		first[i] -= flag;
		if(first[i] < second[i]){
			flag = 1;
			first[i] += 10;
		}
		else{
			flag = 0;//key point: do not forget this else section
		}
		res.push_back(first[i] - second[i]);
	}
	for(i;i<first.size();i++){
		first[i] -= flag;
		res.push_back(first[i]);
	}

	//print(res);
	while(res.back() == 0)
		res.pop_back();
	reverse(res.begin(),res.end());
	
	print(res);
}




int main(int argc,char* argv[]){
	/* ------ intput part ------*/
   	int x = atoi(argv[1]);
   	int y = atoi(argv[2]);
    //string str(argv[1]);
    //float num = atof(argv[1]);


	//int x[] = {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
	//int len = sizeof(x)/sizeof(x[0]);
	//vector<int> nums = getVector(x,len);
    
   	print(x-y);
   	substraction(x,y);
    return 0;
}