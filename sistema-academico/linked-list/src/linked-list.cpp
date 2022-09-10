#include "../includes/linked-list.hpp"
#include "../includes/node.hpp"
#include "node.cpp"
#include <iostream>

template <class T> 
LinkedList<T>::LinkedList()
{
    head = tail = auxPointer = nullptr;
    length = auxPointerIndex = 0;
}

template <class T> 
LinkedList<T>::~LinkedList()
{
    Node<T> *tmp, *aux;
    for (tmp = head; tmp != nullptr; tmp = aux)
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
    removedNode->data = nullptr;
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
    int indexDelta, diffToBorder;
    indexDelta = index - auxPointerIndex;
    if (indexDelta == 0) return auxPointer;

    if (indexDelta > 0)
    {
        diffToBorder = length - index;
        // if the index diff is less or equal than the differente from the index to the border, then
        // reach the index starting from the current index
        if (indexDelta <= diffToBorder)
        {
            while (auxPointerIndex != index)
                auxPointer = auxPointer->next,
                auxPointerIndex++;

            return auxPointer;
        }

        // otherwise, move auxPointer to the end of the list
        for (
            auxPointerIndex = length -1, auxPointer = tail;
            auxPointerIndex != index;
            auxPointer = auxPointer->prev, auxPointerIndex--
        );

        return auxPointer;
    }  
    
    // if the desired index is closer to the border than the path between the current node and the desired node,
    // then reach the desired index from the list head
    if (-index > indexDelta)
    {
        for (
            auxPointerIndex = 0, auxPointer = head;
            auxPointerIndex != index;
            auxPointer = auxPointer->next, auxPointerIndex++
        );

        return auxPointer;
    }

    // otherwise, reach the desired index from the current position
    while (auxPointerIndex != index)
        auxPointer = auxPointer->prev,
        auxPointerIndex--;
        
    return auxPointer;
}

template <class T> 
Node<T> *LinkedList<T>::removeListHead()
{
    if (head == nullptr)
        return nullptr;

    Node<T> *nodeToRemove = head;
    head = nodeToRemove->next;

    if (head) head->prev = nullptr;
    
    return nodeToRemove;
}

template <class T> 
Node<T> *LinkedList<T>::removeListTail()
{
    if (tail == nullptr)   
        return nullptr;
    
    Node<T> *nodeToRemove = tail;

    tail = nodeToRemove->prev;
    if (tail) 
        tail->next = nullptr;
    else 
        head = nullptr;
    
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

    return nodeToRemove;
}