/*************************************************************************
	> File Name: 1040.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 24 Feb 2014 02:24:57 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>

int main(){
#ifdef d
    freopen("1040.txt","r",stdin);
#endif
    string str;
    getline(cin,str);

    int strlen=str.size();
    int maxlen=1;

    for(int i=0; i<strlen; i++){

        for(int j=0; i-j>=0 && i+j <strlen; j++){
            if(str[i-j]!=str[i+j]){
                break;
            }
            if(j*2+1>maxlen){
                maxlen=j*2+1;
            }
        }

        for(int j=0; i-j>=0 && i+j+1 <strlen; j++){

            if(str[i-j]!=str[i+1+j]){
                break;
            }
            
            if(j*2+2>maxlen){
                maxlen=j*2+2;
            }
        }
    }
    cout<<maxlen<<endl;
}
