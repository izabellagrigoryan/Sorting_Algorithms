#include "Array.h"

template class Array<int>;

template <typename T>
T Array<T>::operator[](int i) const
{
    if (i >= 0 && i <= this->size)

        return this->ptr[i];
    else
        return this->ptr[0];
}

template <typename T>
T& Array<T>::operator[](int i)
{
    if (i >= 0 && i <= this->size)

        return this->ptr[i];
    else
        return this->ptr[0];
}

template <typename T>
int Array<T>::getsize()
{
    return this->size;
}

template <typename T>
void Array<T>::print_array()
{
    for (int i = 0; i < size; i++)
        std::cout << this->ptr[i] << ",  ";
    std::cout << std::endl;
}


