#include <iostream>
using namespace std;

void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

void printPermutations(char *c, int start, int end){

  if(start == end)
  {
    cout<<c<<" ";
  }
  else
  {
    for(int i=start; i<=end; i++)
    {
      swap(c+start, c+i);
      printPermutations(c, start+1, end);
      swap(c+start, c+i);
    }
  }

}

int main()
{
  string str = "abc";
  int length = str.length();
  char *s = &str[0];
  printPermutations(s, 0, length-1);

  return 0;
}
