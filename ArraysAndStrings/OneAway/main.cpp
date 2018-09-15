/*
    There are three types of edits that can be performed on string: 
    insert a character, remove a character, or replace a character. 
    Given two strings, write a function to check if they are one edit
    (or zro edits) away. 
    
    EXAMPLE:
        pale, ple -> true
        pales, pale -> true
        pale, bale -> true
        pale, bake -> false  
*/

#include <iostream> 
#include <string> 

using namespace std; 

bool check(string first, string second); 
bool checkInsertRemove(string longer, string shorter); 
bool checkReplace(string first, string second); 

int main() {
    cout << boolalpha; 

    cout << check("pale", "ple") << endl;
    cout << check("pales", "pale") << endl;
    cout << check("pale", "bale") << endl;
    cout << check("pale", "bake") << endl;

    return 0; 
}

bool check(string first, string second) {
    if (first.length() > second.length()) {
        return checkInsertRemove(first, second); 
    } else if (first.length() < second.length()) {
        return checkInsertRemove(second, first); 
    } else {
        return checkReplace(first, second); 
    }
}

bool checkInsertRemove(string longer, string shorter) {
    int difference = 0; 
    int index = 0; 

    for (int i = 0; i < longer.length(); i++) {
        char chLong = longer[i]; 
        char chShort = shorter[index]; 
        if (chLong != chShort) {
            if (difference > 0) {
                return false; 
            } else {
                difference++; 
            }
        } else {
            index++; 
        }                   
    }
    return true; 
    
}

bool checkReplace(string first, string second) {
    int difference = 0; 

    for (int i = 0; i < first.length(); i++) {
        char f = first[i]; 
        char s = second[i]; 
        if (f != s) {
            if (difference > 0) {
                return false; 
            }
            difference++; 
        } 
    }
    return true; 
}

