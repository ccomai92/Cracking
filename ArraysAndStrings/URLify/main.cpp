/*
    Write a method to replace all spaces in a string with '%20'. 
    You may assume that the string has sufficient space at the 
    end to hold the additional characters, and that you are given
    the "true length of the string.

    EXAMPLE: 
        INPUT: "Mr John Smith    ", 13
        OUTPUT: "Mr%20John%20Smith" 
*/ 

#include <iostream>
#include <string> 

using namespace std; 

string replace(string input, int wordSize); 

int main() {
    
    cout << "\"" << replace("Mr John Smith    ", 13) << "\"" << endl;
    return 0; 
}

// O(N) time complexity
string replace(string input, int wordSize) {
    string result = "";
    int size = input.length(); 
    char list[size]; 

    int index = wordSize - 1; 

    // init -> check? execute: end loop -> increment
    // check?-> execute -> increment

    for (int i = size - 1; i >= 0; i--) {
        char temp = input[index]; 
        if (temp == ' ') {
            list[i] = '0';
            list[i - 1] = '2';
            list[i - 2] = '%';
            i -= 2; 
        } else {
            list[i] = temp; 
        }
        index--; 
    }
    for (int i = 0; i < size; i++) {
        result += list[i]; 
    }
    return result; 
}