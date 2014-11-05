/*************************************************************************
	> File Name: 1076.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Nov 2014 08:31:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 1001
vector<int> G[MAX];
int vis[MAX];
int depth[MAX];
int n,l;
int cnt;
void bfs(int src){
    queue<int> qq;
    memset(vis,0,sizeof(vis));

    cnt=0;
    vis[src]=1;
    qq.push(src);
    depth[src]=0;

    while(!qq.empty()){
        int temp=qq.front();
        qq.pop();
        int size = G[temp].size();

        for(int i=0; i< size; i++){
            if(!vis[G[temp][i]]){
                depth[G[temp][i]]=depth[temp]+1;

                vis[G[temp][i]]=1;
                if(depth[G[temp][i]]<l){
                    qq.push(G[temp][i]);
                }
                cnt++;                
            }
        }
    }
}
int main(){
    freopen("1076.txt","r",stdin);

    cin>>n>>l;


    for(int i=1; i<=n; i++){
        int cnt;
        cin>>cnt;
        for(int j=0; j<cnt; j++){
            int temp;
            cin>>temp;
            G[temp].push_back(i);
        }
    }

    int querycnt;
    cin>>querycnt;

    for(int i=0; i<querycnt; i++){
        int source;
        cin>>source;
        bfs(source);
        cout<<cnt<<endl;
    }
}
