#include "Array.h"

template class Array<int>;

template <typename T>
Array<T>::Array(const Array<T>& array)
{
    this->size = array.size;

    this->ptr = new T[size];
    for (int i = 0; i < size; i++)
        this->ptr[i] = array.ptr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& array)
{
    if (this != &array)
    {
        delete[] ptr;
        this->size = array.size;

        this->ptr = new T[size];
        for (int i = 0; i < size; i++)
            this->ptr[i] = array.ptr[i];
    }
    return *this;
}

template <typename T>
Array<T>::Array(Array<T>&& arr) noexcept
{
    if (this != &arr)
    {
        this->size = arr.size;
        this->ptr = arr.ptr;

        arr.ptr = nullptr;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& arr) noexcept
{
    if (this != &arr)
    {
        delete[] this->ptr;
        this->ptr = nullptr;

        this->size = arr.size;
        this->ptr = arr.ptr;

        arr.size = 0;
        arr.ptr = nullptr;

    }
    return *this;
}

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
void Array<T>::push_back(T element)
{
    T* newptr = new T[size + 1];

    for (int i = 0; i < this->size; i++)
        newptr[i] = this->ptr[i];

    delete[] this->ptr;
    this->ptr = newptr;
    this->ptr[size] = element;
    this->size++;
}

template <typename T>
void Array<T>::pop_back()
{
    T* newptr = new T[size - 1];

    for (int i = 0; i < this->size - 1; i++)
        newptr[i] = this->ptr[i];

    delete[] this->ptr;
    this->ptr = newptr;

    this->size--;
}

template <typename T>
void Array<T>::print_array()
{
    for (int i = 0; i < size; i++)
        std::cout << this->ptr[i] << ",  ";
    std::cout << std::endl;
}


