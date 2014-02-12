/*************************************************************************
	> File Name: 1069.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sat 08 Feb 2014 05:06:47 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;
stringstream stringStream;

// convert any n to 4-digit string
string int2string(int n){
    stringStream.str("");
    stringStream.clear();

    if(n>=0 && n<10){
        stringStream<<"000"<<n;
        return stringStream.str();
    }

    else if(n<100){
        stringStream<<"00"<<n;
        return stringStream.str();
    }
    else if(n<1000){
        stringStream<<"0"<<n;
        return stringStream.str();
    }
    else {
        stringStream<<n;
        return stringStream.str();
    }
}

string getNextNumber(string str){
    
    sort(str.begin(),str.end());
    string smallstr=str;

    for(int i=0; i<str.size()/2; i++){
        char temp;
        temp = str[i];
        str[i]=str[str.size()-1-i];
        str[str.size()-1-i]=temp;
    }

    s

    int bign;
    stringStream<<str;
    stringStream>>bign;

    stringStream.str("");
    stringStream.clear();
    
    int smalln;
    stringStream<<smallstr;
    stringStream>>smalln;

    cout<<str<<" - "<<smallstr<<" = ";
    printf("%04d\n",bign-smalln);

    return int2string(bign-smalln);

}

int main(){
    int N;

    cin>>N;

    string str = int2string(N);
    int length=str.size();

    int count=0;
    for(int i=0; i<length-1; i++){
        if( str[i] == str[i+1] ){
            count++;
        }
    }

    if(count == (length-1)){
        cout<<str<<" - "<<str<<" = 0000"<<endl;
        return 0;
    }

    string result = getNextNumber(str);

    while( result != "6174"){
        result=getNextNumber(result);
    }
}
