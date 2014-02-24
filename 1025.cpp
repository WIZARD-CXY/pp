/*************************************************************************
	> File Name: 1025.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 24 Feb 2014 08:29:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

struct Testee{
    char id[13];
    int grade;
    int localRank;
    int globalRank;
    int localnum;
};

bool cmp(const Testee &a ,const Testee &b){
    if(a.grade>b.grade){
        return true;
    } else if (a.grade==b.grade && strcmp(a.id,b.id)<0){
        return true;
    } else return false;
}

int main(){
#ifdef d
    freopen("1025.txt","r",stdin);
#endif

    int n;
    scanf("%d",&n);

    vector<Testee> vec;
    int offset=0;

    for(int i=0; i<n; i++){
        int testeenum;
        cin>>testeenum;
        
        for(int j=0; j<testeenum; j++){
            Testee testee;
            scanf("%s%d",testee.id,&testee.grade);
            testee.localnum=i+1;
            vec.push_back(testee);
        }

        sort(vec.begin()+offset,vec.begin()+offset+testeenum,cmp);

        vec[offset].localRank=1;

        for(int j=1; j<testeenum; j++){
            if(vec[offset+j].grade==vec[offset+j-1].grade){
                vec[offset+j].localRank=vec[offset+j-1].localRank;
            } else {
                vec[offset+j].localRank=j+1;
            }
        }
        offset+=testeenum;

    }

    sort(vec.begin(),vec.end(),cmp);
    vec[0].globalRank=1;

    for(int j=1; j<vec.size(); j++){
        if(vec[j].grade==vec[j-1].grade){
            vec[j].globalRank=vec[j-1].globalRank;
        } else {
            vec[j].globalRank=j+1;
        }
    } 

    printf("%d\n",vec.size());

    for(int i=0; i<vec.size(); i++){
        printf("%s %d %d %d\n",vec[i].id,vec[i].globalRank,vec[i].localnum,vec[i].localRank);
    }
}


