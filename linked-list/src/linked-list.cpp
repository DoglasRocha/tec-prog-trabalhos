#include "../includes/linked-list.hpp"
#include "../includes/node.hpp"
#include "node.cpp"
#include <iostream>

template <class T> 
LinkedList<T>::LinkedList()
{
    head = tail = auxPointer = 0;
    length = auxPointerIndex = 0;
}

template <class T> 
LinkedList<T>::~LinkedList()
{
    Node<T> *tmp, *aux;
    for (tmp = head; tmp != 0; tmp = aux)
    {
        aux = tmp->next;
        delete tmp;
    }
}

template <class T> 
LinkedList<T> *LinkedList<T>::insert(T data, int index)
{
    Node<T> *node = new Node<T>(data);

    switch (index)
    {
    case 0:
        insertAtListHead(node);
        break;
    
    case -1:
        insertAtListTail(node);
        break;

    default:
        insertAtIndex(node, index);
        break;
    }

    length++;

    if (index <= auxPointerIndex)
        auxPointerIndex++;

    return this;
}

template <class T>
LinkedList<T> *LinkedList<T>::append(T data)
{
    insert(data, -1);

    return this;
}

template <class T> 
T LinkedList<T>::remove(int index)
{
    Node<T> *removedNode;
    T data;

    switch(index) 
    {
    case 0:
        removedNode = removeListHead();   
        break;

    case -1:
        removedNode = removeListTail();
        break;

    default:
        removedNode = removeAtIndex(index);
        break;
    }

    data = removedNode->data;
    removedNode->data = 0;
    length--;
    
    delete removedNode;
    return data;
}

template <class T>
T LinkedList<T>::operator[](int index)
{
    return getNodeAt(index)->data;
}

template <class T>
int LinkedList<T>::getLength()
{
    return length;
}

template <class T> 
void LinkedList<T>::insertInEmptyList(Node<T> *node)
{
    head = tail = auxPointer = node;
}

template <class T> 
void LinkedList<T>::insertAtListHead(Node<T> *node)
{
    if (length == 0)
        insertInEmptyList(node);

    else
    {
        node->next = head;
        head->prev = node;
        head = node; 
    }
}

template <class T> 
void LinkedList<T>::insertAtListTail(Node<T> *node)
{
    if (length == 0)
        insertInEmptyList(node);

    else        
    {
        tail->next = node;
        node->prev = tail;
        tail = node;   
    }
}

template <class T> 
void LinkedList<T>::insertAtIndex(Node<T> *node, int index)
{
    Node<T> *aux;

    if (length == 0)
        insertInEmptyList(node);

    else if (length <= index)
        insertAtListTail(node);

    else
    {
        aux = getNodeAt(index);

        node->prev = aux->prev;
        aux->prev->next = node; 
        node->next = aux;
        aux->prev = node;
    }
}

template <class T> 
Node<T> *LinkedList<T>::getNodeAt(int index)
{
    int indexDelta = index - auxPointerIndex,
        diffToHead = index,
        diffToTail = length - 1 - index;

    if (-diffToHead > indexDelta)
        auxPointer = head,
        auxPointerIndex = 0,
        indexDelta = index - auxPointerIndex;
        

    if (diffToTail < indexDelta)
        auxPointer = tail,
        auxPointerIndex = length - 1,
        indexDelta = index - auxPointerIndex;

    if (indexDelta > 0)
    {
        while (index != auxPointerIndex)
        {
            auxPointerIndex++,
            auxPointer = auxPointer->next;

            if (auxPointer == 0)
                auxPointerIndex = 0,
                auxPointer = head;
        }
    }
    else
    {
        while (index != auxPointerIndex)
        {
            auxPointerIndex--,
            auxPointer = auxPointer->prev;
        
            if (auxPointer == 0)
                auxPointerIndex = length -1,
                auxPointer = tail;
        }
    }

    return auxPointer;
}

template <class T> 
Node<T> *LinkedList<T>::removeListHead()
{
    if (head == 0)
        return 0;

    Node<T> *nodeToRemove = head;
    head = nodeToRemove->next;

    if (head) head->prev = 0;

    if (nodeToRemove == auxPointer)
        auxPointer = head,
        auxPointerIndex = 0;

    else
        auxPointerIndex--;

    return nodeToRemove;
}

template <class T> 
Node<T> *LinkedList<T>::removeListTail()
{
    if (tail == 0)
        return 0;
    
    Node<T> *nodeToRemove = tail;

    tail = nodeToRemove->prev;
    if (tail) 
        tail->next = 0;
    
    auxPointer = tail;
    auxPointerIndex--;
    
    return nodeToRemove;
}

template <class T> 
Node<T> *LinkedList<T>::removeAtIndex(int index)
{
    Node<T> *nodeToRemove;

    if (length <= 1)
        return removeListHead();
    
    else if (length - 1 <= index)
        return removeListTail();
    
    nodeToRemove = getNodeAt(index);

    nodeToRemove->prev->next = nodeToRemove->next;
    nodeToRemove->next->prev = nodeToRemove->prev;

    auxPointer = nodeToRemove->next;

    return nodeToRemove;
}
