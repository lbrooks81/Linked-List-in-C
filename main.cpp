#include <float.h>
#include <iostream>

#include "DoublyLinkedList.h"
#include "LinkedListBase.h"
#include "SinglyLinkedList.h"
using namespace LinkedList;

void TestLinkedList();

int main()
{
    std::cout << "Hello world!" << std::endl;
    TestLinkedList();

}

void TestLinkedList()
{
    SinglyLinkedList<int> linkedList;
    std::cout << "Testing Singly Linked List..." << std::endl;

    for (int i = 0; i < 5; i++)
    {
        linkedList.insert(rand() % 100, i);
    }

    std::cout << linkedList.toString() << std::endl;
    std::cout << "Inserting 150 at index 2" << std::endl;
    linkedList.insert(150, 2);
    std::cout << "Inserting 112 at index 2" << std::endl;
    linkedList.insert(112, 2);

    std::cout << linkedList.toString() << std::endl;

    std::cout << "Searching for 150: " << linkedList.search(150) << std::endl;

    std::cout << "Size of linked list: " << linkedList.getCount() << std::endl;

    std::cout << "Removing 112" << std::endl;
    linkedList.remove(112);

    std::cout << linkedList.toString() << std::endl;

    std::cout << "Removing value at index 2" << std::endl;
    linkedList.removeAt(2);

    std::cout << linkedList.toString() << std::endl;

    std::cout << "Searching for 150: " << linkedList.search(150) << std::endl;

    std::cout << "Clearing list" << std::endl;

    linkedList.clear();

    std::cout << "Is empty? " << to_string(linkedList.isEmpty()) << std::endl;


}
