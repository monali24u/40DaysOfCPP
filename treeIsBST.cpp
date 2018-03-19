#include <iostream>
using namespace std;

struct node
{
  int val;
  node *left;
  node *right;
};

void AddNode(node **root, int data)
{
  if(*root == NULL)
  {
    node *newnode = new node;
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;
    *root = newnode;
  }
  else
  {
    if(data <= (*root)->val)
    {
      AddNode(&((*root)->left), data);
    }
    else
    {
      AddNode(&((*root)->right), data);
    }
  }

}

bool TreeIsBST(node *root, int min, int max)
{
    if(root == NULL)
  	return true;

    if(root->val < min || root->val > max)
    {
      return false;
    }

    if(root->val >= min && root->val <= max)
    {
      return true;
    }

    bool LeftTree = TreeIsBST(root->left, min, root->val);
    bool RightTree = TreeIsBST(root->right, root->val, max);

    return (LeftTree && RightTree);
}

void Inorder(node *root)
{
  if(root != NULL)
  {
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
  }
}

int main()
{
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

  Inorder(root);
  cout<<endl;
  bool result = TreeIsBST(root,-99, 99);
  if(result == false)
  {
    cout<<"Tree is not BST"<<endl;
  }
  else
  {
    cout<<"Tree is BST"<<endl;
  }

  return 0;
}
