#include <iostream>
#include <cstdio>
using namespace std;
#include<cmath>

struct Node
{
	int value;
	Node* leftChild;
	Node* rightChild;
	int height;		//左子树高度 - 右子树高度
	Node(int v):value(v),leftChild(NULL),rightChild(NULL),height(0){}
};

int getHeight(Node* node)
{
	if(node == NULL)return -1;
	return node->height;

}

bool isBalanced(Node* parent)
{
	return abs(getHeight(parent->leftChild) - getHeight(parent->rightChild)) < 2;
}

Node* rotate_LL(Node* parent)
{
	Node* child = parent->leftChild;
	parent->leftChild = child->rightChild;
	child->rightChild = parent;

	parent->height = max(getHeight(parent->leftChild),getHeight(parent->rightChild)) + 1;
	child->height = max(getHeight(child->leftChild),getHeight(child->rightChild)) + 1;
	return child;
}

Node* rotate_RR(Node* parent)
{
	Node* child = parent->rightChild;
	parent->rightChild = child->leftChild;
	child->leftChild = parent;

	parent->height = max(getHeight(parent->leftChild),getHeight(parent->rightChild)) + 1;
	child->height = max(getHeight(child->leftChild),getHeight(child->rightChild)) + 1;
	return child;
}

Node* rotate_LR(Node* parent)
{
	Node* child = parent->leftChild;
    parent->leftChild = rotate_RR(child);
    return rotate_LL(parent);
}

Node* rotate_RL(Node* parent)
{
	Node* child = parent->rightChild;
	parent->rightChild = rotate_LL(child);
	return rotate_RR(parent);
}

Node* InsertNode(Node* root,int newValue)
{
	if(root!=NULL)
	{
		if(newValue > root->value)		//R
		{
			root->rightChild = InsertNode(root->rightChild,newValue);
			if(!isBalanced(root))
			{
				if(newValue > root->rightChild->value)	//R-R
				{
					root = rotate_RR(root);
				}else							//R-L
				{
					root = rotate_RL(root);
				}
			}
		}else							//L
		{
			root->leftChild = InsertNode(root->leftChild,newValue);
			if(!isBalanced(root))
			{
				if(newValue > root->leftChild->value)	//L-R
				{
					root = rotate_LR(root);
				}else							//L-L
				{
					root = rotate_LL(root);
				}
			}
		}
	}else
	{
		root = new Node(newValue);
	}
	root->height = max(getHeight(root->leftChild),getHeight(root->rightChild)) + 1;
	return root;
}

void PrintTree(Node* root)
{
	if(root != NULL)
	{
		cout<<root->value<<"--";
		PrintTree(root->leftChild);
		PrintTree(root->rightChild);
	}
}

int main()
{
    freopen("1066.txt","r",stdin);
	int n;
	cin>>n;

	Node *root = NULL;

	int x;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>x;
		root = InsertNode(root,x);
	}
	cout<<root->value<<endl;
	
	return 0;
}
