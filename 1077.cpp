/*************************************************************************
	> File Name: 1077.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Nov 2014 11:32:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<string>

int main(){
    freopen("1077.txt","r",stdin);
    int n;
    cin>>n;
    getchar();
    string s;
    vector<string> svec;
    vector<char> res;

    int minlength=257;

    for(int i=0; i<n; i++){
        getline(cin,s);
        svec.push_back(s);
        if(minlength > s.size()){
            minlength=s.size();
        }
    }
    
    int j;
    bool flag=true;

    for(j=0; j<minlength; j++){
        for(int i=0; i < n-1; i++){
            if(svec[i][svec[i].size()-j-1] != svec[i+1][svec[i+1].size()-j-1]){
                flag=false;
                break;
            } 
        }
        if(flag==false){
            break;
        }else{
            res.push_back(svec[0][svec[0].size()-j-1]);
            
        }
        
    }
    if(j==0 && !flag ){
        cout<<"nai";
        
    }else {
        for(int i=res.size()-1; i>=0; i--){
            cout<<res[i];
        }
    }
    cout<<endl;
}
