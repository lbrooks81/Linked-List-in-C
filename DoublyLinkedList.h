#ifndef LINKEDLISTS_DOUBLYLINKEDLIST_H
#define LINKEDLISTS_DOUBLYLINKEDLIST_H

#include "LinkedListBase.h"

namespace LinkedList
{
    template<typename T>
    class DoublyLinkedList : public LinkedListBase<T>
    {
    private:
        class Node
        {
        public:
            T value;
            Node* next;
            Node* previous;
            Node(T value): value(value), next(nullptr), previous(nullptr){}
        };
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList(): head(nullptr), tail(nullptr){}
        DoublyLinkedList(T value);
        ~DoublyLinkedList() override;
        T & operator[](size_t index) const override;
        void insert(T value) override;
        void insert(T value, int index) override;
        void remove(T value) override;
        void removeAt(size_t index) override;
        int search(T value) override;
        void clear() override;
    };
    template class DoublyLinkedList<int>;

}

#endif //LINKEDLISTS_DOUBLYLINKEDLIST_H
