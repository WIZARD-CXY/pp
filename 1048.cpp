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
bool vis[10005];

int binarySearch(int l, int r, int v){
    while(l<r){
        int mid=(l+r)/2;

        if(a[mid]==v && vis[mid]==0){
            return mid;
        } else if( a[mid]>v ){
            r=mid;
        }else {
            l=mid+1;
        }
    }
    return -1;
}

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
    for(i=0; i<n; i++){
        vis[i]=1;
        if(binarySearch(0,n,m-a[i]) != -1){
            printf("%d %d\n",a[i],m-a[i]);
            return 0;
        }
        vis[i]=0;

    }
    if(i==n){
        printf("No Solution\n");
    }
}
