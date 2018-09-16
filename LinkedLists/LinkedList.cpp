#include "LinkedList.h"

LinkedList::LinkedList(): head(nullptr), count(0) {}

LinkedList::~LinkedList() {
    std::cout << "Destructor" << std::endl;
    while (this->head != nullptr) {  
        this->dump();
        Node *temp = this->head->next; 
        delete this->head; 
        this->head = temp; 
        
    }
}

bool LinkedList::append(int data) {
    Node *newNode = new Node{data, nullptr};
    // std::cout << newNode->data << std::endl;
    if (this->head == nullptr) {
        this->head = newNode; 
        return true; 
    }
    Node *temp = this->head; 
    while (temp->next != nullptr) {
        temp = temp->next; 
    }

    temp->next = newNode;
    this->count++;  
    return true;
}

bool LinkedList::remove(int data) {
    if (this->head == nullptr) {
        std::cerr << "List is empty" << std::endl; 
        return false; 
    } 

    Node *temp; 
    if (this->head->data == data) {
        temp = head; 
        head = head->next; 
        delete temp; 
        this->count--; 
        return true; 
    }
    temp = this->head;

    while (temp->next != nullptr) {
        if (temp->next->data == data) {
            Node *clipper = temp->next; 
            temp->next = temp->next->next; 
            delete clipper; 
            this->count--; 
            return true; 
        }
        temp = temp->next; 
    }

    return false; 
}

// remove duplicates from an unsorted linked list. 
// Runtime becomes O(N)
bool LinkedList::removeDups1() {
    std::set<int> history; 
    if (this->head == nullptr) {
        std::cerr << "empty list" << std::endl; 
        return false; 
    }
    Node *current = this->head; 
    history.insert(this->head->data); 

    while (current->next != nullptr) {
        int data = current->next->data; 
        std::set<int>::iterator it = history.find(data); 
        if (it == history.end()) { // not found
            history.insert(data);
            current = current->next;   
        } else {
            Node *temp = current->next; 
            current->next = temp->next;
            delete temp; 
            // std::cout << "insde" << std::endl;
            // this->dump(); 
        }
    } 

    return true; 
}

// remove duplicates from an unsorted linked list.
// what if I can not use a temporary buffer? (
// runtime would be O(N^2)
bool LinkedList::removeDups2() {
    if (this->head == nullptr) {
        std::cerr << "empty list" << std::endl; 
        return false; 
    }

    Node *current1 = this->head;  

    while (current1 != nullptr && current1->next != nullptr) {
        Node *current2 = current1;
        while (current2->next != nullptr) {
            if (current1->data == current2->next->data) {
                Node *temp = current2->next; 
                current2->next = temp->next; 
                delete temp; 
            } else {
                current2 = current2->next; 

            }
            // std::cerr << "inside" << std::endl;
            // this->dump(); 
        }
        // be careful with edge case where remove lastnode 
        // then current->next = nullptr; 
        // However, happen to check current1->next != nullptr will
        // cause segmentation fault. 
        current1 = current1->next;
    }

    return true; 
}

// if k is bigger than the size, return nullptr; 
// What if I don't have count variable? 
Node* LinkedList::kthToLast(int k) { 
    if (k == 0) {
        k = 1;
    }

    Node *current1 = this->head;
    Node *current2 = this->head; 
    for (int i = 0; i < k; i++) {
        if (current1 == nullptr) {
            return nullptr; 
        }
        current1 = current1->next;
    }

    while (current1 != nullptr) {
        current1 = current1->next;
        current2 = current2->next;
    }
    

    return current2; 
}

void LinkedList::dump() {
    Node *temp = this->head; 
    while (temp != nullptr) {
        std::cout << temp->data << " "; 
        temp = temp->next;
    }
    std::cout << std::endl; 
}