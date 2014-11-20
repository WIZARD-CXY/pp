/*************************************************************************
	> File Name: 1078.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Nov 2014 01:23:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cmath>

int A[10000];

bool isPrime(int n){
    if( n==0 || n==1 ){
        return false;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("1078.txt","r",stdin);

    int m,n;
    cin>>m>>n;
    if(!isPrime(m)){
        for(int i=m+1; ;i++){
            if(isPrime(i)){
                m=i;
                break;
            }
        }
    }
    int temp;
    for(int i=0; i<n; i++){
        scanf("%d",&temp);
        int j;
        for(j=0; j<m; j++){
            if(A[(temp+j*j)%m]==0){
                A[(temp+j*j)%m]=1;
                if(i==0){
                    printf("%d",(temp+j*j)%m);

                }else{
                    printf(" %d",(temp+j*j)%m);
                }
                break;
            }
        }
        if(j==m){
            if(i==0){
                printf("-");
            }else{
                printf(" -");
            }
        }
    }
}
