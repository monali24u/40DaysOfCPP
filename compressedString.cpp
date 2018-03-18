#include <iostream>
using namespace std;

string compressedString(string &str)
{
  int length = str.length();
  string compressedStr = "";
  char last = str[0];
  int count = 1;

  for(int i=1; i<length; i++)
  {
    if(str[i] == last)
    {
      count++;
    }
    else
    {
      char cnt = count + '0';
      compressedStr = compressedStr + last + cnt;
      count = 1;
      last = str[i];
    }

  }
  char cnt = count + '0';
  compressedStr = compressedStr + last + cnt;

  int compressedStrLength = compressedStr.length();

  if(compressedStrLength <= length)
  {
    return compressedStr;
  }

  return str;
}

int main()
{
  string str;
  cin>>str;
  string result = compressedString(str);
  cout<<result;

  return 0;
}
