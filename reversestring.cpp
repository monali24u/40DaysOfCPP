#include <iostream>
using namespace std;

void reverse(char *str){
  char *start = str;
  char *end = str;

  while(*end != '\0'){
    end++;
  }
  end--;

  while(start < end){
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }

}

int main(){
  string s = "monali";
  char *str = &s[0];
  reverse(str);
  cout<<str;
  return 0;
}
