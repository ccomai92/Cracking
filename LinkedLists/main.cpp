#include "LinkedList.h"
#include <iostream> 
using namespace std; 

int main() {
    LinkedList list; 
    list.append(3); 
    list.append(4);
    list.append(2); 
    list.append(2);
    list.append(2); 
    list.append(2);
    list.append(2); 
    list.append(2);
    list.append(4); 
    list.append(5); 
    list.append(4); 

    list.dump(); 

    // list.removeDups2();
    cout << "Third From Last: " << list.kthToLast(3)->data << endl; 
 
    return 0; 
}