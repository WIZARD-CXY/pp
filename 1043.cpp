/*************************************************************************
	> File Name: 1043.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Oct 2014 07:40:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <cstdio>
#include <algorithm>
#include <cstring>

int preorder[1001];
int inorder[1001];
int postorder[1001];

//if build return fail it is indicate output NO
int build(int n, int *s1, int *s2, int* postorder){
    int flag1;
    int flag2;
    if(n>0){
        int pos;
        for(pos=0; pos<n; n++){
            if(s2[pos]==s1[0]){
                break;

            }
        }

        for(int i=0; i<pos; i++){
            if(inorder[i]<s1[0]){
               flag1=0;
            }
        }
        for(int i=pos+1; i<n; i++){
            if(inorder[i]<s1[0]){
                flag2=0;
            }
        }
        if(flag1)
             

        build(pos,s1+1,s2,postorder);
        build(n-pos-1,s1+pos+1,s2+pos+1,postorder+pos);

    }
}
int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>preorder[i];
        inorder[i]=preorder[i];
    }

    sort(inorder,inorder+n);
    if(!build(n,preorder,inorder,postorder)){
        cout<<"NO"<<endl;
    }else {
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++){
            
            if(i==0){
              cout<<postorder[i];
            }
            else{
                cout<<" "<<postorder[i];
            }

        }
    }
}
