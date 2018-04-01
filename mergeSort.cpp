#include <iostream>
using namespace std;

void merge(int ary[], int start, int end)
{
  int mid = (start + end)/2;
  int start1 = start;
  int start2 = mid+1;
  int size = start + end + 1;
  int tempArry[size] = {0};
  int it = 0;

  while((start1 <= mid) && (start2 <= end))
  {
    if(ary[start1] <= ary[start2])
    {
      tempArry[it] = ary[start1];
      start1++;
      it++;
    }
    else
    {
      tempArry[it] = ary[start2];
      start2++;
      it++;
    }
  }

//move remaining elements
 while(start1 <= mid)
 {
   tempArry[it] = ary[start1];
   start1++;
   it++;
 }

 while(start2 <= end)
 {
   tempArry[it] = ary[start2];
   start2++;
   it++;
 }

 //move tempArry to main ary
 it = 0;
 for(int i=start; i<=end; i++)
 {
   ary[i] = tempArry[it];
   it++;
 }

}

void mergeSort(int ary[], int start, int end)
{
  if(start < end)
  {
    int mid = (start + end)/2;
    mergeSort(ary, start, mid);
    mergeSort(ary, mid+1, end);
    merge(ary, start, end);
  }
}

int main()
{
  int A[] = {3, 7, 1, 8, 4, 2, 11, 3, 6};
  mergeSort(A, 0, 8);

  for(int i=0; i<9; i++)
  {
    cout<<A[i]<<" ";
  }

  return 0;
}
