#include <iostream>
using namespace std;

bool isStringhasUniqueChar(string str)
{
  int length = str.length();
  bool flag = true;

  if(length == 0){
    return true;
  }

  if(length == 1){
    return true;
  }

  for(int i=0; i<length; i++){

    char tocompare = str[i];

    for(int j=i+1; j<length; j++){

      char compareWith = str[j];

      if(tocompare == compareWith){
	      cout<<"come in here "<<tocompare<<" "<<compareWith<<endl;
        flag = false;
        return flag;
      }

    }

  }
  return flag;

}

int main(){

  string str = "monalipatil";
  bool result = isStringhasUniqueChar(str);

  if(result == false){
    cout<<"given string has no unique characters"<<endl;
  }
  else{
    cout<<"given string has unique characters"<<endl;
  }

  return 0;
}
