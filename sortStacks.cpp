#include <iostream>
#include <stack>
using namespace std;

class Sort
{
  stack<int> s2;

  public:
    Sort(){};
    void SortStack(stack<int> &);
    void Print();
};

void Sort::SortStack(stack<int> &s1)
{
  while(!s1.empty())
  {
    int tempval = s1.top();
    s1.pop();

    while(!s2.empty() && (s2.top() > tempval))
    {
      s1.push(s2.top());
      s2.pop();
    }

    s2.push(tempval);
  }

}

void Sort::Print()
{
  while(!s2.empty())
  {
    cout<<s2.top()<<endl;
    s2.pop();
  }
}

int main()
{
  stack<int> s1;
  s1.push(5);
  s1.push(3);
  s1.push(1);
  s1.push(4);
  s1.push(6);
  s1.push(2);

  Sort st;
  st.SortStack(s1);
  st.Print();

  return 0;
}
