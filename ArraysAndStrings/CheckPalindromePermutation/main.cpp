/*
    Given a string, write a function to heck if it is a 
    permutation of a palindrome. A palindrome is a word or 
    phrase that is the same forwards and backwards. A 
    permutation is a rearrangement of letters. The palindrome
    does not need to be limited to just dictionary words. 
*/ 

#include <iostream>
#include <string>
#include <map>
#include <cctype> // tolower(), toupper() 

using namespace std; 

bool check(string input); 

int main() {

    cout << boolalpha; 
    cout << check("Tact Coa") << endl; 
    cout << check("") << endl; 

    return 0; 
}

bool check(string input) {
    map<char, int> mymap; 
    int spaceCount = 0; 

    for (int i = 0; i < input.length(); i++) {
        char temp = tolower(input[i]); 
        if (temp != ' ')
            mymap[temp]++; 
        else 
            spaceCount++; 

    }

   
    int oddCount = 0; 
    int size = input.length() - spaceCount; 
    for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        if (it->second % 2 == 1) {
            oddCount++; 
        }
    }
    if (size % 2 == 1) { // odd character number
        if (oddCount != 1) {
            return false; 
        }
    } else { // even character number 
        if (oddCount != 0) {
            return false;
        }
    }
    return true; 
}