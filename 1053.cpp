/*************************************************************************
	> File Name: 1053.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 24 Feb 2014 10:47:45 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <algorithm>
#include <cstdio>
#include <vector>
int n,m,s;
vector<int> path;
vector<int> edge[101];
bool vis[101];
int weight[101];

bool dfs(int curweight,int curnode){
    curweight+=weight[curnode];
    vis[curnode]=1;

    if(curweight>s){
        return false;
    }

    if(edge[curnode].size()==0 && curweight==s)//leaf node found and it is a solution
    {
        path.push_back(weight[curnode]);
        cout<<path[0];
        for(int i=1; i<path.size(); i++){
            cout<<" "<<path[i];
        }
        cout<<endl;
        path.pop_back();

    } else if(curweight <s && edge[curnode].size() >0){
        
        int max_w,max_id;

        path.push_back(weight[curnode]);
        do{
            max_w=-1;
            max_id=-1;
            for(int i=0; i<edge[curnode].size(); i++){
                if(!vis[edge[curnode][i]] && weight[edge[curnode][i]]>max_w){
                    max_w=weight[edge[curnode][i]];
                    max_id=edge[curnode][i];
                }
            }

            if(max_id!=-1){
                //handle the max weight node that is not visited before
                dfs(curweight,max_id);
            }
        } while(max_id!=-1);
        path.pop_back();
    }
    return true;
}


int main(){

#ifdef d
    freopen("1053.txt","r",stdin);

#endif
    cin>>n>>m>>s;


    for(int i=0; i<n; i++){
        cin>>weight[i];
    }


    for(int i=0; i<m; i++){
        int node,k;
        cin>>node>>k;
        for(int j=0; j<k; j++){
            int tmpnode;
            cin>>tmpnode;

            edge[node].push_back(tmpnode);
        }
    }
    dfs(0,0);
}
