/*************************************************************************
	> File Name: 1034.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 26 Feb 2014 04:05:03 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

map<string,vector<string> > adj;
map<string,int> weight;
map<string,int> vis;
map<string,int> ans;
int cnt,totalweight;
string head;

void dfs(string str){
    vis[str]=1;

    cnt++;

    totalweight+=weight[str];

    if(weight[str]>weight[head]){
        head=str;
    } else if( weight[str]==weight[head] && str<head){
        head=str;
    }


    for(vector<string>::iterator it=adj[str].begin(); it!=adj[str].end(); it++){
        if(!vis[*it]){
            dfs(*it);
        }
    }
}


int main(){
    int n,k,time;
    string name1,name2;

#ifdef d
    freopen("1034.txt","r",stdin);
#endif

    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>name1>>name2>>time;

        weight[name1]+=time;
        weight[name2]+=time;
        adj[name1].push_back(name2);
        adj[name2].push_back(name1);
        vis[name1]=0;
        vis[name2]=0;
    }


    for(map<string,int>::iterator it=vis.begin(); it!=vis.end();it++){
        if(it->second==0){
            cnt=0;
            totalweight=0;
            head=it->first;
            dfs(it->first);
            if(cnt>2 && totalweight/2 >k){
                ans[head]=cnt;
            }
        }
    }

    cout<<ans.size()<<endl;

    for(map<string,int>::iterator it=ans.begin(); it!=ans.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }


}
