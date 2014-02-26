#include <iostream>
#include <cstdio>
using namespace std;

bool vis[100001];
int nextaddr[100001];

int main(){
#ifdef d
    freopen("1032.txt","r",stdin);
#endif
    int s1,s2,n;
    cin>>s1>>s2>>n;

    for(int i=0; i<n; i++){
       int a,b;
       char c;
       cin>>a>>c>>b;
       nextaddr[a]=b;
    }
    // visit list which head is s1
    // and mark the corresponding node be visited
    int p=s1;
    while(p!=-1){
        vis[p]=1;
        p=nextaddr[p];
    }

    int p2=s2;
    
    while(p2!=-1 && !vis[p2]){
       p2=nextaddr[p2];
    }

    if(p2!=-1){
       printf("%05d",p2);
    } else printf("-1");
}
        
