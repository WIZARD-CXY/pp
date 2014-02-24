/*************************************************************************
	> File Name: 1039.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 24 Feb 2014 03:06:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <algorithm>
#include <vector>

vector<int> name2course[26*26*26*10];

int main(){
#ifdef d
    freopen("1039.txt","r",stdin);
#endif
    int n,k;

    scanf("%d%d",&n,&k);

    for(int i=1; i<=k; i++){
        int coursenum,peoplenum;
        cin>>coursenum>>peoplenum;

        for(int j=0; j<peoplenum; j++){
            char name[4];
            scanf("%s",name);
            int index=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
            name2course[index].push_back(coursenum);
        }
    }

    for(int i=0; i<n; i++){
        char name[4];
        scanf("%s",name);
        printf("%s",name);

        int index=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+name[3]-'0';
        printf(" %d",name2course[index].size());

        sort(name2course[index].begin(),name2course[index].end());

        for(int j=0; j<name2course[index].size(); j++){
            printf(" %d",name2course[index][j]);
        }
        printf("\n");
    }
}
