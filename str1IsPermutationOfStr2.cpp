#include <iostream>
using namespace std;

bool isPermutation(string s1, string s2)
{
  int arry[256] = {0};

  int length1 = s1.length();
  int length2 = s2.length();

  if(length1 != length2)
  {
    return false;
  }

  if(length1 == 0 && length2 == 0)
  {
    return true;
  }


  for(int i=0; i<length1; i++)
  {
    int index = int(s1[i]);
    arry[index] = arry[index] + 1;
  }

  for(int j=0; j<length2; j++)
  {
    int index = int(s2[j]);
    arry[index] = arry[index] - 1;
  }

  for(int k=0; k<256; k++)
  {
    if(arry[k] != 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  string s1, s2;
  cin>>s1>>s2;
  bool result = isPermutation(s1,s2);

  if(result == false){
    cout<<"string1 is not permutation of string2"<<endl;
  }
  else{
    cout<<"string1 is permutation of string2"<<endl;
  }

  return 0;
}
