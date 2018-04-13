#include <iostream>
#include <map>
using namespace std;


void IsAnagram(string &s1, string &s2)
{
  int length1 = s1.length();
  int length2 = s2.length();

  if(length1 != length2)
  {
    cout<<"Invalid strings";
    return;
  }

  if(length1 == 0 && length2 == 0)
  {
    cout<<"anagrams";
    return;
  }

  map<int, int> mymap;
  map<int, int>::iterator it;
  mymap.insert(pair<int,int>(s1[0], 1));

  for(int i=1; i<length1; i++)
  {
    it = mymap.find(s1[i]);
    if(it != mymap.end())
    {
      //found
      it->second = it->second + 1;
    }
    else
    {
      mymap.insert(pair<int,int>(s1[i], 1));
    }
  }

  for(int i=0; i<length1; i++)
  {
    it = mymap.find(s2[i]);
    if(it != mymap.end())
    {
      //found
      it->second = it->second - 1;
    }
    else
    {
      mymap.insert(pair<int,int>(s2[i], 1));
    }
  }

 for(it=mymap.begin(); it!= mymap.end(); it++)
 {
   if(it->second != 0)
   {
     cout<<"not anagram";
     return;
   }
 }

cout<<"anagram";
return;

}

int main()
{
  string s1 = "";
  string s2 = "";
  IsAnagram(s1, s2);
  return 0;
}
