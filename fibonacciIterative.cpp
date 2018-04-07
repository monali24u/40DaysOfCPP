#include <iostream>
#include <vector>
using namespace std;


int fibonacciIterative(int val)
{
	vector<int> myvec(val, -1);
	if( val == 0)
	{
	    myvec[0] = 0;
	    return 0;
	}
	if(val == 1)
	{
	    myvec[1] = 1;
                return 1;
	}
	if(myvec[val] != -1)
	{
		return myvec[val];
	}

	myvec[val]  = fibonacci(val-1) + fibonacci(val-2);

	return myvec[val];
}


int fibonacciIterativeWithoutExternalDS(int val)
{
	if( val == 0)
	{
	   return 0;
	}
	if(val == 1 || val == 2)
	{
    return 1;
	}

	int previous = 1;
	int current =  1;
	int next = 1;

	for(int i=3; i<=val; i++)
	{
		next = current + previous;
		previous = current;
		current = next;
	}

  return next;
}

int fibonacciRecursive(int num, int p, int c)
{
	if(num == 0)
	{
	   return p;
	}
	else if(num == 1 && num == 2)
	{
	    return c;
	}
	else
	{
	  int temp = p;
	   p = c;
	   c = c + temp;
	   fibonacci(num-1, p, c);
  }
}

int main() {
	// your code goes here
	int result = fibonacci(50);
	cout<<result<<endl;

	int result2 = fibonacciRecursive(6, 0, 1);
	cout<<result2;
	return 0;
}
