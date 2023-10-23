#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
class Stack
{
private:
    size_t capacity;
    size_t size;
    T *data;

public:
    Stack()
    {
        this->capacity = 3;
        this->size = 0;
        this->data = new T[this->capacity];
    }

    ~Stack()
    {
        delete[] this->data;
    }

    size_t getSize()
    {
        return this->size;
    }

    size_t getCapacity()
    {
        return this->capacity;
    }

    bool isEmpty()
    {
        if (this->size == 0)
        {
            return true;
        }
        return false;
    }

    void clear()
    {
        this->capacity = 3;
        this->size = 0;
        delete[] this->data;
        this->data = new T[this->capacity];
    }

    void push(T item)
    {
        if (this->size == this->capacity)
        {
            this->capacity *= 2;

            T *newArr = new T[this->capacity];
            std::copy(this->data, this->data + this->size, newArr);
            newArr[this->size] = item;

            delete[] this->data;
            this->data = newArr;
            this->size++;
        }
        else
        {
            this->data[this->size] = item;
            this->size++;
        }
    }

    T pop()
    {
        if (this->size == 0)
        {
            throw std::invalid_argument("stack is empty");
        }

        T tmpData = this->data[this->size - 1];
        this->size--;

        if (this->size <= this->capacity / 4)
        {
            this->capacity /= 2;

            T *newArr = new T[this->capacity];
            std::copy(this->data, this->data + this->size, newArr);
            delete[] this->data;
            this->data = newArr;
        }

        return tmpData;
    }
};

#endif
