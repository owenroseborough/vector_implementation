#ifndef OWENS_VECTOR_H
#define OWENS_VECTOR_H

#include <iostream>
using namespace std;

template <typename T> class owens_vector {
private:
    // array to hold data
    T* m_array;
    size_t m_size;

public:
    owens_vector();
    owens_vector(size_t num);
    ~owens_vector();
    T& operator[](int index);
    void operator=(std::initializer_list<T> bracedInitializer);
    size_t size();
    void print();
};
template <typename T> owens_vector<T>::owens_vector()
{
    m_array = new T[100];
    m_size = 100;
}
template <typename T> owens_vector<T>::owens_vector(size_t num)
{
    m_array = new T[num];
    m_size = num;
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
    // Copy elements from the initializer list to the vector
    size_t index = 0;
    for (const T& value : bracedInitializer) {
        m_array[index] = value;
        index++;
    }
    
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