#include <iostream>
#include <vector>
using namespace std;


void FindHighests(vector<int> &vec)
{
  int length = vec.size();
  if(length == 0)
  {
    return -1;
  }

	int first = vec[0];
  int second = vec[0];
  int third = vec[0];

  for(int i=1; i<length; i++)
  {
    if(vec[i] > first)
    {
       third = second;
       second = first;
       first = vec[i];
    }
    if((vec[i] < first) && (vec[i] > second))
    {
       third = second;
       second = vec[i];
    }
    if((vec[i] < second) && (vec[i] > third))
    {
      third = vec[i];
    }
  }

  cout<<first<<" "<<second<<" "<<third<<end;

}

int main() {
	int arry[] = {1,3,2,7,5,9,4};

	vector<int> vec;
	vec.insert(vec.begin(), arry, arry+7);

  FindHighests(vec);

	return 0;
}
