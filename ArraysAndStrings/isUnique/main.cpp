/*
    Implement an algorithm to determine if a string has all unique characters.
    What if you cannot use additional datastructure? 
*/

#include <iostream>
#include <string>
#include <map>

using namespace std; 

bool isUnique1(string input);
bool isUnique2(string input);
bool isUnique3(string input); 

int main() {
    string first = "asdf"; 
    string second = "fffff";
    string third = "lijklijkl";

    cout << boolalpha;  

    cout << "First method: " << endl; 
    cout << first << ":  " << isUnique1(first) << endl;
    cout << second << ": " << isUnique1(second) << endl;
    cout << third << ": " << isUnique1(third) << endl;

    cout << "Second method: " << endl; 
    cout << first << ":  " << isUnique2(first) << endl;
    cout << second << ": " << isUnique2(second) << endl;
    cout << third << ": " << isUnique2(third) << endl;

    cout << "Third method: " << endl; 
    cout << first << ":  " << isUnique3(first) << endl;
    cout << second << ": " << isUnique3(second) << endl;
    cout << third << ": " << isUnique3(third) << endl; 

    return 0; 
}

// map has value initilized as 0 
bool isUnique2(string input) {
    map<char, int> map;
    for (int i = 0; i < input.length(); i++) {
        char temp = input[i]; 
        // cout << map[temp] << endl;
        if (map[temp] != 0) {
            return false;
        } 
        map[temp]++; 
    } 
    return true; 
}

// checking without using extra datastructure 
bool isUnique3(string input) {
    int checker = 0; 

    for (int i = 0; i < input.length(); i++) {
        int ch = input[i] - 'a'; 
        if ((checker & (1 << ch)) > 0) {
            return false; 
        }
        checker = checker | (1  << ch); 
    }
    return true; 
}



// first method came up 
bool isUnique1(string input) {
    if (input.length() > 128) {
        return false; 
    }
    int list[128]; 
    for (int i = 0; i < 128; i++) {
        list[i] = 0; 
        // cout << (char) i << " " << list[i] << endl; 
    }

    for (int i = 0; i < input.length(); i++) {
        char temp = input[i]; 
        if (list[temp] > 0) {
            return false;
        }
        list[temp]++; 
    }
    return true;  

}