/*************************************************************************
	> File Name: 1051.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 23 Feb 2014 08:42:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <stack>
#include <cstdio>

int main(){
    int n,m,k,i,j,x;

#ifdef d
    freopen("1051.txt","r",stdin);
#endif

    scanf("%d%d%d",&m,&n,&k);

    for(i=0; i<k; i++){
        stack<int> c;
        int cur=1,fg=1;

        for(j=0; j<n; j++){
            scanf("%d",&x);

            if(fg){
                while( c.empty() || c.top()!=x){
                    c.push(cur);
                    if(c.size()>m){
                        fg=0;
                        break;
                    }
                    cur++;
                }

                if(fg && c.size()>=1 && c.top()==x){
                    c.pop();
                }
            }
        }

        if(fg==0){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}

