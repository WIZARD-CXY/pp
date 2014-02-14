/*************************************************************************
	> File Name: 1016.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Thu 13 Feb 2014 09:08:40 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct record{
    string name;
    int month,day,hour,min;
    string status;
};

int toll[24];

int cmpName(const record &a, const record &b){
    return a.name < b.name;
}
int cmptime(const record &a, const record &b){
    int atotaltime=a.day*24*60+a.hour*60+a.min;
    int btotaltime=b.day*24*60+b.hour*60+b.min;

    return atotaltime < btotaltime;
}
int main(){
    freopen("1016.txt","r",stdin);
    
    for(int i=0; i<24; i++) cin>>toll[i];

    int m;
    cin>>m;

    record records[m+1];

    for(int i=0; i<m; i++){
        cin>>records[i].name;
        scanf("%d:%d:%d:%d",&records[i].month,&records[i].day,&records[i].hour,&records[i].min);
        cin>>records[i].status;
    }

    sort(records,records+m,cmpName);

    int count[1000];//count[i] will be the ith customer's #record-1  
    int num=0;
    for(int i=1; i<m; i++){
        if(records[i].name == records[i-1].name){
            count[num]++; //the same guy
        } else num++;// the other guy
    }
    

    int prefix=0;
    for(int i=0; i<num+1; i++){

        sort(records+prefix,records+count[i]+1,cmptime);

        bool first=true; //
        double totalamount=0.0;
        for(int j=0; j<count[i];j++){
            
            if( records[prefix+j].status == "on-line" && records[prefix+j+1].status =="off-line"){
                if(first){
                    cout<<records[prefix+j].name;
                    printf(" %02d\n",records[prefix+j].month);
                    first=false;
                }


                
            }
        }
        
        prefix+=count[i]+1;
    }
}


