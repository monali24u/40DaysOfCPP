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
  if(*root == NULL)
  {
    node *newnode = new node;
    newnode->val = input;
    newnode->next = NULL;
    *root = newnode;
    current = *root;
  }
  else
  {
    node *newnode = new node;
    newnode->val = input;
    newnode->next = NULL;
    current->next = newnode;
    current = newnode;
  }

}

void RemoveDuplicatesUsingHashtable(node *root)
{
  if(root == NULL)
  {
    return;
  }
  int hash[100] = {0};
  node *current = root;
  node *previous = NULL;

  while(current != NULL)
  {
    int index = current->val;
    if(hash[index] == 0)
    {
      hash[index] = hash[index] + 1;
      previous = current;
    }
    else
    {
      previous->next = current->next;
    }

    current = current->next;
  }

}

void RemoveDuplicates(node *root)
{
  //n2 solution
  if(root == NULL)
  {
    return;
  }
  node *current = root;

  while(current != NULL)
  {
    node *runner = current;
    while(runner->next != NULL)
    {
      if(runner->next->val == current->val)
      {
        runner->next = runner->next->next;
      }
      else
      {
        runner = runner->next;
      }
    }
    current = current->next;
  }


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
  AddNode(&root, 10);
  AddNode(&root, 40);
  AddNode(&root, 10);
  AddNode(&root, 60);

  Print(root);

  //RemoveDuplicates(root);
  RemoveDuplicatesUsingHashtable(root);

  Print(root);

  return 0;
}
