/*************************************************************************
	> File Name: 1005.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 10 Feb 2014 08:37:08 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

void saydigit(int n){

    if(n==1) cout<<"one";
    else if(n==2) cout<<"two";
    else if(n==3) cout<<"three";
    else if(n==4) cout<<"four";
    else if(n==5) cout<<"five";
    else if(n==6) cout<<"six";
    else if(n==7) cout<<"seven";
    else if(n==8) cout<<"eight";
    else if(n==9) cout<<"nine";
    else if(n==0) cout<<"zero";
    else {}
}

void print(int n){
    if(n/10 != 0)
       print(n/10);
    
    if( n>=0 && n<10){
       saydigit(n%10);
    } else {
       cout<<" ";
       saydigit(n%10);
    }
}
int main(){
    string str;

    cin>>str;

    int len=str.size();

    int sum=0;

    for(int i=0; i<len;i++){
        sum+=str[i]-'0';
    }

   print(sum); 
    
}
