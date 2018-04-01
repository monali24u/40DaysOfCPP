#include <iostream>
#include <map>
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

void RemoveDuplicatesUsingMap(node *root)
{
  map<int, int>mymap;
  map<int, int>::iterator it;
  node *slow = root;

  if(slow != NULL)
  {
    mymap.insert(pair<int,int>(slow->val, 1));
    slow = slow->next;
  }
  else
  {
    return;
  }


  while(slow != NULL)
  {
     it = mymap.find(slow->val);

     if(it != mymap.end())
     {
       //found
       it->second = it->second + 1;
     }
     else
     {
       mymap.insert(pair<int,int>(slow->val, 1));
     }

   slow = slow->next;
  }

  for(it=mymap.begin(); it!=mymap.end(); it++)
  {
    cout<<it->first<<" "<<it->second<<endl;
  }

  node *fast = root;
  node *back = root;
  fast = fast->next;

  while(fast != NULL)
  {
    it = mymap.find(fast->val);

    if((it->second) > 1)
    {
      node *temp = fast;
      back->next = fast->next;
      delete temp;
      it->second = it->second - 1;
    }
    else
    {
      back = back->next;
    }

    fast = fast->next;
  }


}

void RemoveDuplicates(node *root)
{
  //if list is sorted else sort list first
   node *slow = root;
   node *fast = root;

   if(fast != NULL)
   {
     fast = fast->next;
   }

   while(fast != NULL)
   {
     if(fast->val == slow->val)
     {
        node *temp = fast;
        slow->next = fast->next;
        delete temp;
     }
     else
     {
       slow = slow->next;
     }

    fast = fast->next;
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

  //for unsorted;
  node *root = NULL;

  AddNode(&root, 40);
  AddNode(&root, 20);
  AddNode(&root, 20);
  AddNode(&root, 40);
  AddNode(&root, 70);
  AddNode(&root, 80);

  Print(root);

  //RemoveDuplicates(root);
  RemoveDuplicatesUsingMap(root);

  Print(root);

  return 0;
}
