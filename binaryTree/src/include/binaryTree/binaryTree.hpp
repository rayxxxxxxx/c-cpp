#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <stdexcept>
#include <stack>

#include "binaryTree/node.hpp"

template <class T>
class Tree
{
private:
    Node<T> *root = nullptr;
    size_t size;

public:
    Tree(const T &data)
    {
        this->root = new Node<T>(data);
        this->size++;
    }

    ~Tree() {}

    Node<T> *getRoot() const
    {
        return this->root;
    }

    bool has(const T &data) const
    {
        Node<T> *currNode = this->root;
        while (currNode != nullptr)
        {
            if (currNode->getData() == data)
            {
                return true;
            }

            if (data < currNode->getData())
            {
                if (currNode->getLeft() == nullptr)
                {
                    return false;
                }
                currNode = currNode->getLeft();
                continue;
            }

            if (data > currNode->getData())
            {
                if (currNode->getRight() == nullptr)
                {
                    return false;
                }
                currNode = currNode->getRight();
                continue;
            }
        }
    }

    Node<T> *getAll() const {}

    void add(T data)
    {
        Node<T> *currNode = this->root;
        while (currNode != nullptr)
        {
            if (currNode->getData() == data)
            {
                return;
            }

            if (data < currNode->getData())
            {
                if (currNode->getLeft() == nullptr)
                {
                    currNode->setLeft(new Node<T>(data));
                    return;
                }
                currNode = currNode->getLeft();
                continue;
            }

            if (data > currNode->getData())
            {
                if (currNode->getRight() == nullptr)
                {
                    currNode->setRight(new Node<T>(data));
                    return;
                }
                currNode = currNode->getRight();
                continue;
            }
        }
    }

    void remove(const T &data) {}

    static bool has(Node<T> *root, const T &data)
    {
        if (root->getData() == data)
        {
            return true;
        }
        if (root->getLeft() != nullptr && data < root->getData())
        {
            return Tree<T>::has(root->getLeft(), data);
        }
        if (root->getRight() != nullptr && data > root->getData())
        {
            return Tree<T>::has(root->getRight(), data);
        }
        return false;
    }

    static Node<T> *getAll(Node<T> *root) {}

    static void add(Node<T> *root, const T &data)
    {
        if (root->getData() == data)
        {
            return;
        }
        if (data < root->getData())
        {
            if (root->getLeft() == nullptr)
            {
                root->setLeft(new Node<T>(data));
                return;
            }
            Tree<T>::add(root->getLeft(), data);
        }
        if (data > root->getData())
        {
            if (root->getRight() == nullptr)
            {
                root->setRight(new Node<T>(data));
                return;
            }
            Tree<T>::add(root->getRight(), data);
        }
    }

    static void remove(Node<T> *root, const T &data) {}
};

#endif