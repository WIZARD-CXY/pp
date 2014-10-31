/*************************************************************************
	> File Name: 1042.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Oct 2014 10:56:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

void print(int i){
    
    int flag=i/13;

    if(flag == 0){
        printf("S%d",i+1);
    } else if (flag == 1){
        printf("H%d",i%13+1);
    } else if(flag == 2){
        printf("C%d",i%13+1);
    } else if(flag== 3){
        printf("D%d",i%13+1);
    } else {
        printf("J%d",i%13+1);
    }
}
int main(){
    freopen("1042.txt","r",stdin);

    int n;
    cin>>n;
    int pattern[54];
    int a[54];
    int a_bk[54];

    for(int i=0; i<54; i++){
        cin>>pattern[i];
        a[i]=a_bk[i]=i;
        
    }

    while(n--){
        for(int i=0; i<54; i++){
            a[pattern[i]-1]=a_bk[i];
        }
        for(int i=0; i<54; i++){
            a_bk[i]=a[i];
        }
    }

    for(int i=0; i<53; i++){
        print(a[i]);
        cout<<" ";
    }
    print(a[53]); cout<<endl;
}
