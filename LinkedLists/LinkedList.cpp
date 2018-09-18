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

bool LinkedList::push_front(int data) {
    Node *temp = this->head;
    this->head = new Node{data, temp}; 
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

// partition a linked list around a value x 
// such that all nodes less than x comes before
// all nodes greater than or equal to x
// The partition element x can appear anywhere 
// in the "right partition" 
bool LinkedList::partition(int input) {
    Node *result = this->search(input);
    if (result == nullptr) {
        std::cerr << "No such element" << std::endl;
        return false;
    }

    Node *smallHead = nullptr;
    Node *smallEnd = nullptr;
    Node *bigHead = nullptr;
    Node *bigEnd = nullptr; 
     

    while (this->head != nullptr) {
        Node *current = this->head;
        Node *next = this->head->next;
        if (current->data < input) {
            if (smallHead == nullptr) {
                smallHead = current;
                smallEnd = current;
                smallEnd->next = nullptr; 
            } else {
                Node *clipper = smallHead; 
                smallHead = current; 
                smallHead->next = clipper; 
            }
        } else {
            if (bigHead == nullptr) {
                bigHead = current;
                bigEnd = current;
                bigEnd->next = nullptr; 
            } else {
                Node *clipper = bigHead;
                bigHead = current;
                bigHead->next = clipper; 
            }
        }
        this->head = next;
    }
    this->head = smallHead; 
    if (smallHead == nullptr) {
        this->head = bigHead; 
    } else {
        smallEnd->next = bigHead;
    }
     
    return true;
}

// You are given two non-empty linked lists 
// representing two non-negative integers.
// The digits are stored in reverse order and
// each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.
LinkedList LinkedList::sumLists1(LinkedList rhs) {
    LinkedList result; 
    int sum = this->head->data + rhs.head->data; 
    int remainder = sum % 10; 
    int quotient = sum / 10; 
    result.push_front(remainder); 

    Node *first = this->head->next; 
    Node *second = rhs.head->next; 

    while (first != nullptr && second != nullptr) {
        sum = first->data + second->data + quotient;
        quotient = sum / 10; 
        remainder = sum % 10; 
        result.push_front(remainder); 
        first = first->next;
        second = second->next; 
    }

    while (first != nullptr) {
        sum = first->data + quotient; 
        quotient = sum / 10; 
        remainder = sum % 10; 
        result.push_front(remainder);
        first = first->next; 
    }

    while (second != nullptr) {
        sum = second->data + quotient; 
        quotient = sum / 10;
        remainder = sum % 10; 
        result.push_front(remainder);
        second = second->next;
    }

    if (quotient != 0) {
        result.push_front(quotient); 
    }
    return result;
}

LinkedList LinkedList::sumLists2(LinkedList rhs) {
    LinkedList result; 
    Node *first = this->head;
    Node *second = rhs.head;
    int quotient = sumListsHelper(first, second, result); 
    if (quotient != 0) {
        result.push_front(quotient);
    }

    return result;

}

int LinkedList::sumListsHelper(Node *first, Node *second, LinkedList &result) {
    if (first == nullptr && second == nullptr) {
        return 0;
    } else if (first == nullptr) {
        int quotient = sumListsHelper(nullptr, second->next, result); 
        int sum = second->data + quotient; 
        int remainder = sum % 10;
        result.push_front(remainder);
        return sum / 10;
    } else if (second == nullptr) {
        int quotient = sumListsHelper(first->next, nullptr, result);
        int sum = first->data + quotient;
        int remainder = sum % 10;
        result.push_front(remainder);
        return sum / 10;
    } else {
        int quotient = sumListsHelper(first->next, second->next, result);
        int sum = first->data + second->data + quotient;
        int remainder = sum % 10;
        result.push_front(remainder);
        return sum / 10;
    }
}

bool LinkedList::isPalindrome() {

    return true;
}

void LinkedList::dump() {
    Node *temp = this->head; 
    while (temp != nullptr) {
        std::cout << temp->data << " "; 
        temp = temp->next;
    }
    std::cout << std::endl; 
}

Node* LinkedList::search(int data) {
    if (this->head == nullptr) {
        return nullptr;
    }
    Node *current = this->head;

    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}