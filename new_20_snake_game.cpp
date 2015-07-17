#include "basic.h"
 /*16.     Snake Sequence 
 You are given a grid of numbers. A snakesequence is made up of adjacent numbers such 
 that for each number, the numberon the right or the number below it is +1 or -1 its value. 
 For example,  
 1 3 2 6 8  
 -9 7 1 -1 2  
 1 5 0 1 9  
 In this grid, (3, 2, 1, 0, 1) is a snake sequence. Given a grid, find thelongest snake 
 sequences and their lengths (so there can be multiple snakesequences with the maximum 
 length). */

unordered_map<string,vector<int>> check;


// key point 
// how to update max_len: when there is no way, then update $check and $max_len
//
void dfs(vector<vector<int>> &matrix,int i,int j,vector<int> &path, const string label, int &max_len){
    int value = matrix[i][j];
    // go to rigth
    if(j != matrix[0].size()-1 && (matrix[i][j+1] - value) == 1){
		string tmp_label=to_string(i)+'-'+to_string(j+1);
		if(check.find(tmp_label) != check.end()){
			int add_start = path.size();
			path.insert(path.end(),check[tmp_label].begin(),check[tmp_label].end());
			if(max_len<path.size()){
				max_len = path.size();
				check[label] = path;
			}
			path.erase(path.begin()+add_start,path.end());
		}
     	else{
	        path.push_back(matrix[i][j+1]);
	        dfs(matrix,i,j+1,path,label,max_len);
	        path.pop_back();
	    }
    }

    // go to the down
    if(i != matrix.size()-1 && (matrix[i+1][j] - value) == 1){
		string tmp_label=to_string(i+1)+'-'+to_string(j);
		if(check.find(tmp_label) != check.end()){
			int add_start = path.size();
			path.insert(path.end(),check[tmp_label].begin(),check[tmp_label].end());
			if(max_len<path.size()){
				max_len = path.size();
				check[label] = path;
			}
			path.erase(path.begin()+add_start,path.end());
		}
     	else{
	        path.push_back(matrix[i+1][j]);
	        dfs(matrix,i+1,j,path,label,max_len);
	        path.pop_back();
	    }
    }

    // go to the left
    if(j != 0 && (matrix[i][j-1] - value) == 1){
		string tmp_label=to_string(i)+'-'+to_string(j-1);
		if(check.find(tmp_label) != check.end()){
			int add_start = path.size();
			path.insert(path.end(),check[tmp_label].begin(),check[tmp_label].end());
			if(max_len<path.size()){
				max_len = path.size();
				check[label] = path;
			}
			path.erase(path.begin()+add_start,path.end());
		}
     	else{
	        path.push_back(matrix[i][j-1]);
	        dfs(matrix,i,j-1,path,label,max_len);
	        path.pop_back();
	    }
    }

    // go the the up
    if(i != 0 && (matrix[i-1][j] - value) == 1){
		string tmp_label=to_string(i-1)+'-'+to_string(j);
		if(check.find(tmp_label) != check.end()){
			int add_start = path.size();
			path.insert(path.end(),check[tmp_label].begin(),check[tmp_label].end());
			if(max_len<path.size()){
				max_len = path.size();
				check[label] = path;
			}
			path.erase(path.begin()+add_start,path.end());
		}
     	else{
	        path.push_back(matrix[i-1][j]);
	        dfs(matrix,i-1,j,path,label,max_len);
	        path.pop_back();
	    }
    }
    if(path.size()> max_len){
	    check[label] = path;
	    max_len = path.size();
	}
    //result.push_back(path);
    return;                  
}

void findmax(){
    //int x[] = {1, 3, 2, 6, 8, -9, 7, 1, -1, 2, 1, 5, 0, 1, 9};
    int x[] = {2,3,4,5,4,5,10,11,20,6,9,12,6,7,8,40};
    //int x[] = {1,2,4,3};
    vector<vector<int>> matrix = getMatrix(x,4,4);
    vector<vector<int>> result;
    vector<int> path;
    print(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
        	string label=to_string(i)+'-'+to_string(j);
            check.insert({label,vector<int>(1,matrix[i][j])});
            int max_len = 1;
            path.push_back(matrix[i][j]);
            dfs(matrix,i,j,path,label,max_len);
            path.pop_back();
        }
    }

    for(auto it = check.begin();it!= check.end();it++){
    	//print(it->first);
    	print(it->second);
    }

    return;
}

int main(int argc,char* argv[]){
    /*int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);*/
   /* string whole(argv[1]);
    string wrong(argv[2]);*/


    findmax();
}