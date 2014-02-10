/*************************************************************************
	> File Name: 1006.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 10 Feb 2014 09:06:30 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>

int main(){
    int n;
    int inh,inm,ins,outh,outm,outs;

    cin>>n;

    string names[n];

    int min=0x7fffffff;
    int max=-1;
    int maxIdx=-1;
    int minIdx=-1;

    for(int i=0; i<n; i++){
        cin>>names[i];
        scanf("%d:%d:%d %d:%d:%d",&inh,&inm,&ins,&outh,&outm,&outs);
        int signintime=inh*3600+inm*60+ins;
        int signouttime=outh*3600+outm*60+outs;
        
        if(max<signouttime){
            max=signouttime;
            maxIdx=i;
        }

        if(min>signintime){
            min=signintime;
            minIdx=i;
        }
    }
    cout<<names[minIdx]<<" "<<names[maxIdx]<<endl;
}
    

