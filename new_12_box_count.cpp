#include "basic.h"

/*
given three box whose value is 6,9,20
given a number N,
find all the combinues of three boxes together can take N
*/
//int x[3] = {6,9,20};

void dfs(const vector<int> &box,vector<vector<int>> &result, vector<int> &path, int target,int pos){
	if(target == 0){
		result.push_back(path);
		print(path);
		return;
	}
	for(int i = pos;i<box.size();i++){
		if(target < box[i]) return;//key point
		path.push_back(box[i]);
		dfs(box,result,path,target-box[i],i);
		path.pop_back();
	}
}


void print_combination(int N){
	int x[] = {6,9,20};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> box = getVector(x,len);
	vector<vector<int>> result;
	vector<int> path;
	dfs(box,result,path,N,0);
	//print(result);
}



int main(int argc,char* argv[]){
	/* ------ intput part ------*/
 	int x = atoi(argv[1]);
    //string str(argv[1]);
    //float num = atof(argv[1]);


	/*int x[] = {5,6,23,45};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);*/
  
	print_combination(x);
    return 0;
}