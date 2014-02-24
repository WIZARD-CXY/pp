#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>

int main(){
    string str;
    cin>>str;


    int len=str.size();
    int carry=0;
    
    string str2(str);

    for(int i=len-1; i>=0; i--){
        str2[i]=((str[i]-'0')*2+carry)%10+'0';
        carry=((str[i]-'0')*2+carry)/10;
    }
   
    sort(str.begin(),str.end());
    string str3(str2);
    sort(str2.begin(),str2.end());


    if(str==str2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(carry!=0) cout<<carry<<str3<<endl;
    else cout<<str3<<endl;
}
