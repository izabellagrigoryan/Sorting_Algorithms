// Bubble_Sort_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "List.h"
template class Node<int>; // Example with double
template class Node<double>; // Example with double

template class List<int>; // Example with int
template class List<double>; // Example with double

template <typename T>
void List<T>::init()
{
    for (int i = 0; i < 10; ++i)
    {
        this->push(rand() / 100 + 1);
    }
}

template <typename T>
void List<T>::bubble_sort()
{
    int step = 1;

    Node<T>* tmp1 = m_head;
    Node<T>* tmp2 = m_head;

    while (step)
    {
        step = 0;

        while (tmp2 != nullptr)
        {
            tmp2 = tmp2->next;

            if (tmp2 != nullptr)
            {
                if (tmp1->m_value > tmp2->m_value)
                {
                    step = 1;
                    int temp = tmp1->m_value;
                    tmp1->m_value = tmp2->m_value;
                    tmp2->m_value = temp;
                }
            }
            tmp1 = tmp1->next;
        }

        tmp1 = m_head;
        tmp2 = m_head;
    }
}

int main()
{
    List<int> m_list;
    m_list.init();
    m_list.print();
    m_list.bubble_sort();
    m_list.print();
}

