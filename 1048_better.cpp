/*************************************************************************
	> File Name: 1048.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Nov 2014 06:41:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
int a[100005];

int main(){
    freopen("1048.txt","r",stdin);

    int n,m;
    scanf("%d%d",&n,&m);
 

    for(int i=0; i<n; i++){
        
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    
    if(a[0]>=m){
        printf("No Solution\n");
        return 0;
    }

    int i=0;
    int j=n-1;
    while(i<j) {
        if(a[i]+a[j]>m){
            j--;
        } else if( a[i]+a[j] <m ){
            i++;
        }else {
            break;
        }

    }
    if(i<j){
        printf("%d %d\n",a[i],a[j]);
    }else{
        printf("No Solution\n");
    }
}
