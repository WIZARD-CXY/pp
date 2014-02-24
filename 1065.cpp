/*************************************************************************
	> File Name: 1065.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 23 Feb 2014 03:39:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long a,b,c,tmp;

    for(int i=1; i<=n; i++){
        cin>>a>>b>>c;
        tmp=a+b;

        if(a<0 && b<0 && tmp >= 0){
            cout<<"Case #"<<i<<": false"<<endl;
        } else if(a>0 && b>0 && tmp <=0){
            cout<<"Case #"<<i<<": true"<<endl;
        } else if( tmp > c) {
            cout<<"Case #"<<i<<": true"<<endl;
        } else {
            cout<<"Case #"<<i<<": false"<<endl;
        }
    }
}
