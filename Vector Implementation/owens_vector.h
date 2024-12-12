#ifndef OWENS_VECTOR_H
#define OWENS_VECTOR_H

#include <iostream>
#include "owens_iterator.h"
using namespace std;

template <typename T> class owens_vector {
private:
    // array to hold data
    T* m_array;
    size_t m_size;
    T* m_begin;
    T* m_end;

public:
    owens_vector();
    owens_vector(size_t num);
    ~owens_vector();
    T& operator[](size_t index);
    void operator=(std::initializer_list<T> bracedInitializer);
    size_t size();
    void print();
    owens_iterator<T> begin();
    owens_iterator<T> end();
    void push_back(T value);
};
template <typename T> owens_vector<T>::owens_vector()
{
    m_array = new T[100];
    m_size = 100;
    m_begin = m_array;
    m_end = m_array + m_size;
}
template <typename T> owens_vector<T>::owens_vector(size_t num)
{
    m_array = new T[num];
    m_size = num;
    m_begin = m_array;
    m_end = m_array + m_size;
}
template <typename T> owens_vector<T>::~owens_vector<T>() {
    delete[] m_array;
}
template <typename T> T& owens_vector<T>::operator[](size_t index)
{
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_array[index];
}
template <typename T> void owens_vector<T>::operator=(std::initializer_list<T> bracedInitializer)
{
    // Ensure the new size matches the initializer list size
    if (bracedInitializer.size() > m_size) {
        delete[] m_array;
        m_size = bracedInitializer.size();
        m_array = new T[m_size];
    }
    else if (bracedInitializer.size() == 0) {
        m_size = 0;
        m_end = m_begin;
        return;
    }
    // Copy elements from the initializer list to the vector
    size_t index = 0;
    for (const T& value : bracedInitializer) {
        m_array[index] = value;
        index++;
    }
    m_end = m_begin + (--index);  //update m_end pointer to point to correct ending of array
    m_size = m_end - m_begin + 1;     //need to update m_size
}
template <typename T> size_t owens_vector<T>::size()
{
    return m_size;
}
template <typename T> void owens_vector<T>::print()
{
    for (const T* i = m_array; i < m_array + m_size; i++) {
        cout << *i << " ";
    }
}
template <typename T> owens_iterator<T> owens_vector<T>::begin()
{
    //need to return instance of owens_iterator pointing to beginning of array
    owens_iterator<T> iterator(m_begin, m_end);
    iterator.begin();
    return iterator;
}
template <typename T> owens_iterator<T> owens_vector<T>::end()
{
    //need to return instance of owens_iterator pointing to ending of array
    owens_iterator<T> iterator(m_begin, m_end);
    iterator.end();
    return iterator;
}
template <typename T> void owens_vector<T>::push_back(T value)
{
    //check if array is full
    if (m_end - m_begin == m_size) {
        //if full, double size of vector
        T* new_array = new T[m_size * 2];
        //copy elements over from old vector to new vector
        for (size_t i = 0; i < m_size; i++) {
            new_array[i] = m_array[i];
        }
        delete[] m_array;
        m_array = new T[m_size * 2]
        m_array = new_array;
        delete[] new_array;
        m_size++;
    }
    //else if array not full then add value to end
    else {
        m_end++;
        *m_end = value;
        m_size++;
    }
}
#endif // OWENS_VECTOR_H