#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


void FindPairs(vector<int> &vec, int sum)
{
   sort(vec.begin(), vec.end());
   int length = vec.size();
   int left = 0;
   int right = length - 1;


   while(left < right)
   {
     if((vec[left] + vec[right]) == sum)
     {
       cout<<"( "<<vec[left]<<" , "<<vec[right]<<" )"<<" ";
       left++;
       right--;
     }
     if((vec[left] + vec[right]) > sum)
     {
       right--;
     }
     if((vec[left] + vec[right]) < sum)
     {
       left++;
     }
   }

}

void FindPairsInOrder(vector<int> &vec, int sum)
{
  set<int> myset;
  set<int>::iterator it;
  int length = vec.size();
  int toCheck;

  for(int i=0; i<length; i++)
  {
    myset.insert(vec[i]);
  }

  for(int j=0; j<length; j++)
  {
    toCheck = sum - vec[j];
    it = myset.find(toCheck);
    if(it != myset.end())
    {
      //find pair
      cout<<"( "<<vec[j]<<" , "<<toCheck<<" )"<<" ";
      myset.erase(vec[j]);
    }

  }
}

int main() {
	int arry[] = {2,4,3,5,7,9,0};

	vector<int> vec;
	vec.insert(vec.begin(), arry, arry+7);
  int sum = 7;

  FindPairsInOrder(vec, sum);
  cout<<endl;
  FindPairs(vec, sum);


	return 0;
}
