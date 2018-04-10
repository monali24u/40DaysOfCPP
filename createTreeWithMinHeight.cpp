#include <iostream>
using namespace std;

struct node
{
  int val;
  node *left;
  node *right;
};

node * AddNode(int data)
{
    node *newnode = new node;
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node * createTree(int arry[], int start, int end)
{
  if(start > end)
  {
    return NULL;
  }

  int mid = (start + end)/2;
  node *root = AddNode(A[mid]);

  root->left = createTree(arry, start, mid-1);
  root->right = createTree(arry, mid+1, end);

  return root;
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
  int array[10] = {1,5,7,8,11,18,20,25,27,40};
  node *result = createTree(array,0,9);
  Inorder(result);

  return 0;
}
