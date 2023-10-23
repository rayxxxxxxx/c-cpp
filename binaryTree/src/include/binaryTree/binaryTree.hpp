#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <stdexcept>
#include <stack>
#include <unordered_set>

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
        this->size = 1;
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

    T *getAll() const
    {
        std::unordered_set<Node<T> *> visited = std::unordered_set<Node<T> *>();
        std::stack<Node<T> *> nodeStack = std::stack<Node<T> *>();
        T *data = new T[this->size];
        size_t i = 0;

        Node<T> *currNode = this->root;
        while (visited.count(this->root) != 1)
        {
            if (visited.count(currNode) == 1)
            {
                data[i] = currNode->getData();
                i++;
                currNode = nodeStack.top();
                nodeStack.pop();
                continue;
            }

            if (currNode->getLeft() != nullptr && visited.count(currNode->getLeft()) == 0)
            {
                nodeStack.push(currNode);
                currNode = currNode->getLeft();
                continue;
            }

            if (currNode->getRight() != nullptr && visited.count(currNode->getRight()) == 0)
            {
                nodeStack.push(currNode);
                currNode = currNode->getRight();
                continue;
            }

            visited.insert(currNode);
            continue;
        }
        data[i] = this->root->getData();
        return data;
    }

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
                    this->size++;
                    break;
                }
                currNode = currNode->getLeft();
                continue;
            }

            if (data > currNode->getData())
            {
                if (currNode->getRight() == nullptr)
                {
                    currNode->setRight(new Node<T>(data));
                    this->size++;
                    break;
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