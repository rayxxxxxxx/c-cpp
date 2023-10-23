#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node()
    {
        this->data = nullptr;
        this->next = nullptr;
    }

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(const Node &node)
    {
        this->data = node.data;
        this->next = node.next;
    }

    ~Node()
    {
        this->next = nullptr;
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

    Node<T> *getNext() const
    {
        return this->next;
    }

    void setNext(Node<T> *node)
    {
        this->next = node;
    }

    Node &operator=(const Node &node)
    {
        this->data = node.data;
        this->next = node.next;
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