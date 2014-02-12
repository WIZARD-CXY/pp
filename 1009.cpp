/*************************************************************************
	> File Name: 1009.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 12 Feb 2014 02:52:51 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAXN 1001

//two poly array 
double poly1[MAXN];
double poly2[MAXN];
double poly[MAXN+MAXN];

int main(){
    int k1,k2;
    cin>>k1;

    int exp;
    double coff;

    for(int i=0; i<k1; i++){
        cin>>exp>>coff;
        poly1[exp]=coff;
    }

    cin>>k2;

    for(int i=0; i<k2; i++){
        cin>>exp>>coff;
        poly2[exp]=coff;
    }

    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            if( fabs(poly1[i])>1e-10 && fabs(poly2[j])>1e-10 ){
                poly[i+j]+=poly1[i]*poly2[j];
            }
        }
    }

    int num=0;
    for(int i=0; i<2*MAXN; i++){
        if(fabs(poly[i])>1e-10){
            num++;
        }
    }
    cout<<num;

    for(int i=2*MAXN; i>=0; i--){
        if(fabs(poly[i])>1e-10){
            printf(" %d %.1lf",i,poly[i]);
        }
    }
}

