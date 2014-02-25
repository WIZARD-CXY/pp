#include <iostream>
#include <cstdio>
using namespace std;

bool vis[100001];
int next[100001];

int main(){
    int s1,s2,n;
    cin>>s1>>s2>>n;

    for(int i=0; i<n; i++){
       int a,b;
       char c;
       cin>>a>>c>>b;
       next[a]=b;
    }
    // visit list which head is s1
    // and mark the corresponding node be visited
    int p=s1;
    while(p!=-1){
        vis[p]=1;
        p=next[p];
    }

    int p2=s2;
    
    while(p2!=-1 && !vis[p]){
       p=next[p];
    }

    if(p2!=-1){
       printf("%05d",p2);
    } else printf("-1");
}
        
