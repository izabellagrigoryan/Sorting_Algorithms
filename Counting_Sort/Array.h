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
            this->ptr[i] = rand() % 10 + 1;
    }
    ~Array(){ delete[] ptr; }

    T operator[](int i) const;
    T& operator[](int i);
    int getsize();
    void print_array();
};

#endif
