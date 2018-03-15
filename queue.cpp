#include <iostream>
using namespace std;

class Queue
{
  private:
    struct node
      {
        int val;
        node *next;
      };
      node *front = NULL;
      node *back = NULL;
  public:
    Queue(){};
    void Enqueue(int value);
    void Dequeue();
    void Print();
};

void Queue::Enqueue(int value)
{
  node *newnode = new node;
  newnode->val = value;
  newnode->next = NULL;

  if(front == NULL)
  {
    front = newnode;
    back = newnode;
  }
  else
  {
    back->next = newnode;
    back = newnode;
  }
}

void Queue::Dequeue()
{
  if(front == NULL)
  {
    cout<<"Nothing to Pop"<<endl;
    return;
  }
  else
  {
      node *temp = front;
      int poppedVal = temp->val;
      front = front->next;
      temp->next = NULL;
      cout<<"poppedVal "<<poppedVal<<endl;
      delete temp;
  }
}

void Queue::Print()
{
  node *runner = front;
  while(runner != NULL)
  {
    cout<<runner->val<<"->";
    runner = runner->next;
  }
  cout<<endl;
}

int main()
{
  Queue *que = new Queue();
  que->Enqueue(1);
  que->Enqueue(2);
  que->Enqueue(3);
  que->Enqueue(4);
  que->Enqueue(5);
  que->Print();
  que->Dequeue();
  que->Dequeue();
  que->Dequeue();
  que->Print();
  que->Dequeue();
  que->Print();
  que->Dequeue();
  que->Print();
  que->Dequeue();

  delete que;

  return 0;
}
