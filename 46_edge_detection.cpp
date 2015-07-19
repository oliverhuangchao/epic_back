#include "basic.h"
/*
Edge Detection 
Two-dimensional array representation of an image can also be represented by a one-
dimensional array of W*H size, where W represent row and H represent column size and 
each cell represent pixel value of that image. You are also given a threshold X. For edge 
detection, you have to compute difference of a pixel value with each of it's adjacent pixel 
and find maximum of all differences. And finally compare if that maximum differenceis 
greater than threshold X. if so, then that pixel is a edge pixel and have todisplay it. 

*/
//similar to find max point


void extend_matrix(vector<vector<int>> &matrix){

}

void search_for_eachpixel(vector<vector<int>> &matrix,int value){
	
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