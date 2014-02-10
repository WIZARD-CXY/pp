/*************************************************************************
	> File Name: 1004_dfs.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 10 Feb 2014 07:05:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstring>
#include <memory>

int tree[101][101];
int maxlevel;

void travel(int root,int level){
    if(level > maxlevel){
        maxlevel =level;
    }

    if(tree[root][0]==0){
        tree[0][level]++;
    } else {
        for(int i=1; i<101; i++){
            if(tree[root][i]==1){
                travel(i,level+1);
            }
        }
    }
}

int main(){

    int total,nonleave;

    int parent,child,childnum;

    cin>>total>>nonleave;

    for(int i=0; i<nonleave; i++){
        cin>>parent>>childnum;
        for(int j=0; j<childnum; j++){
            cin>>child;
            tree[parent][child]=1;
            tree[parent][0]++;

        }
    }

    travel(1,0);

    for(int i=0; i<=maxlevel;i++)
    {
        cout<<tree[0][i];
        if(i != maxlevel){
            cout<<" ";
        }
    }
}


