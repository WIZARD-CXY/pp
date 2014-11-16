/*************************************************************************
	> File Name: 1050.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 23 Feb 2014 07:21:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#define MAXN 10000
bool isExist[MAXN];

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    for(int i=0; i<s2.size(); i++){
        isExist[s2[i]]=1;
    }

    for(int i=0; i<s1.size(); i++){
        if(!isExist[s1[i]]) printf("%c",s1[i]);
    }
}
