#include <iostream>
using namespace std;

int BinarySearch(int A[], int val, int size)
{
  int low = 0;
  int high = size - 1;
  int mid;

  while(low <= high)
  {
    mid = (low + high)/2;

    if(A[mid] == val)
    {
      return mid;
    }
    else if(A[mid] < val)
    {
      low = mid + 1;
    }
    else if(A[mid] > val)
    {
      high = mid - 1;
    }

  }

  return -1;

}

int main()
{
  int arry[] = {1,2,3,4,6,7,8,11,13};
  int result = BinarySearch(arry, 11, 9);
  if(result == -1)
  {
    cout<<"Given value is not present in arry"<<endl;
  }
  else
  {
    cout<<"Given value "<<arry[result]<<" found at index "<<result<<"\n";
  }

  return 0;
}
