/*
    Implement a method to perform basic string compression 
    using the counts of repeated characters. 
    For example, the string aabccccaaa would become a2b1c5a3. 
    If the "compressed" string would not become smaller than
    the original string, your method should return the original 
    stirng. You can assume the string has only uppercase and 
    lowercase letters(a - z)

    Q for clarificaiton 
        smaller than the original string means < or <= ? 
*/ 

#include <iostream> 
#include <string> 

using namespace std; 

string compress(string input); 

int main() {
    cout << boolalpha; 

    cout << compress("aabcccccaaa") << endl;
    cout << compress("aabbcc") << endl;
    cout << compress("aaacccccbaaa") << endl;
    cout << compress("KrisKwon") << endl;
    return 0; 
}

string compress(string input) {
    string result = ""; 
    char ch = input[0]; 
    int count = 0; 

    for (int i = 0; i < input.length(); i++) {
        char temp = input[i]; 
        if (temp != ch) {
            result.append(1, ch); 
            result.append(to_string(count)); 
            // cout << "ch : " << ch << endl; 
            // cout << "count: " << count << endl;
            // cout << "result: " << result << endl;  
            ch = temp; 
            count = 1; 
        } else {
            count++; 
        }
    }
    // result += ch;
    // result += to_string(count); 
    result.append(1, ch); 
    result.append(to_string(count)); 

    // cout << "ch : " << ch << endl; 
    // cout << "count: " << count << endl;
    // cout << "result: " << result << endl;  

    if (input.length() <= result.length()) {
        return input; 
    }
    return result; 
}

