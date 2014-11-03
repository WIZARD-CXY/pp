/*************************************************************************
	> File Name: 1074.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Nov 2014 11:21:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<cstdio>
struct record{
    string addr;
    int data;
    string next;
};

int main(){
    freopen("1074.txt","r",stdin);

    string startaddr;
    int n,k;
    cin>>startaddr>>n>>k;

    vector<record*> rec;

    map<string,record*> mm;

    for(int i=0; i<n; i++){
        record* temp=new record;
        cin>>temp->addr>>temp->data>>temp->next;
        mm[temp->addr]=temp;
    }
    
    string temp=startaddr;
    while(mm[temp]->next != "-1"){
        
        rec.push_back(mm[temp]);
        temp=mm[temp]->next;
    }
    int i;
    for(i=0; i<n/k; i++){
        for(int j=0; j<k; j++){
            cout<<rec[k*(i+1)-j-1]->addr<<" "<<rec[k*(i+1)-j-1]->data<<" "<<rec[k*(i+1)-j-1]->next<<endl;
        }
    }
    if(i*k<n){
        for(int j=i*k-1; j<n; j++){
            cout<<rec[j]->addr<<" "<<rec[j]->data<<" "<<rec[j]->next<<endl;


        }
    }
}
