#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    string str;
    cin>>str;

    int len=str.size();
    int n1,n2,n3;
   
    for(n2=3; n2<=len; n2++){
         int tmp=len+2-n2;
         if(tmp%2!=0) continue;
         else {
            n1=n3=tmp/2;
         }
         if(n1<=n2) break;
    }
    // line on line output
    for(int i=0; i<n1; i++){
      if(i!=n1-1){
        cout<<str[i];
        for(int j=0; j<n2-2; j++){
           cout<<" ";
        }
        cout<<str[len-1-i]<<endl;
      }else {
        for(int k=n1-1; k<n1+n2-1;k++){
        cout<<str[k];
      }
    }
}
}
