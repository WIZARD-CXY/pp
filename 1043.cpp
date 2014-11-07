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

int pre[1001];
int preImg[1001];
int post[1001];
int gindex=0;
int gindex2=0;

bool isMirrored;

struct node{
    node *left;
    node *right;
    int key;
};

void insertNode(node *&p, int key, bool isM){
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
// mode *&root is necessary!!
void createBSTree(node *&root, int *arr,int n, bool isM){
    for(int i=0; i<n; i++){
        insertNode(root, arr[i],isM);
    }
}

void postOrder(node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        post[gindex++]=root->key;
    }
}
void preOrder(node *root){
    if(root){
        preImg[gindex2++]=root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    freopen("1043.txt","r",stdin);


    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>pre[i];
    }
    if(pre[1]<pre[0]){
        isMirrored=false;

    }else{
        isMirrored=true;
    }
    node *root=NULL;
    createBSTree(root,pre,n,isMirrored);
    preOrder(root);

    for(int i=0; i<n; i++){
        if(pre[i]!=preImg[i]){
           cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    postOrder(root);

    cout<<post[0];
    for(int i=1; i<n; i++){
        cout<<" "<<post[i];
    }
    cout<<endl;

}
