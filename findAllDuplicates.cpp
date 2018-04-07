#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<int> FindDuplicates(vector<int> &vec)
{
	int length = vec.size();
	map<int, int> mymap;
	map<int, int>::iterator it;
	mymap.insert(pair<int, int>(vec[0],1));
  vector<int> newvec;

	for(int i=1; i<length; i++)
	{
		it = mymap.find(vec[i]);
		if(it != mymap.end())
		{
			//found duplicate
			it->second = it->second + 1;

		}
		else
		{
			mymap.insert(pair<int, int>(vec[i],1));
		}
	}

  for(it = mymap.begin(); it != mymap.end(); it++)
  {
      if(it->second > 1)
      {
        newvec.push_back(it->first);
      }
  }

	return newvec;

}

int main() {
	int arry[] = {1,2,3,2,1,1,2};

	vector<int> vec;
	vec.insert(vec.begin(), arry, arry+7);

	vector<int>::iterator it;

	vector<int> result = FindDuplicates(vec);
  for(it = result.begin(); it != result.end(); it++)
 	{
 		cout<<*it<<" ";
 	}

	return 0;
}
