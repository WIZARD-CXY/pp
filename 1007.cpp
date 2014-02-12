/*************************************************************************
	> File Name: 1007.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 12 Feb 2014 10:26:09 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main(){
    
    int begin=0,end=0,sum=-1;


    int k;
    cin>>k;

    int num[k];
    int tempbegin=0,tempend=0,tempsum=0;
    int negativecount=0;

    for(int i=0; i<k; i++){
        cin>>num[i];
        if(num[i]<0) negativecount++;
    }

    if(negativecount == k){
        cout<<0<<" "<<num[0]<<" "<<num[k-1];
        
        return 0;
    }

    for(int i=0; i<k; i++){
        
        if(tempsum>=0){
            tempsum+=num[i];
            tempend=i;
        } else {
            //if tempsum<0 ,then tempSum+input[i]<input[i]
            //so start from new subsequence
            tempend=tempbegin=i;
            tempsum=0;
            tempsum+=num[i];
        }

        if(tempsum > sum ){
            sum=tempsum;
            end=tempend;
            begin=tempbegin;
        }
    }

    cout<<sum<<" "<<num[begin]<<" "<<num[end]<<endl;
}
