/*************************************************************************
	> File Name: 1059.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Nov 2014 09:26:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cmath>

bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    long int n;
    freopen("1059.txt","r",stdin);

    scanf("%ld", &n);
    printf("%ld=",n);

    if(n==1){
        printf("%ld",n);
    }else {
        int i,temp=n;
        
        for(int i=2; i<=temp; i++){
            int cnt=0;

            if(isPrime(i)){
                while((n%i)==0){
                    n/=i;
                    cnt++;
                }
            }
            if(cnt>1){
                printf("%d^%d",i,cnt);
            
            }else if(cnt==1){
                printf("%d",i);
            }

            if(cnt>=1 && n!=1){
                printf("*");
            }
            if(n==1) {
                break;
            }
        }
    }
    printf("\n");
}
