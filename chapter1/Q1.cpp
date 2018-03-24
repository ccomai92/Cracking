// Is Unique:
// Implement an algorithm to determine if a string has all unique characters. 
// What if you cannot use additional data structures? 
#include <string>
#include <vector>
#include <iostream> 
using namespace std; 

bool isUnique(string word); 

int main()
{
  string first = "start";
  string second = "second"; 
  cout << isUnique(first) << endl; 
  cout << isUnique(second) << endl;
  return 0; 
}

bool isUnique(string word)
{ 
  if (word.size() > 128)
  {
    return false; 
  }
 
  bool list[128]; 
  
  for (int i = 0; i < word.length(); i++)
  {
    int temp = word[i]; 
    if (list[temp])
    {
      return false;
    }
    else 
    {
      list[temp] = true;
    }
  }
  return true;
}
