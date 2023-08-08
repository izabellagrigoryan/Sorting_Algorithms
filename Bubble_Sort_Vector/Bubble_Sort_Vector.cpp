// Bubble_Sort_Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Vector.h"

template  <typename T>
void Vector<T>::bubble_sort()
{
    int step = 1;
    while (step)
    {
        step = 0;
        for (int i = 0; i < get_size() - 1; i++)
        {
            if (this->m_ptr[i] > this->m_ptr[i + 1])
            {
                step = 1;
                int temp = this->m_ptr[i];
                this->m_ptr[i] = this->m_ptr[i + 1];
                this->m_ptr[i + 1] = temp;
            }
        }
    }
}

template  <typename T>
void Vector<T>::init()
{
    for (int i = 0; i < 10; ++i)
    {
        this->push_back(rand() / 100 + 1);
    }
}

int main()
{
    Vector<int> m_vector;
    m_vector.init();
    m_vector.print();
    m_vector.bubble_sort();
    m_vector.print();

}
