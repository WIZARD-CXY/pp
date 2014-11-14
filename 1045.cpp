/*************************************************************************
	> File Name: 1045.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Nov 2014 11:35:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
int len[201][10001];

int LCS(int row,int col, int a[],int b[]){
    int i,j;
    int max;

    for(i=1; i<=row; i++){
        for(j=1; j<=col; j++){
            max=len[i-1][j-1];
            if(max<len[i][j-1]) max=len[i][j-1];
            if(max<len[i-1][j]) max=len[i-1][j];

            if(a[i]==b[j]){
                len[i][j]=max+1;
            }else{
                len[i][j]=max;
            }
        }
    }
    return len[row][col];
}
int main(){
    freopen("1045.txt","r",stdin);

    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[m+1];

    for(int i=0; i<m; i++){
        cin>>a[i+1];

    }
    
    int l;
    cin>>l;
    int b[l+1];

    for(int i=0; i<l; i++){
        cin>>b[i+1];
    }

    cout<<LCS(m,l,a,b)<<endl;
}
