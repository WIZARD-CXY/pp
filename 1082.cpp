#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    freopen("1082.txt","r",stdin);
    string a[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string b[] = {"", "Shi", "Bai", "Qian", "Wan","Shi","Bai","Qian","Yi"};

    vector<string> res;
    vector<int> digit;

    int num,e;
    cin>>num;

    if(num==0){
        cout<<"ling";
        return 0;
    } else if(num <0){
        cout<<"Fu ";
        num=-num;
    }

    while(num!=0){
        digit.push_back(num%10);
        num/=10;
    }

    for(e=0; e<digit.size() && digit[e]==0; e++){
        
    }
    if(e==8){
        cout<<a[digit[e]]<<" Yi";
        return 0;
    }



    for(int i=e; i<digit.size(); i++){
        if(i!=0 && (digit[i]!=0 || i==4 || i==8)){
            res.push_back(b[i]);
        }
        res.push_back(a[digit[i]]);
    }

    for(int i=res.size()-1; i>=0; i--){
        if( i!=res.size()-1 ){
            cout<<" ";
        }
        int cnt=0;

        while(i>=0 && res[i]=="ling"){
            i--;
            cnt++;
        }
        if(cnt!=0 && res[i]!="Wan"){
            cout<<"ling ";
        }
        cout<<res[i];
    }

    if(e==5 || e==6 || e==7){
        cout<<" Wan";
    }
}
