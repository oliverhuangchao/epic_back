#include "basic.h"
/*
  Replace Words 
Given a string. Replace the words whose length>=4 and is even, with a space between the 
two equal halves of the word. Consideronly alphabets for finding the evenness of the word  
I/P "A person can't walk in this street"  
O/P "A per son ca n't wa lk in th is str eet" 
*/

inline int checkstr(const string &str){
	int count = 0;
	for(char item : str){
		if((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z')){
			++count;
		}
	}
	return count;
}

inline void split_word(string &word,int count){//key part
	int index = 0;
	for(int i=0;i<word.size();i++){
		char item = word[i];
		if((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z')){
			index++;
		}
		if(index == count/2)
			break;
	}
	word.insert(word.begin()+index,' ');
	return;
}

void replace_words(string &str){
	vector<string> z = splitString(str,' ');
	for(string &item : z){
		int count = checkstr(item);
		if(count>=4 && count%2 ==0){
			split_word(item,count);
		}
	}
	print(joinVector(z,' '));
}



int main(int argc,char* argv[]){
    //int start = atoi(argv[1]);
    //string x(argv[1]);
    //float actual = atof(argv[1]);

    string x("A person can't walk in this street");
    replace_words(x);

    string y = "012345";
    y.insert(y.begin()+2,'*');
    print(y);

}