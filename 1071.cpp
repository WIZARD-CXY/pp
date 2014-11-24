/*************************************************************************
	> File Name: 1071.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 09 Feb 2014 09:02:30 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

void convert2lower(string &line){
    
    int len=line.size();
    for(int i=0; i<len; i++){
        line[i]=tolower(line[i]);
    }
}

pair<string,int> func(const string &line){

    map<string,int> freq;

    int p1,p2;
    p1=p2=0;

    int len=line.size();

    for(int i=0; i<=len; i++){
        
        if((i<len) && isalnum(line[i])){
            p2++;
        } else {
            if(p2>p1){
                string subs =line.substr(p1,p2-p1);
                convert2lower(subs);
                map<string,int>::iterator it=freq.find(subs);

                if(it == freq.end()){
                    freq[subs]=1;
                } else {
                    freq[subs]+=1;
                }
            }
            p1=p2=i+1;
        }
    }

    int largest=0;

    map<string,int>::iterator ptr=freq.begin();

    for(map<string,int>::iterator it = freq.begin(); it!= freq.end(); it++){
        if( it->second > largest){
            ptr=it;
            largest=it->second;
        }
    }
    return *ptr;
}


int main(){
    string str;
    getline(cin,str);
    pair<string,int> res=func(str);
    cout<<res.first<<" "<<res.second<<endl;
}
