/*************************************************************************
	> File Name: 1001.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月17日 星期日 15时29分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    int c = a + b;

    stringstream stringStream;
    stringStream<<c; // int to stringstream
    string s = stringStream.str();

    for(int i = s.size()-3; i > 0 && s[i-1] != '-'; i-=3)
        s.insert(i,",");

    cout<<s<<endl;
}
