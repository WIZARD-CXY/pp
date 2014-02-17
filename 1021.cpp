/*************************************************************************
	> File Name: 1021.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 17 Feb 2014 03:42:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#define MAXN 10005

int vis[MAXN];
int n;

int parent[MAXN];

vector<int> ans;
int dis[MAXN];
vector<int> adj_list[MAXN];

int bfs(int x){
    queue<int> q;

    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    
    vis[x]=1;
    int maxv=0;

    q.push(x);
    
    while(!q.empty()){
        int v=q.front();
        q.pop();
        int i;

        if(dis[v]>maxv){
            maxv=dis[v];
        }

        for(i=0; i<adj_list[v].size(); i++){
            if(!vis[adj_list[v][i]] ){
                vis[adj_list[v][i]]=1;
                dis[adj_list[v][i]]=dis[v]+1;
                q.push(adj_list[v][i]);
            }
        }
    }
    return maxv;
}


int find(int x){
    return parent[x]==x?x:find(parent[x]);
}

int merge(int a,int b){
    int x=find(a);
    int y=find(b);

    if(x!=y){
        parent[y]=x;
    }
}

int main(){
    int a,b,i,sum;

#ifdef D
    freopen("1021.txt","r",stdin);
#endif
    cin>>n;

    for(i=1; i<=n; i++){
        parent[i]=i;
    }

    for(i=0; i<n-1; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        merge(a,b);
    }

    sum=0;

    for(i=1; i<=n; i++){
        if(parent[i]==i){
            sum++;
        }
    }

    if(sum>1){
        //forest
        cout<<"Error: "<<sum<<" components"<<endl;
    }else {
        //tree
        int maxv=bfs(1);
        for(i=1; i<=n; i++){
            if(dis[i]==maxv){
                ans.push_back(i);
            }
        }

        maxv=bfs(ans[0]);

        for(i=1; i<=n; i++){
            if(dis[i]==maxv){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());

        cout<<ans[0]<<endl;

        for(i=1; i<ans.size(); i++){
            if(ans[i]!=ans[i-1]){
                cout<<ans[i]<<endl;
            }
        }
    }
}
