/*************************************************************************
	> File Name: 1064.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 23 Feb 2014 11:24:16 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <algorithm>

int t[1001],a[1001],n;
int m=1;

void inorderTrav(int index){
    if(index*2 <=n){
        inorderTrav(index*2);
    }
    t[index]=a[m++];
    if(index*2+1<=n){
        inorderTrav(index*2+1);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);

    inorderTrav(1);

    for(int i=1; i<=n; i++){
        printf("%d",t[i]);
        if(i!=n) printf(" ");
    }
}
