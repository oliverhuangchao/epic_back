#include "basic.h"
/*You are given a telephone keyboard 
0-0, 1-1, 2-ABC2, 3-DEF3, 4-GHI4, 5-JKL5, 6-MNO6,7-PQRS 7, 8-TUV8, 9-WXYZ9, *-space, 
#-char separater 
if you type "2", you will get 'A', that is "2"-'A', "22"-'B' ,"222"-'C', "2222"-'D' 
However, the digits can repeated many times 
"22222"-you get 'A' again. 
You can use "#" to separate characters, for example 
"2#22", you get "AB".
However, you may also have consecutive different digits without separator:"23"-'AD' 
If you type "*", it means space.  
You a given a sequence of digits, translate it into a text message 
*/

// transform the given vector to the dict
// create two dict in the end
void create_dict(unordered_map<string,char> &dict,unordered_map<char,int> &lendict, vector<string> &inputVector){
    for (string item : inputVector){
        vector<string> tmp = splitString(item,'-');
        lendict[tmp[0][0]] = tmp[1].size();
        //dict[string(tmp[1].size(),tmp[0][0])] = tmp[1].back();
        vector<char> chars = splitString(item);
        int count = 1;
        for( char each : chars ){
            dict[string(count,tmp[0][0])] = each;
        }
    }
}

string transform(unordered_map<string,char> &dict, string &inputString,unordered_map<char,int> &lendict){
    //string res = "";
    vector<string> spaceVector = splitString(inputString,'*');
    vector<string> pieces;
    for(string item : spaceVector){
        string piece = "";
        vector<string> tmp = splitString(item,'#');
        for(string k : tmp){
            int start = 0;
            int end = 0;
            char c = k[0];
            while(start<k.size()){
                if(k[end] == c){
                    end ++;
                    continue;
                }
                int len = (end-start) % lendict[c];
                string sample = k.substr(start,len);
                start = end;
                piece.push_back(dict[sample]);
                sample = "";
            } 
        }
        pieces.push_back(piece);
    }
    return joinVector(pieces,' ');
}


void sms(){
    string x[] = {"0-0", "1-1", "2-ABC2", "3-DEF3", "4-GHI4", "5-JKL5", "6-MNO6","7-PQRS7", "8-TUV8", "9-WXYZ9"};
    string inputString = "AD";
    vector<string> z = getVector(x,10);
    unordered_map<string,char> dict;
    unordered_map<char,int> lendict;
    create_dict(dict,lendict,z);
    string res = transform(dict,inputString,lendict);
}



int main(int argc,char* argv[]){
    /*int s = atoi(argv[1]);
    int e = atoi(argv[2]);
    int size = atoi(argv[3]);*/

    sms();
}