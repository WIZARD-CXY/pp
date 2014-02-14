#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

#define MAX 1001

int n,m,k,q;

int processTime[MAX];
queue<int> que[20+1];

int leaveTime[MAX];//record every customer's leaving time
int Timebase[21];

int main(){

#ifdef D
    freopen("1014.txt","r",stdin);
#endif
    cin>>n>>m>>k>>q;

    for(int i=0; i<k; i++){
        cin>>processTime[i];
    }

    int index;
    int top=0;

    for(int i=0; top<m*n && top<k; top++){
     // i means i-th window Timebase[i] means after pushing top-th customer to i-th window,the finish time of window i
        que[i].push(top);
        leaveTime[top]=Timebase[i]+processTime[top];
        Timebase[i]=leaveTime[top];
        i=(i+1)%n;
    }

    // if customer is larger than the m*n
    for(;top<k;top++){
        //find earliest leave customer
        int min_wait=0x7fffffff;
        int found = 0;
        
        //n is #window
        for(int j=0; j<n; j++){
            int customer = que[j].front();
            
            if(min_wait > leaveTime[customer]){
                min_wait=leaveTime[customer];
                index=j;
                found=true;
            }
        }

        que[index].pop();
        que[index].push(top);
        leaveTime[top]=Timebase[index]+processTime[top];
        Timebase[index]=leaveTime[top];
    }

    while(q--){
        int qq;
        cin>>qq;

        qq--;

        if(leaveTime[qq]-processTime[qq]>=9*60){
            cout<<"Sorry"<<endl;
        }

        else{
            int hour = leaveTime[qq]/60;
            int min = leaveTime[qq]%60;
            printf("%02d:%02d\n",8+hour,min);
        }
    }
}



