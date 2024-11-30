#ifndef LINKEDLISTS_SINGLYLINKEDLIST_H
#define LINKEDLISTS_SINGLYLINKEDLIST_H

#include "LinkedListBase.h"

namespace LinkedList
{
    template <typename T>
    class SinglyLinkedList : public LinkedListBase<T>
    {
    private:
        class Node
        {
        public:
            T value;
            Node* next;
            Node(T value): value(value), next(nullptr){}
        };

        Node* head;
    public:
        SinglyLinkedList(): head(nullptr){}
        SinglyLinkedList(T value);
        ~SinglyLinkedList() override;
        T & operator[](size_t index) const override;
        void insert(T value) override;
        void insert(T value, int index) override;
        void remove(T value) override;
        void removeAt(size_t index) override;
        int search(T value) override;
        void clear() override;
    };
    template class SinglyLinkedList<int>;

}

#endif //LINKEDLISTS_SINGLYLINKEDLIST_H
