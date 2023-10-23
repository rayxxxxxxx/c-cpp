#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
class Queue
{
private:
    size_t capacity;
    size_t tail;
    size_t head;
    T *data;

public:
    Queue()
    {
        this->capacity = 3;
        this->tail = 0;
        this->head = 0;
        this->data = new T[this->capacity];
    }

    ~Queue()
    {
        delete[] this->data;
    }

    size_t getCapacity() const
    {
        return this->capacity;
    }

    size_t getSize() const
    {
        return this->tail - this->head;
    }

    bool isEmpty() const
    {
        return this->tail - this->head == 0 ? true : false;
    }

    void clear()
    {
        this->capacity = 3;
        this->tail = 0;
        this->head = 0;
        delete[] this->data;
        this->data = new T[this->capacity];
    }

    void push(T item)
    {
        if (this->tail == this->capacity)
        {
            this->capacity *= 2;

            T *newArr = new T[this->capacity];
            std::copy(this->data, this->data + this->tail, newArr);
            newArr[this->tail] = item;

            delete[] this->data;
            this->data = newArr;
            this->tail++;
        }
        else
        {
            this->data[this->tail] = item;
            this->tail++;
        }
    }

    T pop()
    {
        if (this->tail - this->head == 0)
        {
            throw std::invalid_argument("queue is empty");
        }

        T tmpData = this->data[head];
        this->head++;

        if ((this->tail - this->head) <= (this->capacity / 4))
        {
            this->capacity /= 2;

            T *newArr = new T[this->capacity];
            std::copy(this->data + this->head, this->data + this->tail, newArr);
            delete[] this->data;
            this->data = newArr;
            this->tail = this->tail - this->head;
            this->head = 0;
        }

        return tmpData;
    }
};

#endif