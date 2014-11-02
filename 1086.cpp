/*************************************************************************
	> File Name: 1056.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Nov 2014 10:15:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

struct node{
    int val;
    node *left;
    node *right;
};
node *root;

node* buildTree(){
    string s;
    cin>>s;
    if(s[1]=='u'){
        int digit;
        cin>>digit;
        node *newnode = new node();
        newnode->val=digit;
        newnode->left=buildTree();
        newnode->right=buildTree();
        return newnode;
    }
    return NULL;
}

bool first=1;
void postOrder(node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        if(first){
            cout<<root->val;
            first=0;
        }else{
            cout<<" "<<root->val;
        }
    }
}

int main(){
    freopen("1086.txt","r",stdin);
    int n;
    cin>>n;
    root=buildTree();
    postOrder(root);
    cout<<endl;
}
