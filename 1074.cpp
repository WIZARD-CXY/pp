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
    vector<record*> reverse_rec;

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
    rec.push_back(mm[temp]);

    int i;
    for(i=0; i<n/k; i++){
        for(int j=0; j<k; j++){
            reverse_rec.push_back(rec[(i+1)*k-j-1]);
        }
    }
    if(i*k<n){
        for(int j=i*k; j<n; j++){
            reverse_rec.push_back(rec[j]);
        }
    }

    for(int j=0; j< reverse_rec.size()-1; j++){
        cout<<reverse_rec[j]->addr<<" "<<reverse_rec[j]->data<<" "<<reverse_rec[j+1]->addr<<endl;
    }
    cout<<reverse_rec[n-1]->addr<<" "<<reverse_rec[n-1]->data<<" -1"<<endl;
}
