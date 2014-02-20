#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAXN 11

bool isPa(string s){
    int len=s.size();
    for(int i=0; i<len/2; i++){
        if(s[i]!=s[len-1-i]) return false;
    }
    return true;
}

int main(){
    string str;
    int k;

    cin>>str>>k;
    for(int i=0; i<k; i++){
        if(isPa(str)){
           cout<<str;
           cout<<endl<<i<<endl;
           return 0;
        }else{
           string tmp=str;
     
           reverse(str.begin(),str.end());

           int carry=0;
           string res(str);
           
           for(int i=tmp.size()-1; i>=0; i--){
                 res[i]=(tmp[i]-'0'+str[i]-'0'+carry)%10+'0';
                 carry=(tmp[i]-'0'+str[i]-'0'+carry)/10;
           }
           if(carry) res.insert(0,"1");
           
           str=res;
        }
    }
    cout<<str<<endl<<k<<endl;
}
