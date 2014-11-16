/*************************************************************************
	> File Name: 1055.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Nov 2014 11:24:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

struct rec{
    char name[9];
    int age;
    int networth;
};

bool cmp2(const rec &a, const rec &b){
    if( a.networth> b.networth ){
        return true;
    } else if( a.networth == b.networth  ){
        if( a.age < b.age ){
            return true;
        }
        else if (a.age == b.age){
            return strcmp(a.name,b.name) < 0;
        }else {
            return false;
        }

    }else {
        return false;
    }
}
int agecount[201]; //agecount[i] indicates people's total num whose age is i


int main(){
    freopen("1055.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);

    vector<rec> records(n);

    for(int i=0; i<n; i++){
        scanf("%s%d%d",records[i].name, &records[i].age, &records[i].networth);
    }

    sort(records.begin(), records.end(), cmp2);

    int filtered_num = 0;// record the filtered total people number;
    int filter[n];

    for(int i=0; i<n; i++){
        if((++agecount[records[i].age])<101){
            filter[filtered_num++]=i;
        }
    }

    for(int i=0; i<k; i++){
        int m;
        int Amin,Amax;
        scanf("%d%d%d", &m, &Amin, &Amax);
        printf("Case #%d:\n",i+1);

        int count=0;
        bool flag=true;

        for(int j=0; j<filtered_num; j++){
            int filtered_index=filter[j];
            if(records[filtered_index].age<=Amax && records[filtered_index].age >= Amin){
                printf("%s %d %d\n",records[filtered_index].name,records[filtered_index].age, records[filtered_index].networth);
                flag=false;
                count++;
                if(count>=m){
                    break;
                }
            }
        }
        if(flag){
            printf("None\n");
        }
    }
}
