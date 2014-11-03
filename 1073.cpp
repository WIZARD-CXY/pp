/*************************************************************************
	> File Name: 1073.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Nov 2014 08:23:39 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<sstream>

using namespace std;

int main(){
    freopen("1073.txt","r",stdin);
    string s;
    cin>>s;
    stringstream ss;

    if(s[0]=='-'){
        cout<<"-";
    }

    int exp;//absolute value
    int coff;//absolute value

    size_t found = s.find("E");

    string coffS = s.substr(1,found-1);
    string expS = s.substr(found+1);

    if(expS[0]=='-'){

        ss<<expS.substr(1);
        ss>>exp;
        cout<<"0.";
        for(int i=0; i<exp-1;i++){
            cout<<"0";

        }
        for(int i=0; i<coffS.size(); i++){
            if(coffS[i]!='.'){
                cout<<coffS[i];
            }
        }
    }else{
        ss<<expS.substr(1);
        ss>>exp;

        cout<<coffS[0];
        int fractionlength=coffS.size()-2;

        if(exp<fractionlength){
            for(int i=0; i<exp; i++){
                cout<<coffS[i+2];
            }
            cout<<".";

            for(int i=exp+2; i< coffS.size(); i++){
                cout<<coffS[i];
            }
        }else if( exp==fractionlength ){
            for(int i=0; i<exp; i++){
                cout<<coffS[i+2];

            }
        }else{
            for(int i=2; i<coffS.size(); i++){
                cout<<coffS[i];
            }
            for(int i=0; i<(exp-fractionlength); i++){
                cout<<"0";
            }
            
        }
        

    }
    cout<<endl;
}

