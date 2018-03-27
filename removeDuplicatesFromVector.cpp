#include <iostream>
#include <vector>
using namespace std;

void RemoveDuplicates(vector<int> &vec)
{
	int length = vec.size();
	if(length == 0 || length == 1)
	{
		return;
	}

	int j=1;

	for(int i=2; i<length; i++)
	{
		if(vec[i-1] != vec[i])
		{
			vec[j] = vec[i-1];
			j++;
		}
	}

	vec[j] = vec[length-1];
	j++;

	vec.erase(vec.begin()+j, vec.end());

}

int main() {
	// your code goes here

	 int myarray[] = {1,2,2,3,4,4,4,5,5};
	 vector<int> vec;
     vec.insert (vec.begin(), myarray, myarray+9);

     for(int i=0; i<vec.size(); i++)
     {
     	cout<<vec[i]<<" ";
     }
     cout<<endl;

     RemoveDuplicates(vec);

     for(int i=0; i<vec.size(); i++)
     {
     	cout<<vec[i]<<" ";
     }

	return 0;
}
