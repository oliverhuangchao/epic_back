#include "basic.h"

void print_frequence(string str){
	//removeChar(str,' ');
	map<char,int> z;
	vector<char> check;
	//set<char> check;
	for(char x:str){
		if(x == ' ') continue;
		if(z.count(x) != 0){
			z[x]++;
		}
		else{
			z.insert({x,1});
			check.push_back(x);
		}
	}
	vector<string> res;

	int max_value = INT_MIN;
	char max_char = '$';
	int min_value = INT_MAX;
	char min_char = '$';

	for(auto i = check.begin();i!= check.end();i++){
		//print(*i);
		string tmp = "";
		tmp.push_back(*i);
		tmp.push_back(':');
		tmp.append(to_string(z[*i]));
		res.push_back(tmp);
		if(max_value < z[*i]){
			max_value = z[*i];
			max_char = *i;
		}
		if(min_value > z[*i]){
			min_value = z[*i];
			min_char = *i;
		}
	}

	for(char &item :str){
		if(item == min_char)
			item = max_char;
		else{
			if(item == max_char)
				item = min_char;
		}
	}
	print(res);
	print(str);
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
    print_frequence(str);
    return 0;
}