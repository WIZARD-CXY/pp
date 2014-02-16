/*************************************************************************
	> File Name: 1019.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Fri 14 Feb 2014 07:50:08 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <cstring>

int main(){
    int n;
    int radix;
    
    cin>>n>>radix;

    string res;

    int i=0;

    if(n==0){
        cout<<"Yes"<<endl<<0;
        return 0;
    }

    while(n){
        res[i++]=n%radix+'0';
        n/=radix;
    }
    
    int j,k;
    bool flag=1;

    for(j=0,k=i-1; j<k; j++,k--){
        if(res[j]!=res[k]){
            flag=0;
            break;
        }
    }

    if(flag){cout<<"Yes"<<endl;}
    else cout<<"No"<<endl;

    for(int j=i-1; j>=0; j--){
        cout<<res[j];
        if(j!=0){
            cout<<" ";
        }
    }
}
