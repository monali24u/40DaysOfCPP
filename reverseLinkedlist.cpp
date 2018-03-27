#include <iostream>
using namespace std;

struct node
{
  int val;
  node *next;
};

node *current = NULL;

void AddNode(node **root, int input)
{
  node *newnode = new node;
  newnode->val = input;
  newnode->next = NULL;

  if(*root == NULL)
  {
    *root = newnode;
    current = *root;
  }
  else
  {
    current->next = newnode;
    current = newnode;
  }
}

void Reverse(node **root)
{
  node *prev = NULL;
  node *current = *root;

  while(current != NULL)
  {
    node *temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
  }

  *root = prev;
}

void Print(node *root)
{
  while(root != NULL)
  {
    cout<<root->val<<"-> ";
    root = root->next;
  }
  cout<<endl;
}


int main(){
  node *root = NULL;

  AddNode(&root, 10);
  AddNode(&root, 20);
  AddNode(&root, 30);
  AddNode(&root, 40);
  AddNode(&root, 50);
  AddNode(&root, 60);
  AddNode(&root, 70);
  Print(root);

  Reverse(&root);
  Print(root);

  return 0;
}
