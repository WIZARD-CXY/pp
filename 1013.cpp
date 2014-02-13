/*************************************************************************
	> File Name: 1013.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Thu 13 Feb 2014 04:13:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 1000

int w[MAXN][MAXN];
int vis[MAXN];
int N,M,K;
int dfs(int src){
    vis[src]=1;
    for(int i=1; i<=N; i++){
        if(!vis[i] && w[src][i]){
            dfs(i);
        }
    }
}


int main(){
    cin>>N>>M>>K;

    for(int i=0; i<M; i++){
        int v1,v2;
        cin>>v1>>v2;
        w[v1][v2]=1;
        w[v2][v1]=1;
    }

    int concern;
    for(int i=0; i<K; i++){
        memset(vis,0,sizeof(vis));

        cin>>concern;
        vis[concern]=1;
        
        int sum=0;
        for(int i=1; i<=N; i++){
            if(!vis[i]){
                dfs(i);
                sum++;
            }
        }
        cout<<sum-1<<endl;
    }
}
