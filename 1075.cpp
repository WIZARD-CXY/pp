/*************************************************************************
	> File Name: 1075.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Nov 2014 12:31:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#define MAX 10005
#include<algorithm>

struct rec{
    int id;
    int gradesum;
    int score[6];// record the ith problem score
    int solved;// record the num of fully solved problem
    bool flag; //indicate if he is submitted valid solution
};

bool cmp(const rec &a, const rec &b){
    if(a.gradesum> b.gradesum){
        return true;
    } else if( a.gradesum == b.gradesum ){
        if(a.solved > b.solved ){
            return true;
        } else if( a.solved == b.solved ){
            return a.id<b.id;
        }else {
            return false;
        }
    }else{
        return false;
    }
}

rec user[MAX];

int p[6];

int main(){
    freopen("1075.txt","r",stdin);

    int n,k,m;
    scanf("%d%d%d",&n, &k, &m);

    for(int i=1; i<=k; i++){
        scanf("%d",&p[i]);
    }
    for(int i=1; i<=n; i++){
        user[i].id=i;
        user[i].flag=false;
        for(int j=1; j<=k; j++){
            user[i].score[j]=-2;
        }
        user[i].solved=0;
    }

    for(int i=0; i<m; i++){
        int uid,proid,score;
        scanf("%d%d%d",&uid,&proid,&score);
        if(score >=0){
            user[uid].flag=true;

            if(score > user[uid].score[proid]){
                user[uid].score[proid]=score;

                if(score == p[proid]){
                    user[uid].solved++;
                }
            }
        }else if(score == -1){
            user[uid].score[proid]=score;
        }
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++ ){
            if(user[i].score[j]>=0){
                user[i].gradesum+=user[i].score[j];
            }
        }
    }

    sort(user+1,user+1+n,cmp);
    
    printf("1 %05d %d",user[1].id,user[1].gradesum);

    for(int i=1; i<=k; i++){
        if(user[1].score[i]>=0){
            printf(" %d",user[1].score[i]);
        }else if(user[1].score[i] == -1){
            printf(" 0");
        }else {
            printf(" -");
        }
    }

    printf("\n");

    int idx;
    int len;
    if(n>1 && user[1].gradesum == user[2].gradesum){
        idx=1;
        len=2;
    }else{
        idx=2;
        len=1;
    }

    for(int i=2; i<=n; i++){
        if(user[i].flag == false) continue;

        if(user[i].gradesum == user[i-1].gradesum){
            printf("%d %05d %d",idx, user[i].id,user[i].gradesum);

            for(int j=1; j<=k; j++){
                if(user[i].score[j]>=0){
                    printf(" %d",user[i].score[j]);
                }else if(user[i].score[j] == -1){
                    printf(" 0");
                }else {
                    printf(" -");
                }
            }
            if(i!=2)
       		    len++;
        } else {
            if(i!=2)
              idx+=len;
            len=1;
            printf("%d %05d %d",idx, user[i].id, user[i].gradesum);

            for(int j=1; j<=k; j++){
                if(user[i].score[j]>=0){
                    printf(" %d",user[i].score[j]);
                }else if(user[i].score[j] == -1){
                    printf(" 0");
                }else {
                    printf(" -");
                }
            }
           
 
        }
        printf("\n");
    }
}
