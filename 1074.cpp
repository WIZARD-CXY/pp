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
    int addr;
    int data;
    int next;
};

int main(){
    freopen("1074.txt","r",stdin);

    int startaddr;
    int n,k;
    scanf("%d%d%d",&startaddr, &n, &k);

    vector<record*> rec;
    vector<record*> reverse_rec;

    map<int,record*> mm;

    for(int i=0; i<n; i++){
        record* temp=new record;
        scanf("%d%d%d",&(temp->addr), (&temp->data), (&temp->next));
        mm[temp->addr]=temp;
    }
    
    int temp=startaddr;
    while(mm[temp]->next != -1){

        if(mm.find(mm[temp]->next) == mm.end()) break; //next key isn't in the map
        rec.push_back(mm[temp]);
        temp=mm[temp]->next;
    }
    rec.push_back(mm[temp]);

    int i;

    for(i=0; i<rec.size()/k; i++){
        for(int j=0; j<k; j++){
            reverse_rec.push_back(rec[(i+1)*k-j-1]);
        }
    }
    if(i*k<rec.size()){
        for(int j=i*k; j<rec.size(); j++){
            reverse_rec.push_back(rec[j]);
        }
    }

    for(int j=0; j< reverse_rec.size()-1; j++){
    printf("%05d %d %05d\n",reverse_rec[j]->addr, reverse_rec[j]->data,reverse_rec[j+1]->addr);
    }
    printf("%05d %d -1\n",reverse_rec[reverse_rec.size()-1]->addr,reverse_rec[reverse_rec.size()-1]->data);
}
