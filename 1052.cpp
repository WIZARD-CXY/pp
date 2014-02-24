/*************************************************************************
	> File Name: 1052.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 23 Feb 2014 10:17:51 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#define MAXN 100000
#include <map>
#include <cstdio>

struct Record{
    int addr;
    int key;
    int next;
};

bool cmp(const Record &a, const Record &b){
    return a.key < b.key;
}

bool isExist[MAXN];

int main(){
#ifdef d
    freopen("1052.txt","r",stdin);
#endif
    int n,head;
    cin>>n>>head;
    map<int,Record > mmap;

    Record tmp;
    for(int i=0; i<n; i++){
        cin>>tmp.addr>>tmp.key>>tmp.next;
        isExist[tmp.addr]=1;
        mmap[tmp.addr]=tmp;
    }

    vector<Record > rec;

    if(head == -1){
        cout<<"0 -1"<<endl;
        return 0;
    } else if ( !isExist[head]){
        printf("0 %05d",head);
        return 0;
    } else {
        int curaddr=head;
        while ( curaddr>=0 && curaddr <MAXN && curaddr!=-1 && isExist[curaddr]){
            rec.push_back(mmap[curaddr]);
            curaddr=mmap[curaddr].next;
        }
    }

    sort(rec.begin(),rec.end(),cmp);

    cout<<rec.size()<<" "<<rec[0].addr<<endl;

    for(int i=0; i!=rec.size(); i++){
        if(i==rec.size()-1){
            printf("%05d %d -1\n",rec[i].addr,rec[i].key);
        }else {

            printf("%05d %d %05d\n",rec[i].addr,rec[i].key,rec[i+1].addr);
        }
    }
}
