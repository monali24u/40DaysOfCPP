#include <iostream>
#include <vector>
using namespace std;


void SelectionSort(vector<int> &vec)
{
  int length = vec.size();
  int minIndex;

  for(int i=0; i<length; i++)
  {
    minIndex = i;
    for(int j=i+1; j<length; j++)
    {
      
    }
  }
}

int main()
{
  int arry[] = {2,10,3,-1,2,9,0};
  vector<int> vec;
  vec.insert(vec.begin(), arry, arry+7);

  SelectionSort(vec);
  vector<int>::iterator it;
  for(it=vec.begin(); it!=vec.end(); it++)
  {
    cout<<*it<<" ";
  }
 return 0;
}
