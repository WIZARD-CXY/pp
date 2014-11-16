/*************************************************************************
	> File Name: 1056.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Nov 2014 08:04:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<queue>

int w[1000];
int r[1000];

int main(){
    freopen("1056.txt","r",stdin);
    int np,ng;
    scanf("%d%d",&np,&ng);

    for(int i=0; i<np; i++){
        scanf("%d",&w[i]);
    }

    queue<int> order;

    for(int i=0; i<np; i++){
        int tt;
        scanf("%d",&tt);
        order.push(tt);
    }

    while(order.size()!=1){
        int gamecnt = order.size()/ng + (order.size()%ng==0?0:1);
        int curank = gamecnt+1;//this round loser's rank

        queue<int> tmp;

        for(int i=0; i<gamecnt; i++){
            int max=-1;
            int maxIdx=-1;

            for(int j=i*ng; j<i*ng+ng && order.size()!=0; j++){
                int index=order.front();
                order.pop();
                if(w[index]>max){
                    max=w[index];
                    if(maxIdx != -1){
                        r[maxIdx]=curank;
                    }
                    maxIdx=index;
                }else{
                    r[index]=curank;
                }
            }
            tmp.push(maxIdx);
        }
        order=tmp;
    }
    r[order.front()]=1;

    printf("%d",r[0]);

    for(int i=1; i<np; i++){
        printf(" %d",r[i]);
    }
    printf("\n");

}
