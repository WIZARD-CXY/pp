/*************************************************************************
	> File Name: 1027.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Nov 2014 12:41:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>

void convert(int n, char a[]){
    //convert 10 redix to 13 radix

    int i=1;
    while(n!=0){
        int temp=n%13;
        if( 0<=temp && temp <=9){
            a[i--]=temp-0+'0';
        }else{
            a[i--]=temp-10+'A';

        }
        n/=13;
    }
}
int main(){
    
    freopen("1027.txt","r",stdin);
    int r,g,b;

    cin>>r>>g>>b;
    cout<<"#";

    char aa[2]={'0','0'};
    convert(r,aa);
    for(int i=0;i<2;i++){
        cout<<aa[i];
    }
    char bb[2]={'0','0'};
    convert(g,bb);
    for(int i=0;i<2;i++){
        cout<<bb[i];
    }
    char cc[2]={'0','0'};
    convert(b,cc);
    for(int i=0;i<2;i++){
        cout<<cc[i];
    }

}
