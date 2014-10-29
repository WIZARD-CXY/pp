/*************************************************************************
	> File Name: 1037.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Oct 2014 11:56:06 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdio>

int a[100000];
int b[100000];
int main(){
    freopen("1037.txt","r",stdin);

    int nc;
    cin>>nc;
    for(int i=0; i<nc; i++){
        cin>>a[i];
    }
    
    int np;
    cin>>np;
    for (int i=0; i<np; i++){
        cin>>b[i];
    }

    sort(a,a+nc);
    sort(b,b+np);
    int sum=0;

    for(int i=0; i<nc && i<np; i++){
        if(a[i]<0 && b[i]<0){
            sum+=a[i]*b[i];
        }
        else{
            break;
        }
    }

    if(nc>np){
        //coupon is more
        for(int i=nc-1; i>=(nc-np); i--){
            if(a[i]>0 && b[i-(nc-np)]>0){
                sum+=a[i]*b[i-(nc-np)];
            }else break;
        }
    }else {
        //products is more or equal to coupon
        for (int i=np-1; i>=(np-nc); i--){
            if(b[i] > 0 && a[i-(np-nc)]>0){
                sum+=b[i]*a[i-(np-nc)];
            }else break;
        }
    }
    cout<<sum<<endl;

}
