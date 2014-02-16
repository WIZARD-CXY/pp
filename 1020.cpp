/*************************************************************************
	> File Name: 1020.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sat 15 Feb 2014 11:14:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include<queue>
#include<cstdio>
int postorder[35];
int inorder[35];
int N;

struct bt_node{
    int data;
    bt_node *left;
    bt_node *right;
};

queue<bt_node*> q;

void create_bt1(int* post, int* in ,int len, bt_node** root){

    if(len==0) {
        cout<<*post<<" "<<*in<<" len0 "<<endl;
        return;
    }

    bt_node* node =new bt_node;

    node->data=*post;
    node->left=NULL;
    node->right=NULL;
    
    if(*root==NULL) *root=node;

    if(len==1) {
        return;//construct leaf node
    }


    //find the root
    int rootpos;
    for(int i=0; i<len; i++){
        if(*post==*(in+i)){
            rootpos=i;
            break;
        }
    }

    int leftlen=rootpos;
    int rightlen=len-1-rootpos;

    //recursivly construct the left subtree and right subtree
    create_bt1(post-rightlen-1,in,leftlen,&node->left);
    create_bt1(post-1,in+leftlen+1,rightlen,&node->right);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>postorder[i];
    for(int i=0;i<N;i++)
        cin>>inorder[i];
    
    bt_node* root=NULL;
    create_bt1(postorder+N-1,inorder,N,&root);
    
    //层序遍历
    q.push(root);
    int time=0;
    while(!q.empty()){
        time++;
        bt_node* tmp=q.front();q.pop();
        if(time==1)
            printf("%d",tmp->data);
        else
            printf(" %d",tmp->data);
        if(tmp->left!=NULL) q.push(tmp->left);
        if(tmp->right!=NULL) q.push(tmp->right);
    }
    return 0;
}




