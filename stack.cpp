#include <iostream>
using namespace std;

class Stack
{
  private:
    struct node
      {
        int val;
        node *next;
      };
      node *top = NULL;
      node *bottom = NULL;
      node *mintop = NULL;
      node *minbottom = NULL;
  public:
    Stack(){};
    void Push(int value);
    void Pop();
    void Min();
    void Print();
    void PrintMin();
};

void Stack::Push(int value)
{
  node *newnode = new node;
  newnode->val = value;
  newnode->next = NULL;

  if(top == NULL)
  {
    top = newnode;
    bottom = newnode;
  }
  else
  {
    newnode->next = top;
    top = newnode;
  }

  //push into min stack
  if(mintop == NULL)
  {
    node *newnode = new node;
    newnode->val = value;
    newnode->next = NULL;

    mintop = newnode;
    minbottom = newnode;
  }
  else
  {
    node *newnode = new node;

    if(value < mintop->val)
    {
      newnode->val = value;
    }
    else
    {
      newnode->val = mintop->val;
    }

    newnode->next = mintop;
    mintop = newnode;
  }

}

void Stack::Pop()
{
  if(top == NULL)
  {
    cout<<"Nothing to Pop"<<endl;
    return;
  }
  else
  {
      node *temp = top;
      int poppedVal = temp->val;
      top = top->next;
      temp->next = NULL;
      cout<<"poppedVal "<<poppedVal<<endl;
      delete temp;

      //minstack poppedVal
      node *mintemp = mintop;
      mintop = mintop->next;
      mintemp->next = NULL;
      delete mintemp;
  }

}

void Stack::Min()
{
  cout<<"Min value is "<<mintop->val<<endl;
  return;
}

void Stack::Print()
{
  node *runner = top;
  while(runner != NULL)
  {
    cout<<runner->val<<"->";
    runner = runner->next;
  }
  cout<<endl;
}

void Stack::PrintMin()
{
  node *runner = mintop;
  while(runner != NULL)
  {
    cout<<runner->val<<"->";
    runner = runner->next;
  }
  cout<<endl;
}

int main()
{
  Stack *stk = new Stack();
  stk->Push(5);
  stk->Push(3);
  stk->Push(5);
  stk->Push(4);
  stk->Push(1);
  stk->Print();
  stk->Min();
  stk->Pop();
  stk->Pop();
  stk->Pop();
  stk->Print();
  stk->Min();
  stk->Pop();
  stk->Print();
  stk->Min();
  stk->Pop();
  stk->Print();
  stk->Min();
  stk->Pop();

  return 0;
}
