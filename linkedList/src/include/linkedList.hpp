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

public:
    LinkedList()
    {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~LinkedList()
    {
    }

    Node<T> *getHead()
    {
        Node<T> *pHeadCopy = this->head;
        return pHeadCopy;
    }

    Node<T> *getTail()
    {
        Node<T> *tailCopy = this->tail;
        return tailCopy;
    }

    bool empty()
    {
        return this->head == nullptr ? true : false;
    }

    Node<T> &get(int index)
    {
        Node<T> *c = this->head;
        for (size_t i = 0; i < index; i++)
        {
            if (c == nullptr)
            {
                throw std::invalid_argument("invalid index");
            }
            c = c->next();
        }
        return *c;
    }

    void push(T item)
    {
        if (this->head == nullptr)
        {
            this->head = new Node<T>(item);
            this->tail = this->head;
            this->size++;
            return;
        }

        this->tail->setNext(new Node<T>(item));
        this->tail = this->tail->next();
        this->size++;
    }

    void insert(T item, int index)
    {
        if (index == 0)
        {
            Node<T> *newnode = new Node<T>(item);

            newnode->setNext(this->head);
            this->head = newnode;

            this->size++;
        }
        else if (index == this->size)
        {
            Node<T> *newnode = new Node<T>(item);
            this->tail->setNext(newnode);
            this->tail = newnode;
            this->size++;
        }
        else
        {
            Node<T> *prev = &(this->get(index - 1));
            if (prev == nullptr)
            {
                throw std::invalid_argument("LinkedList error: node is nullptr");
            }

            Node<T> *newnode = new Node<T>(item);

            newnode->setNext(prev->next());
            prev->setNext(newnode);

            this->size++;
        }
    }

    T pop()
    {
        T tmp = this->tail->data();
        Node<T> *preTail = &(this->get(this->size - 2));
        preTail->setNext(nullptr);
        delete this->tail;
        this->tail = preTail;
        return tmp;
    }

    T remove(int index) {}

    void clear()
    {
        Node<T> **pNodes = new Node<T> *[this->size];
        Node<T> *c = this->head;

        std::size_t i = 0;
        while (c != nullptr)
        {
            pNodes[i] = c;
            c = c->next();
            i++;
        }
        delete[] pNodes;

        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
};

#endif