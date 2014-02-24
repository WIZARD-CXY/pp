/*************************************************************************
	> File Name: 1038.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 24 Feb 2014 06:16:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

bool cmp(const string &s1, const string &s2){
    return (s1+s2) < (s2+s1);
}

int main(){
#ifdef d
    freopen("1038.txt","r",stdin);
#endif
    int n;

    cin>>n;

    vector<string> vec;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        vec.push_back(s);
    }

    sort(vec.begin(),vec.end(),cmp);

    string res("");

    for(int i=0; i<n; i++){
        res+=vec[i];
    }

    int ix=0;

    while(res[ix]=='0'){
        ix++;
    }
    
    if(res.substr(ix).size()){
        cout<<res.substr(ix)<<endl;
    } else {
        cout<<0<<endl;
    }
}

