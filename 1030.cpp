/*************************************************************************
	> File Name: 1030.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Oct 2014 09:51:49 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int w[505][505];
int vis[505];
int dis[505];
int cost[505];
int cos[505][505];
int pre[505];

void dijk(int n, int src, int dst){
    
    for(int i=0; i<n; i++){
        dis[i]=w[src][i];
        cost[i]=cos[src][i];
        pre[i]=src;
    }

    dis[src]=0;
    cost[src]=0;

    for(int i=0; i<n; i++){
        int min=0x7fffffff;
        int minIdx=-1;

        for (int j=0; j<n; j++){
            if(!vis[j] && dis[j]<min){
                min=dis[j];
                minIdx=j;
            }
        }
        
        if(min == 0x7fffffff || minIdx == dst) return;

        vis[minIdx]=1;

        //relax
        for(int j=0; j<n; j++){
            if(!vis[j] && w[j][minIdx]< 0x7fffffff){
                int temp = dis[minIdx]+w[minIdx][j];
                
                if(temp < dis[j]){
                    dis[j]= temp;
                    pre[j]= minIdx;
                    cost[j]=cost[minIdx]+cos[minIdx][j];

                }else if(temp == dis[j]){
                    if(cost[j] > cost[minIdx]+cos[minIdx][j]){
                        pre[j]=minIdx;
                        cost[j]=cost[minIdx]+cos[minIdx][j];
                    }
                    
                }
                else{}
            }
        }

    }
    
}

void printpath(int src,int dst){
    if (pre[dst] != src){
        printpath(src, pre[dst]);

    }
    cout<<pre[dst]<<" ";
}
int main(){
    freopen("1030.txt","r",stdin);

    int n,m,s,d;

    cin>>n>>m>>s>>d;

    
    for(int i=0; i<n; i++){
        pre[i]=-1;
        dis[i]=0x7fffffff;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                w[i][j]=0x7fffffff;
                cos[i][j]=0x7fffffff;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        int v1,v2,distance,cost;
        cin>>v1>>v2>>distance>>cost;

        w[v1][v2]=w[v2][v1]=distance;
        cos[v1][v2]=cos[v2][v1]=cost;
    }

    dijk(n, s, d);
    printpath(s,d);
    cout<<d<<" "<<dis[d]<<" "<<cost[d]<<endl;
}
