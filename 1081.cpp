/*************************************************************************
	> File Name: 1081.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Nov 2014 08:57:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

long long gcd(long long a, long long b){
    return b==0?a:gcd(b,a%b);
}

long long lcm(long long a, long long b){
    return a/gcd(a,b)*b;
}

long long no[100],de[100];

int main(){
    freopen("1081.txt","r",stdin);

    int n;
    scanf("%d",&n);

    long long commondeno=1;

    for(int i=0; i<n; i++){
        long long nomi,deno;
        scanf("%lld/%lld",&no[i],&de[i]);

        commondeno=lcm(de[i],commondeno);

    }

    long long finalnominator=0;

    for(int i=0; i<n; i++){
        finalnominator+=commondeno/de[i]*no[i];
    }

    long long prefix = finalnominator/commondeno;

    long long finalnominator2 = finalnominator - prefix*commondeno;

    long long t = gcd(finalnominator2,commondeno);

    finalnominator2/=t;
    commondeno/=t;

    if( prefix ==0 && finalnominator2==0 ){
        printf("0\n");
    } else if (prefix == 0 && finalnominator2!=0){
        printf("%lld/%lld\n",finalnominator2,commondeno);
    }else if (prefix!=0 && finalnominator2==0){
        printf("%lld\n",prefix);
    }else{
        printf("%lld %lld/%lld\n",prefix,finalnominator2,commondeno);
    }
}
