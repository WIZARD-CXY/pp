/*************************************************************************
	> File Name: 1085.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Nov 2014 12:20:26 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int  main(){
    freopen("1085.txt","r",stdin);

    int n,p;
    cin>>n>>p;
    long long a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);

    int begin=0,end=0,max=0;

    while(end<n){
        long long temp=a[begin]*p;
        while(end<n && a[end]<=temp){
            end++;
        }
        if(end-begin>max){
            max=end-begin;
        }
        begin++;
    }
    cout<<max<<endl;

}
