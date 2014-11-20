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

void printInorder(int index){
    if(2*index<=n){
        printInorder(2*index);
    }
    printf("%d ",t[index]);
    if(2*index+1<=n){
        printInorder(2*index+1);
    }
}

int main(){
    freopen("1064.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);// a is now binary search tree inorderTrav res;
    // t is the array presentation of binarysearchtree
    // if t[i] is root t[2*i] is left child t[2*i+1] is the right child

    inorderTrav(1);

    for(int i=1; i<=n; i++){
        printf("%d",t[i]);
        if(i!=n) printf(" ");
    }

    cout<<endl;
    printInorder(1);
}
