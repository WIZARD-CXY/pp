/*************************************************************************
	> File Name: 1083.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Nov 2014 05:49:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>

struct rec{
    string name;
    string id;
    int grade;
};
bool cmp(const rec &a ,const rec &b){
    return a.grade > b.grade;
}
int main(){
    freopen("1083.txt","r",stdin);
    int n;
    scanf("%d",&n);

    vector<rec> records;

    records.resize(n);

    for(int i=0; i<n; i++){
        
        cin>>records[i].name>>records[i].id>>records[i].grade;
    }

    sort(records.begin(),records.end(),cmp);
    int low,high;
 
    scanf("%d%d",&low,&high);
    bool empty= true;

    for(int i=0; i<records.size(); i++){
        if(records[i].grade>=low && records[i].grade<=high){
            cout<<records[i].name<<" "<<records[i].id<<endl;
            empty=false;
        }
    }
    if(empty){
        cout<<"NONE"<<endl;
    }
}
