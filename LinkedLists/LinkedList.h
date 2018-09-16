#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

#include <iostream> 
#include <map>
#include <set>

struct Node {
    int data; 
    Node *next = nullptr; 
}; 

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    bool append(int data); 
    bool remove(int data);
    bool removeDups1();
    bool removeDups2();  
    Node* kthToLast(int k); 

    void dump(); 

private:
    Node *head;
    int count;  
};

#endif