/*************************************************************************
	> File Name: 1058.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Nov 2014 09:12:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

int main(){
    freopen("1058.txt","r",stdin);

    int ga,sa,ka,gb,sb,kb;

    scanf("%d.%d.%d %d.%d.%d",&ga, &sa, &ka, &gb, &sb, &kb);

    int gc,sc,kc;
    int carry=0;
    int temp=ka+kb;

    if(temp>=29){
        kc=temp-29;
        carry=1;
    }else{
        kc=temp;
        carry=0;
    }

    temp=sa+sb+carry;

    if(temp>=17){
        sc=temp-17;
        carry=1;
        
    }else{
        sc=temp;
        carry=0;
    }
    
    gc=ga+gb+carry;
    printf("%d.%d.%d\n",gc,sc,kc);
}
    
