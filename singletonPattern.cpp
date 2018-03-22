#include <iostream>
using namespace std;

class person
{
         public:
	person(){};
	person obj = NULL;

         public:
	 person getInstance()
	 {
	 	if(obj == NULL)
	 	{
	 		obj = new person();
	 	}
	 	else
	 	{
	 		return obj;
	 	}
	 }
}

int main() {
	// your code goes here
	person obj = new person();


	return 0;
}
