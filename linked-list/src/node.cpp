#include "../includes/node.hpp"

template <class T> 
Node<T>::Node(T data_)
{
    data = data_;
    next = prev = 0;
}

template <class T>
Node<T>::~Node()
{
    
}