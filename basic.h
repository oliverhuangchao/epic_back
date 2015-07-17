#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <float.h>
using namespace std;
/* ------- basic data structure ------*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
 };

// Definition for Directed graph.
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};
 


/* ------ get length functions  -------*/
int getLength(ListNode* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

/* ------print functions  -------*/
template<typename T>
void print(const vector<T>& path){
	cout<<"[";
	int size = path.size();
	for(int i=0;i<size;i++){
		if(i == size-1)
			cout<<path[i];
		else
			cout<<path[i]<<',';
	}
	cout<<"]";
	cout<<endl;
}
void print(const vector<string>& path){
	cout<<"[";	
    int size = path.size();
	for(int i=0;i<size;i++){
		if(i == size-1)
			cout<<path[i];
		else
			cout<<path[i]<<',';
	}
    cout<<"]";
    cout<<endl;
}


template<typename T>
void print(T x[],int l){
    cout<<"[";
    for(int i=0;i<l-1;i++)
        cout<<x[i]<<",";
    cout<<x[l-1];
    cout<<"]";
    cout<<endl;
}

template<typename T>
void print(T x){
    cout<<x<<endl;
}

template<typename T>
void print(const vector<vector<T>> result){
    for(auto each:result){
        for(auto x:each){
            cout<<x<<' ';
        }
        cout<<endl;
    }
    return;
}

void print(ListNode* head){
    if(!head){
        cout<<"list is empty"<<endl;
        return;
    }
    while(head->next){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<head->val<<"->NULL";
    cout<<endl;
}
template<typename T> 
void print(const unordered_set<T> &x){
    cout<<"[";
    for(auto it = x.begin(); it != x.end(); it++){
        cout<<*it<<',';
    }
    cout<<"]";
    cout<<endl;
}

template<typename T>
void print(const vector<pair<T,T>> &x){
    for(auto it: x){
        cout<<'('<<it.first<<','<<it.second<<')'<<endl;
    }
    cout<<endl;
}

template<typename T, typename G>
void print(const unordered_map<T,G> &x){
    cout<<"[";
    auto it = x.begin();
    for(auto it  = x.begin();it != x.end();it++)
        cout<<'('<<it->first<<','<<it->second<<')'<<",";
    cout<<"]";
    cout<<endl;
}

template<typename T>
void print(queue<T> x){
    while(!x.empty()){
        cout<<x.front()<<endl;
        x.pop();
    }
    cout<<endl;
}



/* ------ get vector functions  -------*/
template<typename T>
vector<T> getVector(T x[],int len){
    vector<T> nums;
    for(int i=0;i<len;i++){
        nums.push_back(x[i]);
    }
    return nums;
}

vector<Point> getPointsVector(int x[],int len){
    vector<Point> result;
    for(int i=0;i<len;i+=2){
        Point tmp(x[i],x[i+1]);
        result.push_back(tmp);
    }
    return result;
}
template<typename T>
ListNode* getList(T x[],int l){
    ListNode* head = new ListNode(x[0]);
    ListNode* tmp = head;
    for(int i=1;i<l;i++){
        ListNode* z = new ListNode(x[i]);
        tmp->next = z;
        tmp = tmp->next;
    }
    return head;
}

template<typename T> 
vector<vector<T>> getMatrix(T x[], int rows, int cols){
    vector<vector<T>> matrix;
    int i = 0;
    vector<T> tmp;
    int count = 0;
    while(count<rows){
        tmp.push_back(x[(i++)+count*cols]);
        if(i == cols){
            i = 0;
            matrix.push_back(tmp);
            tmp.clear();
            count++;
        }
    }
    return matrix;
}

/*
	useage: splitString(str,'delim')
*/
vector<string> splitString(string str,char delim){
    vector<string> res;
    int len = str.size();
    int start = 0;
    int index = string::npos;
    while(!str.empty()){
        index = str.find(delim);
        if(index == string::npos){
            res.push_back(str);
            break;
        }
        res.push_back(str.substr(start,index-start));
        str.erase(str.begin()+start,str.begin()+index+1);
    }
    return res;
}

// splict without delim means that we need to split the string char by char
vector<char> splitString(string str){
	vector<char> res;
	while(!str.empty()){
		res.push_back(str.back());
		str.pop_back();
	}
	reverse(res.begin(),res.end());
	return res;
}

// join the vector to a string
// input is vector<sting> and char
//	output is a string
string joinVector(vector<string> &vs, char delim){
	string res = "";
	for(string item : vs){
		res.append(item);
		res.push_back(delim);
	}
	res.pop_back();
	return res;
}

string joinVector(vector<char> &vc){
    string res = "";
    for(char item:vc)
        res.push_back(item);
    return res;
}

// splite a number to a int vector
vector<int> splitNum(int num){
    vector<int> res;
    while(num != 0){
        res.push_back(num % 10);
        num /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}


// transform octal to decimal
int oct2dec(int num){
    vector<char> z = splitString(to_string(num));
    int count = 0;
    reverse(z.begin(),z.end());
    for(int i=0;i<z.size();i++){
        count += (int)pow(8,i)*((int)(z[i]-48));
    }
    return count;
}

// transform decimal to octal
int dec2oct(int num){
    int res = 0;
    int i = 0;
    while(num){
        res += (int)pow(10,i)*(num%8);
        num /= 8;
        i++;
    }
    return res;
}


inline void swapChar(string &str,int i,int j){
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void removeChar(string &str,char x){
    int i=0;
    while(i<str.size()){
        if(str[i] == x){
            str.erase(i,1);
        }
        i++;
    }
}