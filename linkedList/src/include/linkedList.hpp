#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>

#include "node.hpp"

template <typename T>
class LinkedList
{
private:
    size_t size;
    Node<T> *head;
    Node<T> *tail;

    Node<T> *getNode(int index)
    {
        Node<T> *currNode = this->head;
        for (size_t i = 0; i < index; i++)
        {
            currNode = currNode->getNext();
        }
        return currNode;
    }

    Node<T> *popNode()
    {
        if (this->head == this->tail)
        {
            this->size = 0;
            return this->head;
        }
        else
        {
            Node<T> *last = this->tail;
            Node<T> *preTail = this->getNode(this->size - 2);
            preTail->setNext(nullptr);
            this->tail = preTail;
            this->size--;
            return last;
        }
    }

public:
    LinkedList()
    {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~LinkedList()
    {
        while (this->size != 0)
        {
            delete this->popNode();
        }
    }

    Node<T> *getHead()
    {
        return this->head;
    }

    Node<T> *getTail()
    {
        return this->tail;
    }

    size_t getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->head == nullptr ? true : false;
    }

    T &get(int index)
    {
        if (index >= this->size || index < 0)
        {
            throw std::invalid_argument("invalid index");
        }
        return this->getNode(index)->getData();
    }

    void push(const T &data)
    {
        if (this->head == nullptr)
        {
            this->head = new Node<T>(data);
            this->tail = this->head;
            this->size++;
        }
        else
        {
            this->tail->setNext(new Node<T>(data));
            this->tail = this->tail->getNext();
            this->size++;
        }
    }

    void insert(int index, const T &data)
    {
        if (index > this->size || index < 0)
        {
            throw std::invalid_argument("invalid index");
        }
        if (index == 0)
        {
            Node<T> *newNode = new Node<T>(data);
            newNode->setNext(this->head);
            this->head = newNode;
            this->size++;
        }
        else if (index == this->size)
        {
            this->tail->setNext(new Node<T>(data));
            this->tail = this->tail->getNext();
            this->size++;
        }
        else
        {
            Node<T> *prev = this->getNode(index - 1);
            Node<T> *newNode = new Node<T>(data);
            newNode->setNext(prev->getNext());
            prev->setNext(newNode);
            this->size++;
        }
    }

    T pop()
    {
        return this->popNode()->getData();
    }

    T remove(int index)
    {
        if (index >= this->size || index < 0)
        {
            throw std::invalid_argument("invalid index");
        }
        if (index == 0)
        {
            T data = this->head->getData();
            Node<T> *newHead = this->head->getNext();
            delete this->head;
            this->head = newHead;
            this->size--;
        }
        else if (index == this->size - 1)
        {
            Node<T> *newTail = this->getNode(this->size - 2);
            newTail->setNext(nullptr);
            delete this->tail;
            this->tail = newTail;
            this->size--;
        }
        else
        {
            Node<T> *preCurrNode = this->getNode(index - 1);
            Node<T> *currNextNode = preCurrNode->getNext()->getNext();
            delete preCurrNode->getNext();
            preCurrNode->setNext(currNextNode);
            this->size--;
        }
    }

    void clear()
    {
        while (this->size != 0)
        {
            delete this->popNode();
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
};

#endif