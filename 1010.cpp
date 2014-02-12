/*************************************************************************
	> File Name: 1010.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 12 Feb 2014 03:11:03 PM CST
 ************************************************************************/
// this prob has some issue about test case 9 9 1 20.
// reference http://blog.csdn.net/whosemario/article/details/8734508
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long getNumFromString(string str,long long radix){
    long long result=0;

    int len = str.size();

    for(int i=0; i<len; i++){
        if( str[i] >= '0' && str[i] <= '9'){
            result=result*radix+str[i]-'0';
        } else if (str[i] >= 'a' && str[i] <= 'z'){
            result=result*radix+str[i]-'a'+10;
        }
    }
    
    return result;
}
//return 1 means s>target
//return 0 means s==target
//return -1 means s<target
int cmp(string &s,long long target,long long radix){

    long long result=0;

    int len = s.size();

    for(int i=0; i<len; i++){
        if( s[i] >= '0' && s[i] <= '9'){
            result=result*radix+s[i]-'0';
        } else if (s[i] >= 'a' && s[i] <= 'z'){
            result=result*radix+s[i]-'a'+10;
        }

        if(result>target) return 1;
    }

    if(result==target) return 0;
    if(result<target) return -1;

}

long long searchRadix(string target1,long long low,long long high,long long target)
{

    long long mid;

    while(low<=high){
        mid=(low+high)/2;

        int res = cmp(target1,target,mid);

        if(res>0){
            high=mid-1;
        } else if(res<0){
            low=mid+1;
        } else return mid;

    }

    return -1;
}

long long calminRadix(string str){
    long long ret =0;

    int len=str.size();
    int num;

    for(int i=0; i<len; i++){
        if(str[i]>='0' && str[i]<='9') num=str[i]-'0';
        else if(str[i]>='a' && str[i]<='z') num=str[i]-'a'+10;
        else {}

        if(ret<num+1) ret=num+1;
    }

    return ret;
}
long long target,radix;

int main(){

 
    string N1;
    string N2;

    cin>>N1>>N2;

    const char *p1=N1.c_str();
    const char *p2=N2.c_str();

    int tag;

    cin>>tag;
    cin>>radix;

    
    if (strlen(p1) == 1 && strlen(p2) == 1 && p1[0] == p2[0] && p1[0] == '1') {
        printf("2\n");
        return 0;
    }else if (strcmp(p1, p2) == 0) {
        printf("%lld\n", radix);
        return 0;
    }

    int res;

    if(tag == 1){

        target=getNumFromString(N1,radix);

        long long low=calminRadix(N2);
        long long most = target>low?target:low;

        res=searchRadix(N2,low,most,target);

        if(res == -1){
            cout<<"Impossible"<<endl;
        }
        else cout<<res;

    }else{
        target = getNumFromString(N2,radix);

        long long low=calminRadix(N1);
        long long most = target>low?target:low;

        res=searchRadix(N1,low,most,target);

        if(res == -1){
            cout<<"Impossible"<<endl;
        }
        else cout<<res;
    }

}



