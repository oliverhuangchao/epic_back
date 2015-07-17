#include "basic.h"


/*
split a number vector using a vector
*/

void split_vector(string str){
	int a[] = {3,4,2,1};
	vector<int> z = getVector(a,4);
	reverse(z.begin(),z.end());
	int start = 0;
	int end;
	vector<string> res;
	for(int i=0;i<z.size();i++){
		end = z[i];
		res.push_back(str.substr(start,end));
		start += end;
	}
	reverse(res.begin(),res.end());
	print(joinVector(res,'-'));
}

int main(int argc,char* argv[]){
	/* ------ intput part ------*/
 	//int x = atoi(argv[1]);
    string str(argv[1]);
    //float num = atof(argv[1]);


	/*int x[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);*/
  
  	split_vector(str);
    return 0;
}