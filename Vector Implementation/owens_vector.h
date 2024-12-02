#ifndef OWENS_VECTOR_H
#define OWENS_VECTOR_H

#include <iostream>
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
    T& operator[](int index);
    void operator=(std::initializer_list<T> bracedInitializer);
    size_t size();
    void print();
    class owens_iterator {
    private:
        T* m_pointer;

    public:
        void owens_iterator_begin() {
            //set value of owens_iterator pointer to beginning of array
            m_pointer = m_begin;
        }
        void owens_iterator_end() {
            //set value of owens_iterator pointer to ending of array
            m_pointer = m_end;
        }
        T operator*() {
            //return value pointed to by iterator
            return *m_pointer;
        }
        void operator++() {
            //increment owens_iterator
            if (m_pointer < m_end) {
                m_pointer++;
            }
        }
        void operator--() {
            //decrement owens_iterator
            if (m_pointer > m_begin) {
                m_pointer--;
            }
        }
    };
    owens_iterator begin() {
        //need to return instance of owens_iterator pointing to beginning of array
        owens_iterator iterator();
        iterator.owens_iterator_begin();
        return iterator;
    }
    owens_iterator end() {
        //need to return instance of owens_iterator pointing to ending of array
        owens_iterator iterator();
        iterator.owens_iterator_end();
        return iterator;
    }
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
template <typename T> T& owens_vector<T>::operator[](int index)
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
}
template <typename T> size_t owens_vector<T>::size()
{
    return m_size;
}
template <typename T> void owens_vector<T>::print()
{
    for (const T& value : m_array) {
        cout << value << " ";
    }
}
#endif // OWENS_VECTOR_H