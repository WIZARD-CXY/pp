/*************************************************************************
	> File Name: 1002.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月17日 星期日 16时28分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define MAX 1001
double p[MAX];

int main(){
    memset(p,0,sizeof(p));
    int exp;
    double cof;
    int anum;
    
    cin>>anum;
    
    while(anum--){
        cin>>exp>>cof;
        p[exp] += cof;
    }

    int bnum;

    cin>>bnum;

    while(bnum--){
        cin>>exp>>cof;
        p[exp] += cof;
    }

    int count = 0;
    
    for (int i=0; i < MAX;i++){
        if(fabs(p[i]) > 1e-10){
            count++;
        }
    }

    cout<<count;

    for(int i=MAX-1;i>=0;i--){
        if(fabs(p[i]) > 1e-10){
            printf(" %d %.1f",i,p[i]);
        }
    }
    cout<<endl;
}
