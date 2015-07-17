#include "basic.h"

/*
Replace String 
Froma given string, replace all instances of 'a' with 'one' and 'A' with 'ONE'. 
Example Input: " A boy is playing in a garden" 
Example Output: " ONE boy is playing in onegarden" 
-- Not that 'A' and 'a' are to be replaced only when theyare single characters, not as part of 
another word.
*/

//key part: the following functions
/*
vector<string> splitString(string,char);
string joinVector(vector<string>,char);
*/


void replace(string& str){
	vector<string> z = splitString(str,' ');
	for(auto & item: z){
		if(item == "A")
			item = "ONE";
		if(item == "a")
			item = "one";
	}
	str = joinVector(z,' ');
	print(str);
}


int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    string x(argv[1]);
    //float actual = atof(argv[1]);
    replace(x);

}