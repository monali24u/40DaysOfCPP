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

int HeightOfBST(node *root)
{
  if(root == NULL)
  {
    return 0;
  }

  int leftHeight = 1 + HeightOfBST(root->left);
  int rightHeight = 1 + HeightOfBST(root->right);

  if(leftHeight > rightHeight)
  {
    return leftHeight;
  }

  return rightHeight;
}

bool IsBalanced(node *root)
{
  if(root == NULL)
  {
    return true;
  }

  if(root->left == NULL && root->right == NULL)
  {
    return true;
  }

  int leftSubtreeHeight = HeightOfBST(root->left);
  int rightSubtreeHeight = HeightOfBST(root->right);

  int diff = leftSubtreeHeight - rightSubtreeHeight;
  if(diff < 0)
  {
    diff = rightSubtreeHeight - leftSubtreeHeight;
  }

  if(diff > 1)
  {
    return false;
  }

  return true;
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
  bool result = IsBalanced(root);
  if(result == false)
  {
    cout<<"Tree is not balanced"<<endl;
  }
  else
  {
    cout<<"Tree is balanced"<<endl;
  }

  return 0;
}
