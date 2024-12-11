#ifndef OWENS_ITERATOR_H
#define OWENS_ITERATOR_H

#include <iostream>
using namespace std;

template <typename T> class owens_iterator {
private:
    T* m_pointer;
    T* m_begin;
    T* m_end;

public:
    owens_iterator(T* begin, T* end);
    void begin();
    void end();
    T operator*();
    void operator++();
    void operator--();
    bool operator!=(owens_iterator<T>);
    T* getPointer();
};
template <typename T> owens_iterator<T>::owens_iterator(T* begin, T* end)
{
    m_begin = begin;
    m_end = end;
}
template <typename T> void owens_iterator<T>::begin() {
    //set value of iterator pointer to begining
    m_pointer = m_begin;
}
template <typename T> void owens_iterator<T>::end() {
    //set value of iterator pointer to ending
    m_pointer = m_end;
}
template <typename T> T owens_iterator<T>::operator*() {
    //return value pointed to by iterator
    return *m_pointer;
}
template <typename T> void owens_iterator<T>::operator++() {
    //increment owens_iterator
    if (m_pointer < m_end) {
        m_pointer++;
    }
}
template <typename T> void owens_iterator<T>::operator--() {
    //decrement owens_iterator
    if (m_pointer > m_begin) {
        m_pointer--;
    }
}
template <typename T> bool owens_iterator<T>::operator!=(owens_iterator<T> other) {
    //compare two iterator objects
    if (m_pointer != other.getPointer()) {
        return true;
    }
    return false;
}
template <typename T> T* owens_iterator<T>::getPointer() {
    return m_pointer;
}
#endif // OWENS_ITERATOR_H