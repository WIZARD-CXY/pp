/*************************************************************************
	> File Name: 1064_bk.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 23 Feb 2014 01:12:57 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

struct BTNode{
    int data;
    BTNode *left;
    BTNode *right;
};

void build(int *array, int len, BTNode **r){
    int level=0;
    int i;
    for(i=0; i<100; i++){
        if((int)pow(2.0,i)-1>len){
            level=i;
            break;
        }
    }

    int remain;
    int leftnum;
    int rightnum;
    int last;
    int c;
    c=(int)pow(2.0,level-1)-1;
    remain=len-c;
    last=c+1;
    if(remain>last/2){
        leftnum=(c-1)/2+last/2;
    } else {
        leftnum =(c-1)/2+remain;
    }
    rightnum =len-leftnum-1;

    BTNode *root=new BTNode;
    *r=root;
    root->data=array[leftnum];
    root->left=NULL;
    root->right=NULL;

    if(leftnum>0){
        build(array,leftnum,&root->left);
    }
    if(rightnum>0){
        build(array+leftnum+1,rightnum,&root->right);
    }
}

int main(){
#ifdef d
    freopen("1064.txt","r".stdin);
#endif
    int n,i;
    cin>>n;

    int *array=new int[n];
    for(i=0; i<n;i++){
        cin>>array[i];
    }

    sort(array,array+n);

    BTNode *root=NULL;
    build(array,n,&root);

    queue<BTNode* > que;
    que.push(root);
    bool first=true;

    while(!que.empty()){
        BTNode *tmp=que.front();
        que.pop();

        if(first){
            cout<<tmp->data;
            first=false;
        } else {
            cout<<" "<<tmp->data;
        }
        if(tmp->left!=NULL) que.push(tmp->left);
        if(tmp->right!=NULL) que.push(tmp->right);
    }
}


