#pragma once
#include <iostream>
#include <string>

template <typename T>
class Queue
{
private:
    T* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int cap = 100);
    ~Queue();

    bool isEmpty() const;
    T first() const;
    void push(const T& value);
    void pop();
    void show() const;
};

template <typename T>
Queue<T>::Queue(int cap)
{
    capacity = cap;
    arr = new T[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] arr;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
T Queue<T>::first() const
{
    if (isEmpty())
        throw std::out_of_range("Queue is empty");

    return arr[front];
}

template <typename T>
void Queue<T>::push(const T& value)
{
    if (size == capacity)
    {
        std::cout << "Queue is full!\n";
        return;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
}

template <typename T>
void Queue<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty!\n";
        return;
    }

    front = (front + 1) % capacity;
    size--;
}

template <typename T>
void Queue<T>::show() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty!\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[(front + i) % capacity] << " ";
    }
    std::cout << std::endl;
}