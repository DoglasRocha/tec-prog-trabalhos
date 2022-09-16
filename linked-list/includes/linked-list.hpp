#pragma once
#include "node.hpp"

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList<T> *insert(T data, int index);
        LinkedList<T> *append(T data);
        T remove(int index);
        T operator[](int index);
        int getLength();

    private:
        Node<T> *head, *tail, *auxPointer;
        int length, auxPointerIndex;

        void insertInEmptyList(Node<T> *node);
        void insertAtListHead(Node<T> *node);
        void insertAtListTail(Node<T> *node);
        void insertAtIndex(Node<T> *node, int index);
        Node<T> *getNodeAt(int index);
        Node<T> *removeListHead();
        Node<T> *removeListTail();
        Node<T> *removeAtIndex(int index);
};