#include "LinkedList.h"
#include <iostream> 
using namespace std; 

int main() {
    LinkedList list1; 
    list1.append(6); 
    list1.append(1);
    list1.append(6);


    LinkedList list2;
    list2.append(2);
     
    

    cout << list1.isPalindrome() << endl;
    cout << list2.isPalindrome() << endl;
    
    return 0; 
}