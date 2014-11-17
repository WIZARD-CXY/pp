/*************************************************************************
	> File Name: 1067.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Nov 2014 09:27:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

int findNotOk(int *arr, int begin, int end){
    for(int i=begin; i<end; i++){
        if(arr[i]!=i) return i;
    }
    return 0;
}

int main(){
    freopen("1067.txt","r",stdin);

    int n;
    scanf("%d",&n);

    int a[n];

    int t;
    for(int i=0; i<n; i++){
        scanf("%d",&t);
        a[t]=i; //number t in i-th position
    }

    int tmp=0;
    int count=0;
    int firstPos=1;
    firstPos=findNotOk(a,firstPos,n);

    while(firstPos){
        //there exist not in position number

        if(a[0]==0){
            // 0 is in position ,swap with fistpos
            a[0]=a[firstPos];
            a[firstPos]=0;
            count++;
        }

        while(a[0]!=0){
            //if 0 is not in pos, swap with the a[0]
            tmp=a[0];
            a[0]=a[tmp];
            a[tmp]=tmp;
            count++;
        }

        firstPos=findNotOk(a,firstPos,n);// 0 is in position find next not in pos number
    }
    printf("%d\n",count);
}
