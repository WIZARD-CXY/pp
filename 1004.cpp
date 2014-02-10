/*************************************************************************
	> File Name: 1004.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 10 Feb 2014 06:03:14 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAXN 102

int main(){
    int t[MAXN][MAXN];

    int n,m;

    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>t[i][0];
        cin>>t[i][1];
        for(int j=0; j<t[i][1]; j++){
            cin>>t[i][j+2];
        }
    }

    queue<int> q;

    int tmp;

    if(n==0) return 0;

    q.push(1);
    q.push(-1);

    int count=0;

    while(!q.empty()){
        tmp=q.front();
        q.pop();
        if(tmp==-1){
            cout<<count;
            if(q.empty()) break;
            else cout<<" ";
            q.push(-1);
            count=0;
            continue;
        }

        int flag=0;

        for(int j=0; j<m;j++){
            if(t[j][0]==tmp){
                flag=1;
                for(int k=0; k<t[j][1]; k++){
                    q.push(t[j][2+k]);
                }
            }
        }

        if(flag==0){
            count++;
        }
    }
}


