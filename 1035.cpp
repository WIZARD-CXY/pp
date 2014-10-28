/*************************************************************************
	> File Name: 1035.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Oct 2014 09:35:34 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#include<vector>

struct record{
    string account;
    string password;
};

int main(){
    freopen("1035.txt","r",stdin);

    int n;
    cin>>n;
    int modifycount=0;
    vector<record> modi;

    for(int i=0; i<n; i++ ){
        string account,password;
        cin>>account>>password;
        bool modified = false;

        for(int j=0; j<password.size(); j++){
            if(password[j] == '1'){
                password[j] = '@';
                modified = 1;
            } else if(password[j] == '0'){
                password[j] = '%';
                modified = 1;
            } else if (password[j] == 'O'){
                password[j]='o';
                modified =1 ;
            } else if( password[j] == 'l'){
                password[j]='L';
                modified =1 ;
            } else {
            }

        
        }
        if(modified){
            modifycount++;
            record temp;
            temp.account = account;
            temp.password = password;
            modi.push_back(temp);
        }
        
    }

    if(modifycount == 0){
        if(n == 1){
            cout<<"There is 1 account and no account is modified"<<endl;
        }else{
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
        }
    } else {
        cout<<modifycount<<endl;
        for(int i=0; i<modi.size(); i++){
            cout<<modi[i].account<<" "<<modi[i].password<<endl;
        }
    }
}
