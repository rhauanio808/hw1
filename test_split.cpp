/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>

// print linked lists
void printList(Node* head);   

// free memory
void deleteList(Node* head);


int main(int argc, char* argv[])
{
    // Test 1: empty list
        Node* unsorted1 = NULL;

        // create sorted lists
        Node* odd1 = NULL;
        Node* even1 = NULL;

        
        // call split
        split(unsorted1, odd1, even1);

        // print test 1 output
        std::cout << "Test 1 - Empty list \n ";
        std::cout << "Original list: "; 
        printList(unsorted1);
        std::cout << "Even list: "; 
        printList(even1);
        std::cout << "Odd list: ";
        printList(odd1);
        std::cout << "\n";

        // free memory
        deleteList (odd1);
        deleteList (even1);


    // Test 2: 1 node
        Node* unsorted2 = new Node{2, NULL};

        // sorted lists
        Node* odd2 = NULL;
        Node* even2 = NULL;

        // call split
        split(unsorted2, odd2, even2);

        // print test 2 output
        std::cout << "Test 2 - single node \n";
        std::cout << "Original list: "; 
        printList(unsorted2);
        std::cout << "Even list: "; 
        printList(even2);
        std::cout << "Odd list: ";
        printList(odd2);
        std::cout << "\n";

        // free memory
        deleteList(odd2);
        deleteList(even2);


    // Test 3: all even list
        Node* unsorted3 = new Node{8, NULL};
        unsorted3->next = new Node{200, NULL};
        unsorted3->next->next = new Node{0, NULL};

        // sorted lists
        Node* odd3 = NULL;
        Node* even3 = NULL;

        // call split
        split(unsorted3, odd3, even3);

        // print test 3 output
        std::cout << "Test 3 - only even list: ";
        printList(unsorted3);
        std::cout << "Even list: ";
        printList(even3);
        std::cout << "Odd list: ";
        printList(odd3);
        std::cout << "\n";

        // free memory
        deleteList(odd3);
        deleteList (even3);
    
    
    // Test 4: standard mixed list
        Node* unsorted4 = new Node{8, NULL};
        unsorted4->next = new Node{1001, NULL};
        unsorted4->next->next = new Node{37, NULL};
        unsorted4->next->next->next = new Node{24, NULL};
        unsorted4->next->next->next->next = new Node{65, NULL};

        // sorted lists
        Node* odd4 = NULL;
        Node* even4 = NULL;

        // call split
        split(unsorted4, odd4, even4);

        // print test 4 output
        std::cout << "Test 4 - mixed list \n ";
        std::cout << "Original list: "; 
        printList(unsorted4);
        std::cout << "Even list: ";
        printList(even4);
        std::cout << "Odd list: ";
        printList(odd4);
        std::cout << "\n";

        // free memory
        deleteList(odd4);
        deleteList (even4);


    // Test 5: mixed list with duplicate
        Node* unsorted5 = new Node{3, NULL};
        unsorted5->next = new Node{222, NULL};
        unsorted5->next->next = new Node{222, NULL};
        unsorted5->next->next->next = new Node{4, NULL};
        unsorted5->next->next->next->next = new Node{66, NULL};
        unsorted5->next->next->next->next->next = new Node{6, NULL};

        // sorted lists
        Node* odd5 = NULL;
        Node* even5 = NULL;

        // call split
        split(unsorted5, odd5, even5);
        
        // print test 5 output
        std::cout << "Test 5 - mixed list w/ duplicates \n ";
        std::cout << "Original list: "; 
        printList(unsorted5);
        std::cout << "Even list: ";
        printList(even5);
        std::cout << "Odd list: ";
        printList(odd5);
        std::cout << "\n";

        // free memory
        deleteList(odd5);
        deleteList (even5);


}

// print linked lists
void printList(Node* head) {
    // list is empty
    if (head == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }
    // list is not empty
    while (head != NULL) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

// delete linked list and free memory
void deleteList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
