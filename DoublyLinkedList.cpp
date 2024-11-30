#include <stdexcept>

#include "DoublyLinkedList.h"

namespace LinkedList
{
    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList(T value)
    {
        this->head = new Node(value);
        this->tail = this->head;
        this->count = 1;
    }

    template <typename T>
    DoublyLinkedList<T>::~DoublyLinkedList()
    {
        clear();
    }

    template <typename T>
    T& DoublyLinkedList<T>::operator[](size_t index) const
    {
        if (index >= this->count || index < 0)
        {
            throw std::out_of_range("Index was out of range");
        }

        Node* current = nullptr;

        if (index < this->count / 2)
        {
            current = this->head;

            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
        }
        else
        {
            current = this->tail;

            for (int i = this->count - 1; i > index; i--)
            {
                current = current->previous;
            }
        }

        return current->value;
    }

    template <typename T>
    void DoublyLinkedList<T>::insert(T value)
    {
        insert(value, this->count);
    }

    template <typename T>
    void DoublyLinkedList<T>::insert(T value, int index)
    {
        if (index > this->count || index < 0)
        {
            throw std::out_of_range("Index was out of range");
        }

        Node* newNode = new Node(value);

        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else if (index == 0)
        {
            newNode->next = this->head;
            newNode->previous = nullptr;
            this->head->previous = newNode;
            this->head = newNode;
        }
        else if (index == this->count)
        {
            this->tail->next = newNode;
            newNode->next = nullptr;
            newNode->previous = this->tail;
            this->tail = newNode;
        }
        else
        {
            Node* current = nullptr;

            if (index < this->count / 2)
            {
                current = this->head;

                for (int i = 0; i < index; i++)
                {
                    current = current->next;
                }

                newNode->next = current->next;
                newNode->previous = current;

                current->next->previous = newNode;
                current->next = newNode;
            }
            else
            {
                current = this->tail;

                for (int i = this->count - 1; i > index; i--)
                {
                    current = current->previous;
                }

                newNode->next = current->next;
                newNode->previous = current;

                current->next->previous = newNode;
                current->next = newNode;
            }
        }

        this->count++;
    }

    template <typename T>
    void DoublyLinkedList<T>::remove(T value)
    {
        Node* current = this->head;

        while (current != nullptr && current->value != value)
        {
            current = current->next;
        }
        if (current != nullptr)
        {
            if (current == this->head)
            {
                Node* nodeToDelete = this->head;
                this->head = this->head->next;
                delete nodeToDelete;
                this->head->previous = nullptr;
            }
            if (current == this->tail)
            {
                Node* nodeToDelete = this->tail;
                this->tail = this->tail->previous;
                delete nodeToDelete;
                this->tail->next = nullptr;
            }
            else
            {
                current->previous->next = current->next;
                current->next->previous = current->previous;
                delete current;
            }

            this->count--;
        }

    }

    template <typename T>
    void DoublyLinkedList<T>::removeAt(size_t index)
    {
        if (index < 0 || index >= this->count)
        {
            throw std::out_of_range("Index was out of range");
        }
        if (index == 0)
        {
            Node* temp = this->head->next;
            delete this->head;
            this->head = temp;
            this->head->previous = nullptr;
        }
        else if (index == this->count -1)
        {
            Node* temp = this->tail->previous;
            delete this->tail;
            this->tail = temp;
            this->tail->next = nullptr;
        }
        else
        {
            Node* current = nullptr;

            if (index < this->count / 2)
            {
                current = this->head;

                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
            }
            else
            {
                current = this->tail;

                for (int i = this->count - 1; i < index - 1; i++)
                {
                    current = current->previous;
                }
            }

            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            current->next->previous = current;
            delete nodeToDelete;
        }

        this->count--;
    }

    template <typename T>
    int DoublyLinkedList<T>::search(T value)
    {
        Node* current = this->head;

        for (int i = 0; i < this->count; i++)
        {
            if (current->value == value)
            {
                return i;
            }

            current = current->next;
        }

        return -1;
    }

    template <typename T>
    void DoublyLinkedList<T>::clear()
    {
        Node* current = this->head;
        for(size_t i = 0; i < this->count; i++)
        {
            Node* temp = current->next;
            delete [] current;
            current = temp;
        }

        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
}