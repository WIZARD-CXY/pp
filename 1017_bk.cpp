#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct window
{
    int baseTime;
    bool operator<(const window& a)const
    {
        return baseTime>a.baseTime;
    }
};

struct customer
{
    int starttime;
    int last;
    bool operator<(const customer& a)const
    {
        return starttime>a.starttime;
    }
};
//min-heap
priority_queue<window> bank;
priority_queue<customer> cu;

int main()
{
//    freopen("1017.txt","r",stdin);

    int n,k,i;
    cin>>n>>k;
    
    for(i=0;i<k;i++)
    {
        window w;
        w.baseTime=8*3600;
    
        bank.push(w);
    }
    for(i=0;i<n;i++)
    {
        customer cust;
        int hh,mm,ss;
        cin>>hh;
        getchar();
        cin>>mm;
        getchar();
        cin>>ss;
        int last;
        cin>>last;
        cust.starttime=3600*hh+60*mm+ss;
        cust.last=last*60;
        cu.push(cust);
    }


    int c=0;
    double total=0;
    while(!cu.empty())
    {
        customer cust=cu.top();
        cu.pop();
        if(cust.starttime>=3600*17) break;
        c++;

        window w=bank.top();
        bank.pop();
        if(cust.starttime<w.baseTime)
        {
            total+=(w.baseTime-cust.starttime);
            w.baseTime+=cust.last;
        }
        else  //have window but the customer not come yet  so no need to wait
        {
            w.baseTime+=cust.starttime;
        }
        bank.push(w);
    }
    printf("%.1lf",total/c/60);
    return 0;
}

