/*************************************************************************
	> File Name: 1072.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 10 Feb 2014 10:26:22 AM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
using namespace std;
#define MAX 1015
#define INT_MAX 0x7fffffff
#include <cstdio>

int w[MAX][MAX],dist[MAX];
bool vis[MAX];
int n,m,k,d;

void dijk(int start){

    for(int i=0; i<=n+m; i++){
        dist[i]=INT_MAX;
        vis[i]=0;
    }
    
    dist[start]=0;

    while(1){
        int min=INT_MAX;
        int min_idx=-1;

        for(int i=1; i<=n+m; i++){
            if(!vis[i] && dist[i] <min){
                min=dist[i];
                min_idx=i;
            }
        }

        if(min_idx == -1) break;

        vis[min_idx]=1;

        for(int i=1; i<=m+n; i++){
            if(w[min_idx][i] < INT_MAX && !vis[i]){
                if(dist[i] > (dist[min_idx]+w[min_idx][i])){
                    dist[i]=dist[min_idx]+w[min_idx][i];
                }
            }
        }
    }
}

int getInt(string str){

    stringstream stringStream;
    int num;

    if(str[0] == 'G'){
        stringStream<<str.substr(1,str.size()-1);
        stringStream>>num;
        num+=n;
    } else {
        stringStream<<str;
        stringStream>>num;
    }
    return num;
}

int main(){

    int gas_station=-1;
    freopen("1072.txt","r",stdin);

    cin>>n>>m>>k>>d; //d is max serve range

    for(int i=1; i<=n+m; i++){
        for(int j=1; j<=n+m; j++){
            w[i][j]=INT_MAX;
        }
    }

    for(int i=1; i<=k; i++){
        string str1,str2;
        int weight;
        cin>>str1>>str2>>weight;

        int v1=getInt(str1);
        int v2=getInt(str2);

        w[v1][v2]=w[v2][v1]=weight;
    }

    int ret_sum=-1;
    int ret_min=-1;

    for(int i=n+1; i<=n+m; i++){
        dijk(i);

        int min=INT_MAX;
        int sum=0;

        for(int j=1; j<=n; j++){
            sum+=dist[j];

            if(dist[j]>d){
                sum=0;
                break;
            }

            if(dist[j]<min){
                min=dist[j];
            }
        }

        if(sum !=0 && ((min>ret_min) || (min==ret_min && sum<ret_sum))){
            ret_sum=sum;
            ret_min=min;
            gas_station=i-n;
        }
    }

    if(gas_station != -1){
        printf("G%d\n%.1lf %.1lf\n",gas_station,ret_min*1.0,ret_sum*1.0/(n*1.0)+1e-10);
    } else {
        printf("No Solution\n");
    }
}

