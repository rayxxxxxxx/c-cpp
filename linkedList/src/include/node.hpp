#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class Node
{
private:
    std::size_t mSize;
    T mData;
    Node *pNext;

public:
    Node(T item)
    {
        this->mSize = sizeof(item);
        this->mData = item;
        this->pNext = nullptr;
    }

    Node &operator=(const Node<T> &node)
    {
        this->mSize = node.mSize;
        this->mData = node.mData;
        this->pNext = node.pNext;

        return *this;
    }

    Node *copy()
    {
        T mData = this->mData;
        return new Node<T>(mData);
    }

    std::size_t size()
    {
        return this->mSize;
    }

    T &data()
    {
        return this->mData;
    }

    void setData(T item)
    {
        this->mSize = sizeof(item);
        this->mData = item;
    }

    Node *next()
    {
        return this->pNext;
    }

    void setNext(Node *pNext)
    {
        this->pNext = pNext;
    }

    bool
    operator==(const Node<T> &node)
    {
        return this->mData == node.mData;
    }

    bool operator!=(const Node<T> &node)
    {
        return this->mData != node.mData;
    }

    bool operator>(const Node<T> &node)
    {
        return this->mData > node.mData;
    }

    bool operator<(const Node<T> &node)
    {
        return this->mData < node.mData;
    }

    bool operator<=(const Node<T> &node)
    {
        return this->mData <= node.mData;
    }

    bool operator>=(const Node<T> &node)
    {
        return this->mData >= node.mData;
    }
};

#endif