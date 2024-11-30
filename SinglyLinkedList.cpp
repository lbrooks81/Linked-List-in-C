#include <stdexcept>

#include "SinglyLinkedList.h"

#include <iostream>

namespace LinkedList
{
    template<typename T>
    SinglyLinkedList<T>::SinglyLinkedList(T value): head(new Node(value))
    {
        this->count = 1;
    }

    template<typename T>
    SinglyLinkedList<T>::~SinglyLinkedList()
    {
        SinglyLinkedList::clear();
    }

    template<typename T>
    T & SinglyLinkedList<T>::operator[](size_t index) const
    {
        if (index >= this->count || index < 0)
        {
            throw std::out_of_range("Index was out of range");
        }

        Node* current = this->head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->value;
    }

    template<typename T>
    void SinglyLinkedList<T>::insert(T value)
    {
        insert(value, this->count);
    }

    template<typename T>
    void SinglyLinkedList<T>::insert(T value, int index)
    {
        if (index > this->count || index < 0)
        {
            throw std::out_of_range("Index was out of range");
        }

        Node* newNode = new Node(value);

        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else if (index == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        else
        {
            Node* current = this->head;

            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
        this->count++;
    }

    template<typename T>
    void SinglyLinkedList<T>::remove(T value)
    {
        Node* current = this->head;
        Node* previous = nullptr;

        for (int i = 0; i < this->count; i++)
        {
            if (current->value == value)
            {
                if (previous == nullptr)
                {
                    this->head = this->head->next;
                }
                else
                {
                    previous->next = current->next;
                    delete current;
                }

                this->count--;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    template<typename T>
    void SinglyLinkedList<T>::removeAt(size_t index)
    {
        if (index > this->count || index < 0)
        {
            throw std::out_of_range("Index was out of range");
        }
        if (index == 0)
        {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        else
        {
            Node* current = this->head;

            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
        }

        this->count--;

    }

    template<typename T>
    int SinglyLinkedList<T>::search(T value)
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

    template<typename T>
    void SinglyLinkedList<T>::clear()
    {
        Node* current = head;
        for(size_t i = 0; i < this->count; i++)
        {
            Node* temp = current->next;
            delete current;
            current = temp;
        }

        this->head = nullptr;
        this->count = 0;
    }
}

