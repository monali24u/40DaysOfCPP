#include <iostream>
#include <vector>
using namespace std;

void addOne(vector<int> &vec)
{
	int carry = 1;
	int length = vec.size() -1;
	int sum;

	for(int i=length; i>=0; i--)
	{
		sum = vec[i] + carry;

		if(sum >= 10)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		vec[i] = sum % 10;
	}

	if(carry == 1)
	{
		vec.insert(vec.begin(), 1);
	}
}

int main() {
	vector<int> vec{1,2,3,4};
	addOne(vec);

	for(int i=0; i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}

	return 0;
}
