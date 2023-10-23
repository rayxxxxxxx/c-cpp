#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node
{
private:
    T data;
    Node<T> *left;
    Node<T> *right;

public:
    Node()
    {
        this->data = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(const Node &node)
    {
        this->data = node.data;
        this->left = node.left;
        this->right = node.right;
    }

    ~Node()
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data.~T();
    }

    T &getData()
    {
        return this->data;
    }

    void setData(const T &data)
    {
        this->data = data;
    }

    Node<T> *getLeft() const
    {
        return this->left;
    }

    Node<T> *getRight() const
    {
        return this->right;
    }

    void setLeft(Node<T> *node)
    {
        this->left = node;
    }

    void setRight(Node<T> *node)
    {
        this->right = node;
    }

    Node &operator=(const Node &node)
    {
        this->data = node.data;
        this->left = node.left;
        this->right = node.right;
        return *this;
    }

    bool operator==(const Node &node) const
    {
        return this->data == node.data;
    }

    bool operator!=(const Node &node) const
    {
        return this->data != node.data;
    }

    bool operator<(const Node &node) const
    {
        return this->data < node.data;
    }

    bool operator>(const Node &node) const
    {
        return this->data > node.data;
    }

    bool operator<=(const Node &node) const
    {
        return this->data <= node.data;
    }

    bool operator>=(const Node &node) const
    {
        return this->data >= node.data;
    }
};

#endif