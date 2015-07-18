#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> vectorinput(int *x,int l){
	//int l = sizeof(x)/sizeof(x[0]);
	vector<int> nums;
	for(int i=0;i<l;i++){
		nums.push_back(x[i]);
	}
	return nums;
}
//------ below is the function defination ------
/*
You are given an N*N matrix. The matrix contains characters. Write a program to find a word in the matrix.The word can be found in either the rows or columns or the diagonals. The program should return true if the word is found and false if the word is not found.

*/
/*
// find the ideal number
void dfs(vector<vector<int>> &result,vector<int> &path,int step,int target){
	if(step == target)	result.push_back(path);
	if(path.empty()){
		for(int i=0;i<=9;i++){
			path.push_back(i);
			dfs(result,path,step+1,target);
			path.pop_back();
		}
		return;
	}
	if(path.back() == 9) return;
	for(int i=path.back()+1;i<=9;i++){
		path.push_back(i);
		dfs(result,path,step+1,target);
		path.pop_back();
	}
	return;
}
*/
/*
 *trans from one string to another string only by swap
void swap(string &x,int i,int j){
	char tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void swapAll(string &x,int i,int j){
	while(i<j){
		swap(x,j-1,j);
		j--;
		cout<<x<<endl;
	}
}
		

void transform(string src,string des){
	int a = 0;
	int b = a;
	int c;
	while(a<des.size()){
		if(des[a] == src[b]){
			a++;
			b++;
		}
		else{
			c = b;
			while(src[c] != des[a])
				c++;
			//cout<<c<<endl;
			swapAll(src,a,c);
			//cout<<src<<endl;
		}
	}
}
*/
/*
// find the subarray that fix the sum value
vector<pair<int,int>> findSubarray(vector<int> nums,int tareget){
	vector<int> z;
	vector<pair<int,int>> result;
	unordered_map<int,int> hmap;
	z.push_back(nums[0]);
	int size = nums.size();
	hmap.insert({z[0],0});
	for(int i=1;i<size;i++){
		z.push_back(z[i-1]+nums[i]);
		hmap.insert({z[i],i});
	}
	for(int i=0;i<size;i++){
		int tmp = 16+z[i];
		if(hmap.find(tmp) != hmap.end()){
			result.push_back({i+1,hmap[tmp]});
		}
	}
	return result;
}
*/
int main(int argc,char **argv){
	int i=1;
	int n = 3;
	int count = 0;
	while(i>0){
		if((n & i) > 0){
			count++;
		}
		i = i<<1;
	}
	cout<<count<<endl;
	return count;
}


