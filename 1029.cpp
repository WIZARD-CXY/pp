/*************************************************************************
	> File Name: 1029.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Oct 2014 10:47:30 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>

using namespace std;
long int res[2000000];
long int mm[1000000];
long int nn[1000000];

int main(){
    freopen("1029.txt","r",stdin);

    int n,m;
    cin>>m;
    for(int j=0; j<m;j++){
        scanf("%ld",&mm[j]);
    }
    cin>>n;
    for(int j=0; j<n;j++){
        scanf("%ld",&nn[j]);
    }
    int ii,jj;
    int i=0;
    for(ii=0, jj=0; i<=(m+n-1)/2 && (ii < m && jj <n); i++){
        if(mm[ii]<nn[jj]){
            res[i]=mm[ii];
            ii++;
        }else{
            res[i]=nn[jj];
            jj++;
        }
    }
    if(i>(m+n-1)/2){
        printf("%ld\n",res[(m+n-1)/2]);
    } else if( i==m ){
        for(int u=i; u<=(m+n-1)/2; u++){
            res[u] = nn[jj++];
        }
        printf("%ld\n",res[(m+n-1)/2]);
    }else {
        for(int u=i; u<=(m+n-1)/2; u++){
            res[u] = mm[ii++];
        }
        printf("%ld\n",res[(m+n-1)/2]);
    }
}
