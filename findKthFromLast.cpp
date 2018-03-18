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

void FindKthFromLast(node *root, int k)
{
  node *slow = root;
  node *fast = root;

  if(k = 0)
  {
    cout<<"Invalid value";
    return;
  }

  if(root != NULL)
  {
    for(int i=1; i<k; )
    {
      if(fast->next != NULL)
      {
        fast = fast->next;
        i++;
      }
      else
      {
        cout<<"value is greater than linkedlist."<<"\n";
        return;
      }
    }
  
    while(fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }

    cout<<"Kth node value is "<<slow->val<<"\n";
  }

}

void Print(node *root)
{
  while(root != NULL)
  {
    cout<<root->val<<"->";
    root = root->next;
  }
  cout<<endl;
}

int main()
{
  node *root = NULL;
  AddNode(&root, 10);
  AddNode(&root, 20);
  AddNode(&root, 30);
  AddNode(&root, 40);
  AddNode(&root, 50);
  AddNode(&root, 60);

  Print(root);
  FindKthFromLast(root, 3);

  return 0;
}
