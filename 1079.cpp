/*************************************************************************
	> File Name: 1079.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Nov 2014 06:29:53 PM CST
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100005
vector<int> G[MAX];
int productnum[MAX];

double dfs(int node, double p, double r){
    double myPrice;
    if(node==0){
        myPrice = p;
    }
    else{
        myPrice=(1.0+r/100.0)*p;
    }

    if(G[node].empty()){
        // reach the retailer node
        return productnum[node]*myPrice;
    }
    
    double ret=0.0;
    for(int i=0; i<G[node].size(); i++){
        ret+=dfs(G[node][i],myPrice,r);
    }
    return ret; 
} 
int main(){
    freopen("1079.txt","r",stdin);
    int n;
    double p,r;

    cin>>n>>p>>r;

    for(int i=0; i<n; i++){
        int cnt;

        cin>>cnt;
        if(cnt==0){
            cin>>productnum[i];
        } else {
            for(int j=0; j<cnt; j++){
                int v;
                cin>>v;
                G[i].push_back(v);
            }
        }
    }
    printf("%.1lf\n",dfs(0,p,r));
}
