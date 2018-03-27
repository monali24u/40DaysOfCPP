#include <iostream>
using namespace std;

int partition(int ary[], int left, int right)
{
  int pivot = ary[(left + right)/2];

  while(left <= right)
  {
    while(ary[left] < pivot)
    {
      left++;
    }

    while(ary[right] > pivot)
    {
      right--;
    }

    if(left <= right)
    {
      int temp = ary[left];
      ary[left] = ary[right];
      ary[right] = temp;
      left++;
      right--;
    }

  }

  return left;
}

void quickSort(int ary[], int left, int right)
{
  int index = partition(ary, left, right);

  if(left < index - 1)
  {
    quickSort(ary, left, index-1);   //sort left half
  }

  if(index < right)
  {
    quickSort(ary, index, right);   //sort right half
  }
}

int main()
{
  int A[] = {3, 7, 1, 8, 4, 2, 11, 3, 6};
  quickSort(A, 0, 8);

  for(int i=0; i<9; i++)
  {
    cout<<A[i]<<" ";
  }

  return 0;
}
