/*************************************************************************
	> File Name: 1046.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Nov 2014 11:31:44 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

int dis[100000+2];
int main(){
    freopen("1046.txt","r",stdin);

    int n;
    scanf("%d",&n);

    int a[n+1];
    
    int sum=0;

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        dis[i+1]=sum;
    }

    int m;

    scanf("%d", &m);

    for(int i=0; i<m; i++){
        int in,out;
        scanf("%d%d",&in,&out);

        int length;
        if(in>out){
            length=dis[in]-dis[out];
        } else {
            length=dis[out]-dis[in];
        }           

        if(length>(sum-length)){
            printf("%d\n",sum-length);
        }else{
            printf("%d\n",length);
        }
        
    }
}
