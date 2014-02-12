/*************************************************************************
	> File Name: 1011.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 12 Feb 2014 09:54:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
int main(){
    double max1=-1,max2=-1,max3=-1;

    double a[3];
    
    int maxIndex1=0;
    for(int j=0; j<3; j++){
        cin>>a[j];
        if(max1<a[j]){
            max1=a[j];
            maxIndex1=j;
        }
    }

    if(maxIndex1==0) cout<<"W ";
    else if(maxIndex1==1) cout<<"T ";
    else cout<<"L ";

    int maxIndex2=0;
    for(int j=0; j<3; j++){
        cin>>a[j];
        if(max2<a[j]){
            max2=a[j];
            maxIndex2=j;
        }
    }
    if(maxIndex2==0) cout<<"W ";
    else if(maxIndex2==1) cout<<"T ";
    else cout<<"L ";

    
    int maxIndex3=0;
    for(int j=0; j<3; j++){
        cin>>a[j];
        if(max3<a[j]){
            max3=a[j];
            maxIndex3=j;
        }
    }
    if(maxIndex3==0) cout<<"W ";
    else if(maxIndex3==1) cout<<"T ";
    else cout<<"L ";

    printf("%.2lf",(max1*max2*max3*0.65-1)*2);
}
