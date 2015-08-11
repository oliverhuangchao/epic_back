// how to implement a dose check
#include "basic.h"
class Plan{
public:
    vector<int> detail;
    string name;
    virtual int getDose(int date) = 0;
    virtual void setDose(int value,int date) = 0;

};


class first_plan:public Plan{
public:
    first_plan(string uname,string doesType){
        name = uname;
        detail.push_back(0);
    }

    int getDose(int date){
        return detail[0];
    }   
    void setDose(int value,int date){
        detail[0] = value;
    }
};

vector<int> getEach(string doesType){
    int size = doesType.size();
    int b = size-1;
    int end = size;
    vector<int> res;
    while (b>=0){
        if(doesType[b] == '-'){
            res.push_back(stoi(doesType.substr(b+1,end-b)));
            //print(doesType.substr(b+1,end-b));
            end = b;
            //b --;
        }
        b --;
    }
    //print(end);
    res.push_back(stoi(doesType.substr(0,end+1)));
    reverse(res.begin(),res.end());
    return res;
}

class second_plan:public Plan{
public:
    second_plan(string uname,string doesType){
        name = uname;
        detail = getEach(doesType);
    }
    int getDose(int date){
        return detail[date%3];
    }   
    void setDose(int value,int date){
        detail[date%3] = value;
    }
};


class planFactory{
public:
    Plan* createPlan(string uname,int pid){
        switch(pid){
            case 0:
                //upload from database
                return new first_plan(uname,"1");
                break;
            case 1:
                // upload from database
                return new second_plan(uname,"1-2-3");
                break;
            default:
                break;
        }
    }
};


int main(){
    //first_plan z("chaoh","1-2-3");
    //print(z.getDose(1));
    //print("finished");
    planFactory fac;
    Plan* x = fac.createPlan("chaoh",1);
    print(x->getDose(10));
    //print(getEach("1-2-3-10-9-5"));
}