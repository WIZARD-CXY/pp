/*************************************************************************
	> File Name: 1028.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Oct 2014 10:32:45 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

struct record{
    char id[15];
    char name[15];
    int grade;
};

record records[100005];

bool cmp1(const record &a, const record &b)
{
    return strcmp(a.id,b.id)<0;
}
bool cmp2(const record &a, const record &b){
    if(strcmp(a.name,b.name)<0){
        return true;
    }else if (strcmp(a.name ,b.name)==0){
        return strcmp(a.id,b.id)<0;
    }else {
        return false;
    }
}

bool cmp3(const record &a, const record &b){
    if(a.grade < b.grade) {
        return true;
    }else if (a.grade==b.grade){
        return strcmp(a.id,b.id)<0;
    }else {
        return false;
    }
}

int main(){
   // freopen("1028.txt","r",stdin);
    int n,c;
    cin>>n>>c;

    for(int i=0; i<n; i++){
       scanf("%s%s%d",records[i].id, records[i].name, &records[i].grade);
    }

    if(c==1){
        sort(records,records+n,cmp1);
    }
    else if(c == 2){
        sort(records,records+n,cmp2);
    }else {
        sort(records,records+n,cmp3);
    }

    for(int i=0; i<n; i++)
       printf("%s %s %d\n",records[i].id , records[i].name ,records[i].grade);
}
