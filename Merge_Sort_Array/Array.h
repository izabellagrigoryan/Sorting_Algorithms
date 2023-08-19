#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
template <typename T>

class Array
{
    T* ptr;
    int size;
public:

    Array(int size) : size(size)
    {
        this->ptr = new T[this->size];
        for (int i = 0; i < this->size; i++)
            this->ptr[i] = rand() % 100 + 1;
    }

    ~Array()
    {
        delete[] ptr;
    }

    Array(const Array<T>& array);
    Array<T>& operator=(const Array<T>& array);
    Array(Array<T>&& arr) noexcept;
    Array<T>& operator=(Array<T>&& arr) noexcept;
    T operator[](int i) const;
    T& operator[](int i);
    int getsize();
    void push_back(T element);
    void pop_back();
    void print_array();


};

#endif
