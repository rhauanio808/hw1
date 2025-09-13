#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    // Scenario 1: removing item from empty list to front of empty list
        ULListStr list1;

        std::cout << "scenario 1: remove from empty list \n";
        if (list1.empty()) {
            std::cout << "list empty \n";
        }
        
        if (list1.size() == 0) {
            std::cout << "size 0 \n";
        }

        // try removing elements
        list1.pop_back();
        std::cout << "removed nothing \n";
        list1.pop_front();
        std::cout << "removed nothing \n \n";

    // Scenario 1: removing item from empty list to an empty list
        ULListStr list2;

        std::cout << "scenario 2: add to an empty list \n";

        // add element to front
        std::cout << "add element: ";
        list2.push_front("1");
        
        std::cout << list2.front() << "\n";
        list2.pop_back();
        std::cout << "removed element \n";

        // add element to back
        std::cout << "add element: ";
        list2.push_back("2");
        std::cout << "\n";
        list2.pop_front();
        std::cout << "removed element \n \n";


    // Scenario 3: adding item to a non-empty list
        ULListStr list3;

        std::cout << "scenario 3: nonempty list with room on both ends \n";
        if (!list3.empty()) {
            std::cout << "list not empty \n";
        }
        
        std::cout << "list size: " << list3.size() << "\n \n";

    // Scenario 4:
    // try adding elements
    ULListStr list4;

    std::cout << " Scenario 4: nonempty list with no room on both ends \n";

    // Push elements so list is (3, 1, 2)
    list4.push_back("1");
    list4.push_back("2");
    list4.push_front("3");  

    std::cout << "list size after pushes: " << list4.size() << "\n"; // 3
    std::cout << "front element: " << list4.front() << "\n"; //  "3"
    std::cout << "back element: " << list4.back() << "\n";   // "2"


    // Pop from both ends
    std::cout << "remove element: ";
    list4.pop_front();
    std::cout << "front element: " << list4.front() << "\n"; //  "3"
    list4.pop_back();  // remove

    std::cout << "List size after pops: " << list4.size();
    std::cout << "Front element (only Z left): " << list4.front();

}
