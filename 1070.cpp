/*************************************************************************
	> File Name: 1070.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 09 Feb 2014 09:46:23 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct mooncake{
    double price;
    double tons;
};

bool cmp(const mooncake &a, const mooncake &b){
    return (a.price/a.tons) > (b.price/b.tons);
}

int main(){
    int N,D;

    cin>>N;
    cin>>D;
    vector<mooncake> mooncakes(N);
   
    for(int i=0; i<N; i++){
        cin>>mooncakes[i].tons;

    }

    for(int i=0; i<N; i++){
        cin>>mooncakes[i].price;
    }

    sort(mooncakes.begin(),mooncakes.end(),cmp);

    double finaldemand=0.0;
    double finalprice=0.0;
    
    for(int i=0; i<mooncakes.size(); i++){
        if(finaldemand+mooncakes[i].tons<=D){
            finaldemand+=mooncakes[i].tons;
            finalprice+=mooncakes[i].price;
        } else {
            finalprice+=mooncakes[i].price*(D-finaldemand)/mooncakes[i].tons;
            finaldemand=D;
        }
    }

    printf("%.2lf\n",finalprice);
}
