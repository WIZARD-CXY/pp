/*************************************************************************
	> File Name: 1043_.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Oct 2014 10:13:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstring>
#include<cstdio>

using namespace std;

int preOrder[1001];
int preOrderImg[1001];
int postOrder[1001];
int gindex;

struct node{
    node *left;
    node *right;
    int key;
};

void insertNode(node *p, int key, bool isM){
    if(p==NULL){
        p=new node();
        p->left=NULL;
        p->right=NULL;
        p->key=key;
        return;
    }
    else{
        if(isM){
            if(key<p->key){
                insertNode(p->right,key,isM);
            }else{
                insertNode(p->left,key,isM);
            }
        }else {
            if(key<p->key){
                insertNode(p->left,key,isM);
            }else{
                insertNode(p->right,key,isM);
            }
        }
    }

}

void createBSTree(node *root, int *arr,int n, bool isM){
    for(int i=0; i<n; i++){
        insertNode(root, arr[i],isM);
    }
}

void postOrder(node *root){
    if(!root){
        postOrder(root->left);
        postOrder(root->right);
        postOrder[gindex++]=root->key;
    }
}

bool checkIs
