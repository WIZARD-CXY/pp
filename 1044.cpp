/*************************************************************************
	> File Name: 1044.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Nov 2014 09:37:39 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100005

struct point{
    int start,end;
};
point node;
int sum[MAX];

vector<point> out;
//use this algorithm to find the minimal value above the given value
// or the value itself with log(r-l) time.
int binarySearch(int l, int r, int m, int &j){
    int i=l;
    int mid;
    
    while(l<r){
        mid=(l+r)/2;
        if(sum[mid]-sum[i-1]>=m){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    j=r;

    return sum[j]-sum[i-1];

}
int main(){
    freopen("1044.txt","r",stdin);

    int n,m;
    scanf("%d%d",&n,&m);
    
    sum[0]=0;
    for(int i=1; i<=n; i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }

    int best=-1;

    for(int i=1,j,temp; i<=n; i++){
        temp=binarySearch(i,n,m,j);

        if(best==-1 || (temp<best && temp>=m)){
            best=temp;
            out.clear();
            node.start=i;
            node.end=j;
            out.push_back(node);
        } else if(temp==best ){// not temp== m because in sample Input 2 we
        // can't get one pefect answer ,All we can get are two above answers
            node.start=i;
            node.end=j;
            out.push_back(node);
        }

    }

    int len=out.size();

    for(int i=0; i<len; i++){
        printf("%d-%d\n",out[i].start,out[i].end);
    }



}
