#ifndef LINKEDLISTS_LINKEDLISTBASE_H
#define LINKEDLISTS_LINKEDLISTBASE_H

#include <string>

using namespace std;

namespace LinkedList
{
    template<typename T>
    class LinkedListBase
    {
    protected:
        size_t count;
        //* Making this protected ensures that it cannot be instantiated outside of the children classes
        LinkedListBase()
        {
            count = 0;
        }
    public:
        bool isEmpty();
        LinkedListBase(T value);
        virtual ~LinkedListBase() = default;

        virtual T & operator[](size_t index) const = 0;
        virtual void insert(T value) = 0;
        virtual void insert(T value, int index) = 0;
        virtual void remove(T value) = 0;
        virtual void removeAt(size_t index) = 0;
        virtual int search(T value) = 0;
        virtual void clear() = 0;
        virtual std::string toString();
        size_t getCount() const;
    };
}

#endif //LINKEDLISTS_LINKEDLISTBASE_H
