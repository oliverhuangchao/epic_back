#include "basic.h"
/*
6. Keypad Permutation 
Phone has letters on the number keys. forexample, number 2 has ABC on it, number 3 has 
DEF, 4 number has GHI,... , andnumber 9 has WXYZ. Write a program that will print out all 
of the possiblecombination of those letters depending on the input.   
*/

void dfs(const string &inputString, unordered_map<char,string> &check, vector<string> &result, string &path, int step, const int &size){
    if(step == size){
        result.push_back(path);
        return;
    }
   
    //string a = check['2'];
    
    string checklist = check[inputString[step]];
    for(char item : checklist){
        path.push_back(item);
        dfs(inputString,check,result,path,step+1,size);
        path.pop_back();
    }
    return;
}



void keypad(string x){
    unordered_map<char,string> check({{'2',"ABC"},{'3',"DEF"},{'4',"GHI"},{'5',"JKL"},{'6',"MNO"},{'7',"PQRS"},{'8',"TUV"},{'9',"WXYZ"}});

    vector<string> res;
    string path;
    dfs(x,check,res,path,0,x.size());
    print(res);

    string a = check['2'];
//    print(check['2']);
}


int main(int argc,char* argv[]){
    //int n = atoi((argv[1]));
    string a(argv[1]);
    keypad(a);
}