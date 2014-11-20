/*************************************************************************
	> File Name: 1068.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Nov 2014 01:06:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>

int dp[10005][105];
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-price[i]]+price[i])
//dp[i][j] means we cam get the maximum value that do not exceed j from first i coins


int price[10005];
bool flag[10005][105];

bool cmp(const int &a, const int &b){
    return a>b;
}
int main(){
    freopen("1068.txt","r",stdin);

    int n,m;

    scanf("%d%d", &n, &m);

    for(int i=1; i <= n; i++){
        scanf("%d",&price[i]);
    }

    sort(price+1,price+1+n,cmp);

    for(int i=1;i<=n; i++){
        for(int j=1; j<=m; j++){

            if(j<price[i] || dp[i-1][j-price[i]]+price[i]<dp[i-1][j]){
                dp[i][j]=dp[i-1][j];// do not select the i-th coin
            }else{
                dp[i][j]=dp[i-1][j-price[i]]+price[i];
                flag[i][j]=true; //select the i-th coin
            }
        }

    }

    if(dp[n][m]!=m){
        printf("No Solution");
    }else{
        bool first = true;

        for(int i=n; i>=1 && m>0; i--){
            if(flag[i][m]){
                if(first){
                    printf("%d",price[i]);
                    first=false;
                } else{
                    printf(" %d",price[i]);
                }
                m-=price[i];
            }
        }
    }
    printf("\n");
}
