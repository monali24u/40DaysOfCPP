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

bool FindCycle(node *root)
{
  node *slow = root;
  node *fast = root;

  while(fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;

    if(fast == slow)
    {
      return true;
    }
  }

  return false;
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

  bool result = FindCycle(root);
  cout<<result;

  return 0;
}
