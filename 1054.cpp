/*************************************************************************
	> File Name: 1054.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Nov 2014 01:25:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<map>

int main(){
    freopen("1054.txt","r",stdin);

    int m,n;
    scanf("%d%d",&m,&n);

    map<int,int> mm;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            scanf("%d",&temp);
            mm[temp]++;

        }
    }
    map<int,int>::iterator it;

    for(it=mm.begin(); it!=mm.end(); it++){
        if(it->second>(n*m/2)){
            printf("%d\n",it->first);
        }
    }
}
