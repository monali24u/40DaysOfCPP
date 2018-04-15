#include <iostream>
#include <vector>
#include <set>
using namespace std;


int CheckDuplicate(vector<int> &vec)
{
	int length = vec.size();
	set<int> myset;
	set<int>::iterator it;
	myset.insert(vec[0]);

	for(int i=1; i<length; i++)
	{
		it = myset.find(vec[i]);
		if(it != myset.end())
		{
			//found duplicate
			return i;
		}
		else
		{
			myset.insert(vec[i]);
		}
	}

	return -1;

}

int main() {
	int arry[] = {1,2,3,2,1,1};

	vector<int> vec;
	vec.insert(vec.begin(), arry, arry+6);
	vector<int>::iterator it;

	for(it = vec.begin(); it != vec.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	int result = CheckDuplicate(vec);

	if(result == -1)
	{
		cout<<"no duplicates found";
	}
	else
	{
		cout<<"duplicate found at index:- "<<result;
	}

	return 0;
}
