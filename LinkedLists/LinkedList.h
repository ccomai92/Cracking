#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

#include <iostream> 
#include <map>
#include <set>
#include <stack>

struct Node {
    int data; 
    Node *next = nullptr;
}; 

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    bool append(int data); 
    bool push_front(int data); 
    bool remove(int data);
    bool removeDups1();
    bool removeDups2();  
    Node* kthToLast(int k); 
    bool partition(int input); 
    LinkedList sumLists1(LinkedList rhs); 
    LinkedList sumLists2(LinkedList rhs); 
    bool isPalindrome(); 

    void dump(); 

private:
    Node *head;
    int count;  

    Node* search(int data); 
    int sumListsHelper(Node *first, Node *second, LinkedList &result);
};

#endif