/*
    Given two strings, write a method to decide if one is a permutation of the other. 
    
    Questions to ask before start, 
        1. What is permutation of the other? two strings have same length? only different 
        in charaters order? 
    
        2. Can I use extra datastructure? 
*/

#include<bits/stdc++.h> // C++ program to sort a string of characters
#include <iostream>
#include <string> 

using namespace std; 

bool checkPermutation1(string input1, string input2); 
bool checkPermutation2(string input1, string input2); 
void sortString(string &input); 


int main() {
    string first = "abababab";
    string second = "aaabbbac"; 

    cout << "Permutation Check 1: " << endl;
    cout << checkPermutation1("abababab", "aabbabab") << endl;
    cout << checkPermutation1("abababab", "cccccccc") << endl;
    cout << checkPermutation1("abcabcabc", "cbacbacba") << endl;
    cout << checkPermutation1("asdfabca", "abcasdff") << endl;

    cout << "Permutation check 2: " << endl;
    cout << checkPermutation2("abababab", "aabbabab") << endl;
    cout << checkPermutation2("abababab", "cccccccc") << endl;
    cout << checkPermutation2("abcabcabc", "cbacbacba") << endl;
    cout << checkPermutation2("asdfabca", "abcasdff") << endl;
 
    return 0; 
}

// utilizing map ---> O(N)
bool checkPermutation1(string input1, string input2) {
    if (input1.length() != input2.length()) {
        return false; 
    }
    map<char, int> mymap; 
    for (int i = 0; i < input1.length(); i++) {
        char temp = input1[i]; 
        mymap[temp]++; 
    }

    /*
    for (map<char, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        cout << i->first << " " << i->second << endl; 
    }*/

    for (int i = 0; i < input2.length(); i++) {
        char temp = input2[i]; 
        mymap[temp]--;
        if (mymap[temp] < 0) {
            return false;
        }
         
    }

    return true; 
}

// sorting ---> O(N log N)
bool checkPermutation2(string input1, string input2) {
    if (input1.length() != input2.length()) {
        return false;
    }

    sortString(input1); 
    sortString(input2); 

    cout << "check: " << input1 << endl;
    cout << "check: " << input2 << endl;

    for (int i = 0; i < input1.length(); i++) {
        if (input1[i] != input2[i]) {
            return false;
        }
    }
    return true; 
}

// c++ std libray sort()
void sortString(string &input) {
   sort(input.begin(), input.end());
}