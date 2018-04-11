#include <iostream>
#include <vector>
using namespace std;


void BubbleSort(vector<int> &vec)
{
  int length = vec.size();
  for(int i=0; i<length; i++)
   {
     for(int i=1; i<length; i++)
     {
       if(vec[i] < vec[i-1])
       {
         int temp = vec[i];
         vec[i] = vec[i-1];
         vec[i-1] = temp;
       }
    }
   }
}

int main()
{
  int arry[] = {2,10,3,-1,2,9,0};
  vector<int> vec;
  vec.insert(vec.begin(), arry, arry+7);

  BubbleSort(vec);
  vector<int>::iterator it;
  for(it=vec.begin(); it!=vec.end(); it++)
  {
    cout<<*it<<" ";
  }
 return 0;
}
