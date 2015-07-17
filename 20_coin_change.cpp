#include "basic.h"

/*
Coin Change 
Somethingcost $10.25 and the customer pays with a $20 bill, the program will print outthe most 
efficient "change-breakdown" which is 1 five, 4 ones, and 3quarters. Find the minimum number 
of coins required to make change for a given sum (given unlimited cumber of N different 
denominations coin) 
*/

void dfs(){

}

// still not finished 
void coin_back(float actual, float given){
    int returnValue =(int)(given*100 - actual*100);
    print("should charge "+to_string(returnValue)+" cents");
    int x[] = {1000,500,100,50,25,10,5,1};//use cents
    int len = sizeof(x)/sizeof(x[0]);
    vector<int> res(len,0);
    print(x,len);
   	print(res);
    int i=0;
    while(1){
        if(returnValue == 0) break;
        /* ----- key part ------ */
        ++res[i];
        returnValue -= x[i];
        if(returnValue<0){
        	returnValue += x[i];
            --res[i++];
        }
        /* ----- key part ------ */
    }
    for(int i=0;i<res.size();i++){
    	if(res[i]!=0){
    		print(to_string(x[i]) + " use " + to_string(res[i]));
    	}
    }
}


int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    //string wrong(argv[2]);
    float actual = atof(argv[1]);
    float given = atof(argv[2]);

    coin_back(actual,given);

   
}