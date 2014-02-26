/*************************************************************************
	> File Name: 1033.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 26 Feb 2014 12:39:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <algorithm>

const int NUM=505;

struct station{
    double dist;
    double price;
};

station s[NUM];

bool cmp(const station &a, const station &b){
    return a.dist<b.dist;
}

int main(){
#ifdef d
    freopen("1033.txt","r",stdin);
#endif
    int i,j,n,dvag;

    int flag=1,index;

    double dest,cmax;

    cin>>cmax>>dest>>dvag>>n;

    for(int i=0; i<n; i++){
        cin>>s[i].price>>s[i].dist;
    }
    s[n].price=0;
    s[n].dist=dest;

    double step=cmax*dvag;
    double currGas=0;

    double minPrice,sum=0;
    sort(s,s+n,cmp);

    if(s[0].dist>0){
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    } else {
        for(i=0; i<n;){
            if(s[i+1].dist-s[i].dist>step){
                flag=0;
                printf("The maximum travel distance = %.2lf\n",s[i].dist+step);
                break;
            } else {
                index=i;
                minPrice=s[i].price;

                //we now have gas situation
                for(j=i+1; s[j].dist-s[i].dist<=currGas*dvag && j<=n; j++){
                    // find the cheapest gas station within the gas volumn limitation
                    if(s[j].price<minPrice){
                        minPrice=s[j].price;
                        index=j;
                    }
                }

                if(index!=i){
                    //have found it,drive directly to it
                    currGas-=(s[index].dist-s[i].dist)/dvag;
                    i=index;
                    continue;
                }

                index=i;
                //find the nearest cheaper gas station may need some gas to be filled
                for(j=i+1; s[j].dist-s[i].dist<cmax*dvag && j<=n;j++){
                    if(s[j].price<minPrice){
                        index=j;
                        break;
                    }
                }

                if(index != i){
                    sum+=((s[index].dist-s[i].dist)/dvag-currGas)*s[i].price;
                    currGas=0;
                    i=index;//drive to the index-th station
                    continue;
                }

                //for situation that even with full tank gas ,we can not find a cheaper gas station
                //so only to fill full here
                index=i;
                minPrice=0x7fffffff;

                for(j=i+1;s[j].dist-s[i].dist<=step && j<=n; j++){
                    if(s[j].price<minPrice){
                        index=j;
                        minPrice=s[j].price;
                    }
                }

                sum+=(cmax-currGas)*s[i].price;

                currGas=cmax-(s[index].dist-s[i].dist)/dvag;
                i=index;
            }
        }
    }
    if(flag==1){
        printf("%.2lf\n",sum);
    }
}











