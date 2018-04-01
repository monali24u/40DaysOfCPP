#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    MyQueue(){};
    void Enqueue(int val);
    int Dequeue();
    void Shift();
    int QueueSize();
};

void MyQueue::Enqueue(int val)
{
  s1.push(val);
}

void MyQueue::Shift()
{
  if(s2.empty())
  {
    while(!s1.empty())
    {
      int val = s1.top();
      s2.push(val);
      s1.pop();
    }
  }
}

int MyQueue::Dequeue()
{
  if(!s1.empty() || !s2.empty())
  {
    Shift();
    int poppedVal = s2.top();
    s2.pop();
    return poppedVal;
  }
  else
  {
    //if both empty
    cout<<"nothing to pop"<<endl;
    return 0;
  }

}

int MyQueue::QueueSize()
{
  int totalsize = s1.size() + s2.size();
  return totalsize;
}

int main()
{
  MyQueue que;
  que.Enqueue(1);
  que.Enqueue(2);
  que.Enqueue(3);
  que.Enqueue(4);
  que.Enqueue(5);

  cout<<que.Dequeue()<<"\n";
  cout<<que.Dequeue()<<"\n";
  cout<<que.Dequeue()<<"\n";
  cout<<que.Dequeue()<<"\n";
  cout<<que.Dequeue()<<"\n";

  return 0;
}
