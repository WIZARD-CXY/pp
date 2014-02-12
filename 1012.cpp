/*************************************************************************
	> File Name: 1012.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 12 Feb 2014 10:24:41 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct record{
    string ID;
    int C,M,E,A;
    int Crank,Mrank,Erank,Arank;

};

bool cmpC(const record &a, const record &b){
    return a.C>b.C;
}

bool cmpM(const record &a, const record &b){
    return a.M>b.M;
}

bool cmpE(const record &a, const record &b){
    return a.E>b.E;
}

bool cmpA(const record &a, const record &b){
    return a.A>b.A;
}

int main(){
    int n,m;
#ifdef d
  freopen("1012.txt","r",stdin);
#endif
    cin>>n>>m;
    record records[n];

    for(int i=0; i<n; i++){
        cin>>records[i].ID;
        cin>>records[i].C;
        cin>>records[i].M;
        cin>>records[i].E;
        records[i].A=(records[i].C+records[i].M+records[i].E)/3;
    }
    
    sort(records,records+n,cmpA);
    int rank=1;
    for(int i=0; i<n; i++){
        if(i>0 && records[i].A ==records[i-1].A){
            
        }
        else rank=i+1; 
        records[i].Arank=rank;
    }

    sort(records,records+n,cmpC);
    rank=1;
    for(int i=0; i<n; i++){
        if(i>0 && records[i].C ==records[i-1].C){
            
        }
        else rank=i+1; 
        records[i].Crank=rank;
    }
    
    sort(records,records+n,cmpM);
    rank=1;
    for(int i=0; i<n; i++){
        if(i>0 && records[i].M ==records[i-1].M){
            
        }
        else rank=i+1; 
        records[i].Mrank=rank;
    }
    
    sort(records,records+n,cmpE);
    rank=1;
    for(int i=0; i<n; i++){
        if(i>0 && records[i].E ==records[i-1].E){
            
        }
        else rank=i+1; 
        records[i].Erank=rank;
    }
    //begin query

    string ID;
    
    for(int j=0; j<m; j++){
        cin>>ID;
        int i;
        for( i=0; i<n; i++){
            if( ID==records[i].ID){
                int BestSub=0;
                int BestRank=records[i].Arank;
                
                if(records[i].Crank<BestRank){
                    BestSub=1;
                    BestRank=records[i].Crank;
                }
                if(records[i].Mrank<BestRank){
                    BestSub=2;
                    BestRank=records[i].Mrank;
                }
                if(records[i].Erank<BestRank){
                    BestSub=3;
                    BestRank=records[i].Erank;
                }
                
                if(BestSub==0){
                    cout<<records[i].Arank<<" A"<<endl;
                }
                if(BestSub==1){
                    cout<<records[i].Crank<<" C"<<endl;
                }
                if(BestSub==2){
                    cout<<records[i].Mrank<<" M"<<endl;
                }
                if(BestSub==3){
                    cout<<records[i].Erank<<" E"<<endl;
                }
                break;
            }
        }
        if(i==n) cout<<"N/A"<<endl;
    }
    
}
