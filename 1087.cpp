/*************************************************************************
	> File Name: 1087.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Nov 2014 10:56:22 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int w[201][201];
int vis[201];

map<string,int> name2num;
map<int,string> num2name;
int dis[201];
int happiness[201],final_happiness[201];
int pre[201];
int pre_city_cnt[201];
int road_cnt[201];
int n,k;

void dijk(int src){
    for(int i=0; i<n; i++){
        dis[i]=w[src][i];
    }

    for(int i=0; i<n; i++){
        //select the minimal dis
        int min=0x7fffffff;
        int minIdx=-1;
        for(int j=0; j<n; j++){
            if(!vis[j] && dis[j]<min){
                minIdx=j;
                min=dis[j];
            }
        }

        if(minIdx==-1){
            break;
        }

        vis[minIdx]=1;

        //relaxation
        for(int j=0; j<n; j++){
            if(!vis[j] && w[minIdx][j]<0x7fffffff){
                if(dis[j] > (dis[minIdx]+w[minIdx][j])){
                    road_cnt[j]=road_cnt[minIdx];
                    pre_city_cnt[j]=pre_city_cnt[minIdx]+1;
                    final_happiness[j]=final_happiness[minIdx]+happiness[j];
                    dis[j]=dis[minIdx]+w[minIdx][j];
                    pre[j]=minIdx;
                }else if( dis[j] == (dis[minIdx]+w[minIdx][j]) ){
                    road_cnt[j]+=road_cnt[minIdx];
                    if(final_happiness[j] < final_happiness[minIdx]+happiness[j]){
                        final_happiness[j]=final_happiness[minIdx]+happiness[j];
                        pre[j]=minIdx;
                        pre_city_cnt[j]= pre_city_cnt[minIdx]+1;
                    }else if(final_happiness[j] == final_happiness[minIdx]+happiness[j]){

                        if(pre_city_cnt[j] > pre_city_cnt[minIdx]+1){
                            pre_city_cnt[j]=pre_city_cnt[minIdx]+1;
                            pre[j]=minIdx;
                        }
                    }
                }
            }
        }

    }
}
void print(int dst,int src){
    if(pre[dst] != src){
        print(pre[dst],src);
    }
    cout<<num2name[pre[dst]]<<"->";

}

void printRes(){
    cout<<road_cnt[name2num["ROM"]]<<" "<<dis[name2num["ROM"]]<<" "<<final_happiness[name2num["ROM"]]<<" "<<final_happiness[name2num["ROM"]]/pre_city_cnt[name2num["ROM"]]<<endl;
    
    print(name2num["ROM"],0);
    cout<<"ROM"<<endl;

}
int main(){
    freopen("1087.txt","r",stdin);

    cin>>n>>k;
    string startcity;
    cin>>startcity;

    name2num[startcity]=0;
    num2name[0]=startcity;

    happiness[0]=final_happiness[0]=0;


    for(int i=1; i<n; i++){
        string city;
        cin>>city;
        name2num[city]=i;
        num2name[i]=city;
        cin>>happiness[i];
    }

    for (int i=0; i<n; i++){
        dis[i]=0x7fffffff;

        for(int j=0; j<n; j++){
            if(i!=j){
                w[i][j]=w[j][i]=0x7fffffff;
            }
        }
    }

    for(int i=0; i<k; i++){
        string city1,city2;
        int cost;

        cin>>city1>>city2>>cost;
        w[name2num[city1]][name2num[city2]]=cost;
        w[name2num[city2]][name2num[city1]]=cost;
    }

    road_cnt[0]=1;

    dijk(0); // src node is indexed by 0
    printRes();
}
