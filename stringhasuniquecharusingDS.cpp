#include <iostream>
using namespace std;

bool isStringhasUniqueCharDS(string str)
{
  int length = str.length();
  bool flag = true;

  if(length == 0){
    return true;
  }

  if(length == 1){
    return true;
  }

  int arry[256] = {0};

  for(int i=0; i<length; i++){
    int index = int(str[i]);
    if(arry[index] == 0){
      arry[index] = arry[index] + 1;
    }
    else{
      if(arry[index] > 0){
        cout<<"came in here for "<<str[i]<<" at index "<<i<<endl;
        flag = false;
        return flag;
      }
    }
  }

  return flag;

}

int main(){

  string str = "monalipatil";
  bool result = isStringhasUniqueCharDS(str);

  if(result == false){
    cout<<"given string has no unique characters"<<endl;
  }
  else{
    cout<<"given string has unique characters"<<endl;
  }

  return 0;
}
