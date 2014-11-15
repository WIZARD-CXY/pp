/*************************************************************************
	> File Name: 1055.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Nov 2014 11:24:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

struct rec{
    char name[9];
    int age;
    int networth;
};

bool cmp2(const rec &a, const rec &b){
    if( a.networth> b.networth ){
        return true;
    } else if( a.networth == b.networth  ){
        if( a.age < b.age ){
            return true;
        }
        else if (a.age == b.age){
            return strcmp(a.name,b.name) < 0;
        }else {
            return false;
        }

    }else {
        return false;
    }
}

int main(){
    freopen("1055.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);

    vector<rec> records(n);

    for(int i=0; i<n; i++){
        scanf("%s%d%d",records[i].name, &records[i].age, &records[i].networth);
    }

    for(int i=0; i<k; i++){
        int m;
        int Amin,Amax;
        scanf("%d%d%d", &m, &Amin, &Amax);

        vector<rec> res;
        for(int j=0; j<n; j++){
            if(records[j].age<=Amax && records[j].age >= Amin){
                res.push_back(records[j]);
            }
        }

        sort(res.begin(),res.end(),cmp2);

        printf("Case #%d:\n",i+1);
        if(res.size()==0){
            printf("None\n");
            continue;
        }
        for(int j=0; j<m && j<res.size(); j++){
            printf("%s %d %d\n",res[j].name, res[j].age, res[j].networth);
            
        }
    }
}
