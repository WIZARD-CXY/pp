/*************************************************************************
	> File Name: 1036.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Oct 2014 10:06:55 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

struct record{
    string name;
    char sex;
    string ID;
    int grade;
};

int main(){
    freopen("1036.txt","r",stdin);
    int n;

    cin>>n;
    record girlhigh;
    record boylow;
    
    boylow.grade=100;
    girlhigh.grade=0;

    int boycount=0;

    for(int i=0; i<n; i++){
        string name;
        char sex;
        string ID;
        int grade;
        cin>>name>>sex>>ID>>grade;
        if(sex=='M'){
            boycount++;
            if(grade <= boylow.grade){
                boylow.name=name;
                boylow.ID=ID;
                boylow.grade=grade;
            }
        } else {
            if(grade >= girlhigh.grade){
                girlhigh.name=name;
                girlhigh.grade=grade;
                girlhigh.ID=ID;
            }
        }
    }

    if(boycount==n ){
        cout<<"Absent"<<endl;
    }else {
        cout<<girlhigh.name<<" "<<girlhigh.ID<<endl;
    }

    if(boycount==0){
        cout<<"Absent"<<endl;
    }else{
        cout<<boylow.name<<" "<<boylow.ID<<endl;
    }

    if(boycount ==0 || boycount == n){
        cout<<"NA"<<endl;

    }else {
        cout<<girlhigh.grade-boylow.grade<<endl;
    }
    
}


