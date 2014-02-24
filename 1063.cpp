/*************************************************************************
	> File Name: 1063.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sat 22 Feb 2014 08:30:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <algorithm>
#include <vector>

int main(){
#ifdef d
    freopen("1063.txt","r",stdin);
#endif

    int n,m,k;

    int x,y;
    scanf("%d",&n);

    vector<vector<int> > vecs;

    for(int i=0; i<n; i++){
        scanf("%d",&m);
        vector<int> vec;
    
        for(int j=0; j<m; j++){
            
            scanf("%d",&x);
            if(find(vec.begin(), vec.end(),x)==vec.end()){
                vec.push_back(x);
            }
        }
        sort(vec.begin(),vec.end());
        vecs.push_back(vec);
    }
    scanf("%d",&k);

    while(k--){
        scanf("%d%d",&x,&y);
        x--;
        y--;

        int nc=0;
        int nt=vecs[x].size()+vecs[y].size();


        for(int i=0,j=0; i<vecs[x].size() && j<vecs[y].size();)
        {
            if(vecs[x][i]==vecs[y][j]){
                i++;
                j++;
                nt--;
                nc++;
            } else if (vecs[x][i]>vecs[y][j]){
                j++;
            } else i++;
        }
        printf("%.1lf%%\n",nc*100.0/nt);
    }
}

