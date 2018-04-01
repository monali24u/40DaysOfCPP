#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

void AddNode(node **root, int val)
{
	node *newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;

	if(*root == NULL)
	{
		*root = newnode;
	}
	else
	{
		if(val <= (*root)->data)
		{
			AddNode(&((*root)->left), val);
		}
		else
		{
			AddNode(&((*root)->right), val);
		}
	}
}

void Inorder(node *root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		cout<<root->data<<" ";
		Inorder(root->right);
	}
}

void PrintLeafNodes(node *root)
{
	if(root == NULL)
	{
		return;
	}

	if(root->left == NULL && root->right == NULL)
	{
		cout<<root->data<<" ";
	}

	if(root->left != NULL)
	{
		PrintLeafNodes(root->left);
	}

	if(root->right != NULL)
	{
		PrintLeafNodes(root->right);
	}

}

int main() {
	// your code goes here
	node *root = NULL;
	AddNode(&root, 8);
	AddNode(&root, 5);
	AddNode(&root, 1);
	AddNode(&root, 3);
	AddNode(&root, 7);
	AddNode(&root, 18);
	AddNode(&root, 9);
	AddNode(&root, 11);
	AddNode(&root, 20);

	PrintLeafNodes(root);
	cout<<endl;

	return 0;
}
