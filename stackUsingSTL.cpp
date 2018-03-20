#include <iostream>
#include <forward_list>
using namespace std;


class Stack
{
  private:
    forward_list<int> mylist;
    forward_list<int> minlist;

  public:
    Stack(){};
    void Push(int value);
    void Pop();
    void Min();
    void Print();
};

void Stack::Push(int value)
{
  mylist.push_front(value);

  if(minlist.empty())
  {
    minlist.push_front(value);
  }
  else
  {
    if(value <= minlist.front())
    {
      minlist.push_front(value);
    }
    else
    {
      minlist.push_front(minlist.front());
    }
  }
}

void Stack::Pop()
{
  if(!mylist.empty())
  {
    mylist.pop_front();
  }
  if(!minlist.empty())
  {
    minlist.pop_front();
  }

  return;
}

void Stack::Min()
{
	if(!minlist.empty())
	{
	   cout<<"Min: "<<minlist.front()<<endl;
	}
  return;
}

void Stack::Print()
{
 if(!minlist.empty())
 {
    forward_list<int>::iterator it;

  for(it=minlist.begin(); it!=minlist.end(); it++)
  {
    cout<<*it<<" ";
  }
  cout<<endl;
 }

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
  stk->Min();
  stk->Print();
  stk->Pop();
  stk->Min();
  stk->Pop();
  stk->Print();
  return 0;
}
