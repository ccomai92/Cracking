#include "LinkedList.h"
#include <iostream> 
using namespace std; 

int main() {
    LinkedList list1; 
    list1.append(7); 
    list1.append(1);
    list1.append(6);

    LinkedList list2;
    list2.append(5); 
    list2.append(9);
    list2.append(2);

    list1.sumLists(list2).dump(); 
    
    return 0; 
}