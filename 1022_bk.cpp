/*************************************************************************
	> File Name: 1022_bk.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Tue 18 Feb 2014 10:42:39 AM CST
 ************************************************************************/


/*
use map<string,set<string> > 
string substr(int start,int len) or substr(int start);
string find(char c) return index of first,or -1 if none;
cin.ignore() clear cache(such as '\n') in cin;
*/

#include<iostream>
#include<cstdlib>
#include<map>
#include<string>
#include<set>
#include<cstdio>
using namespace std;
map<string,set<string> > title,author,key,publisher,year;
set<string>::iterator it;
int main(){
    freopen("1022.txt","r",stdin);

    int i,j,n,m; 
    cin>>n;
    cin.ignore();
    string ii,tt,aa,kk,pp,yy;
    for(i=0;i<n;i++){
       getline(cin,ii);
       getline(cin,tt);
       getline(cin,aa);
       getline(cin,kk);
       getline(cin,pp);
       getline(cin,yy);
       title[tt].insert(ii);  
       author[aa].insert(ii); 
       int spaceid=kk.find(' ');
       while(spaceid>0){
           string one=kk.substr(0,spaceid);
           key[one].insert(ii); 
           kk=kk.substr(spaceid+1);
           spaceid=kk.find(' ');
       }
       key[kk].insert(ii); 
       publisher[pp].insert(ii);  
       year[yy].insert(ii);                  
    }
    cin>>m;
    cin.ignore();
    int qid;
    string qstr,query;
    for(i=0;i<m;i++){
       getline(cin,qstr);
       qid=qstr[0]-'0';
       query=qstr.substr(3);
       cout<<qstr<<endl;
       if(qid==1){
           if(title[query].size()==0){
               cout<<"Not Found"<<endl;
               continue;
           }
           for(it=title[query].begin();it!=title[query].end();it++){
               cout<<*it<<endl;
           }
       } 
       else  if(qid==2){
           if(author[query].size()==0){
               cout<<"Not Found"<<endl;
               continue;
           }
           for(it=author[query].begin();it!=author[query].end();it++){
               cout<<*it<<endl;
           }
       }
       else  if(qid==3){
           if(key[query].size()==0){
               cout<<"Not Found"<<endl;
               continue;
           }
           for(it=key[query].begin();it!=key[query].end();it++){
               cout<<*it<<endl;
           }
       }         
       else  if(qid==4){
           if(publisher[query].size()==0){
               cout<<"Not Found"<<endl;
               continue;
           }
           for(it=publisher[query].begin();it!=publisher[query].end();it++){
               cout<<*it<<endl;
           }
       }         
       else  if(qid==5){
           if(year[query].size()==0){
               cout<<"Not Found"<<endl;
               continue;
           }
           for(it=year[query].begin();it!=year[query].end();it++){
               cout<<*it<<endl;
           }
       }                   
    }
    return 0; 
}
