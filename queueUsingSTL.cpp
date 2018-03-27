#include <iostream>
#include <list>
using namespace std;

class Queue
{
  private:
     list<int> mylist;

  public:
    Queue(){};
    void Enqueue(int value);
    void Dequeue();
    void Print();
};

void Queue::Enqueue(int value)
{
   mylist.push_back(value);
}

void Queue::Dequeue()
{
  if(!mylist.empty())
  {
    mylist.pop_front();
  }
}

void Queue::Print()
{
  if(!mylist.empty())
  {
    list<int>::iterator it;

    for(it=mylist.begin(); it!=mylist.end(); it++)
    {
      cout<<*it<<" ";
    }
    cout<<endl;
  }
  else
  {
    cout<<"Queue is empty"<<endl;
  }
}

int main()
{
  Queue q;
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  q.Enqueue(4);
  q.Enqueue(5);
  q.Enqueue(6);
  q.Print();
  q.Dequeue();
  q.Dequeue();
  q.Dequeue();
  q.Print();
  q.Dequeue();
  q.Dequeue();
  q.Print();
  q.Dequeue();
  q.Print();

  return 0;
}
