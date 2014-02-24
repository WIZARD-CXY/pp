/*************************************************************************
	> File Name: 1041.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 24 Feb 2014 02:01:07 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
int c[10001];
int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
        c[a[i]]++;
    }

    for(int i=0; i<n; i++){
        if(c[a[i]]==1){
            cout<<a[i]<<endl;
            return 0;
        }
    }

    cout<<"None"<<endl;

}


