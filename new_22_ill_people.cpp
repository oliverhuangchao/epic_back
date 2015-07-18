#include "basic.h"


unordered_set<int> ill_list;
inline bool checkit(int people){
    return ill_list.find(people) != ill_list.end();
}

void print_ill_people(){
    int x[] = {3,4,-1,-1,-1,-1,3,3,-1,4,1,2,2,4,-1,-1,1,-1,3,2};
    vector<vector<int>> matrix = getMatrix(x,4,5);
    print(matrix);
    int people = 4;
    int N = 5;
    int init = 2; // init people
    /*vector<vector<bool>> check(people,vector<bool>(N,false));
    for(int i=0;i<N;i++)
        check[init-1][i] = true;*/
    ill_list.insert(init-1);
    for(int k = 0;k<N;k++){
        for(int p=0;p<people;p++){
            if(matrix[p][k] != -1 && (checkit(p) || checkit(matrix[p][k]-1))){
                if(!checkit(p)) ill_list.insert(p);
                if(!checkit(matrix[p][k]-1)) ill_list.insert(matrix[p][k]-1);
            }
        }
    }
    vector<int> res;
    for(auto it = ill_list.begin();it != ill_list.end();it++)
        res.push_back(*it+1);
    sort(res.begin(),res.end());
    print(res);
}


int main(int argc,char* argv[]){
    //int s = atoi(argv[1]);
   	//string whole(argv[1]);
    print_ill_people();
}