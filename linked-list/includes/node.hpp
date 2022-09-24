#pragma once

template <class T> 
class Node
{
    public:
        Node *next, *prev;
        T data;

        Node(T data_=0);
        ~Node();
};

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