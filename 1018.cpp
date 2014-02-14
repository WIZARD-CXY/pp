/*************************************************************************
	> File Name: 1018.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Fri 14 Feb 2014 05:28:20 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <memory>
#include <cstring>

using namespace std;

#define MAXV 501

int mindis=0x7fffffff;
int mincarry=0x7fffffff;
int minback;

vector<int> minpath;

int status[MAXV];
int use[MAXV];
int w[MAXV][MAXV];

vector<int> path;
int curdis=0;

int capacity;
int station;
int target;
int road;

void dfs(int node, int target){
    
    if(node == target){
        for(int i=0; i<path.size()-1; i++)
            curdis+=w[path[i]][path[i+1]];//record the path's length

        int tmpstatus[MAXV];

        memset(tmpstatus,0,sizeof(tmpstatus));

        for(int i=1; i<path.size(); i++){
            tmpstatus[path[i]]=status[path[i]]-capacity/2;
        }

        int carry=0;//the number of bike which will be sent from pbmc
        int collect=0;// the number of additional bike collected from the node along the path

        int tmp;

        if(curdis <= mindis){
            for(int i=1; i<path.size(); i++){
                tmp=collect+tmpstatus[path[i]];
                if(tmp<0){
                    carry-=tmp;
                    collect=0;
                }
                else if (tmp>=0)
                {
                    collect=tmp;
                }
            }
        }

        if(curdis < mindis){
            mindis=curdis;
            mincarry=carry;
            minback=collect;
            minpath=path;
        }
        else if(curdis ==mindis){
            if(carry < mincarry){
                mincarry=carry;
                minback=collect;
                minpath=path;
            } else if(carry==mincarry && collect <minback){
                mincarry=carry;
                minback=collect;
                minpath=path;
            }
        }

        curdis=0;
    }
    else {
        for(int v=0;v<MAXV;v++){
            if(w[node][v]){
                if(use[v]==false){
                    path.push_back(v);
                    use[v]=1;
                    dfs(v,target);
                    use[v]=0;
                    path.pop_back();
                }
            }
        }
    }
}
int main(){

    int x,y;

    int time;
    cin>>capacity>>station>>target>>road;

    memset(status,0,sizeof(status));
    //status[i] means the i-th station's current #bike

    for(int i=1; i<=station; i++){
        cin>>status[i];
    }

    memset(w,0,sizeof(w));

    for(int i=0; i<road; i++){
        cin>>x>>y>>time;
        w[x][y]=w[y][x]=time;
    }

    path.push_back(0);
    use[0]=1;
    dfs(0,target);
    
    cout<<mincarry<<" ";

    for(int i=0; i<minpath.size(); i++)
    {
        cout<<minpath[i];
        if(i!=(minpath.size()-1)){
            cout<<"->";
        }
    }
    cout<<" "<<minback<<endl;
}

