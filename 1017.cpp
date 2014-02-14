/*************************************************************************
	> File Name: 1017.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Fri 14 Feb 2014 11:00:22 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct record{
    int starttime;
    int processtime;
};
bool cmp(const record &a, const record &b){
    return a.starttime < b.starttime;
}
#define MAXN 10001
int waitTime[MAXN];

int main(){
    //freopen("1017.txt","r",stdin);

    int n,k;

    cin>>n>>k;

    record rec[n];
 
    int baseTime[k];
    
    //initial all the window in the bank
    for(int i=0 ; i<k; i++){
        baseTime[i]=8*3600;
    }

    for(int i=0; i<n; i++){
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        rec[i].starttime=3600*h+60*m+s;
        cin>>rec[i].processtime;
        rec[i].processtime*=60;
    }

    sort(rec,rec+n,cmp);

    int customercnt=0;

    while(customercnt<n){

        int minwait=0x7fffffff;
        int Idx=0;

        if(rec[customercnt].starttime>17*3600) break;

        for(int i=0; i<k; i++){
            //select the smallest basetime of the window to push the new customer
            if(baseTime[i]<minwait){
                minwait=baseTime[i];
                Idx=i;
            }
        }

        if(minwait<=rec[customercnt].starttime){
            // window is empty do not need wait
            waitTime[customercnt]=0;
            baseTime[Idx]=minwait+rec[customercnt].processtime;
        }
        else {
            // window is occupied 
            waitTime[customercnt]=minwait-rec[customercnt].starttime;
            baseTime[Idx]=minwait+rec[customercnt].processtime;
        }


        customercnt++;
    }

    int totalwaitTime=0;

    for(int i=0; i<customercnt; i++){
        totalwaitTime+=waitTime[i];
    }
    if(customercnt!=0) printf("%.1lf\n",1.0*totalwaitTime/customercnt/60);
    else cout<<"0.0"<<endl;
}
