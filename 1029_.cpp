/*************************************************************************
	> File Name: 1029_.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Oct 2014 08:20:36 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

long int A[1000000];
long int B[1000000];
long int res[2000000];
int main()
{
    freopen("1029.txt","r",stdin);

    int m,n;

    cin>>m;
    for(int i=0; i<m; i++){
        scanf("%ld",&A[i]);
    }
    cin>>n;

    for(int i=0; i<n; i++){
        scanf("%ld",&B[i]);
    }

    int p=0,q=0,x=0;

    while(p<m || q < n){
        if(q>=n || (p<m) && (A[p]<B[q])) {
            res[x++]=A[p++];
        } else {
            res[x++]=B[q++];
        }
    }

    printf("%ld",res[(m+n-1)/2]);
}
