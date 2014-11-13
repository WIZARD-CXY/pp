/*************************************************************************
	> File Name: 1047.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Nov 2014 12:03:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("1047.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);

    vector<string> Res[2501];

    for(int i=0; i<n; i++){
        char name[5];
        int num;
        scanf("%s%d",name,&num);
        string s = string(name);

        for(int j=0; j<num; j++){
            int courseId;
            scanf("%d",&courseId);
            Res[courseId].push_back(s);
        }

    }
    for(int i=1; i<=k; i++){
        printf("%d %d\n", i, Res[i].size()); 

        sort(Res[i].begin(),Res[i].end());
            for(int j=0; j<Res[i].size(); j++){
                printf("%s\n",Res[i][j].c_str());
        }
        
    }
}
