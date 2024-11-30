#include "LinkedListBase.h"

#include <ostream>

namespace LinkedList
{
    template <typename T>
    bool LinkedListBase<T>::isEmpty()
    {
        return this->count == 0;
    }

    template<typename T>
    std::string LinkedListBase<T>::toString()
    {
        std::string s = "";
        for(int i = 0; i < this->count; i++)
        {
            s += "[" + std::to_string(i) + "]: " + std::to_string(this->operator[](i)) + " ";
        }
        return s;
    }

    template <typename T>
    size_t LinkedListBase<T>::getCount() const
    {
        return this->count;
    }

    template class LinkedListBase<int>;
}
