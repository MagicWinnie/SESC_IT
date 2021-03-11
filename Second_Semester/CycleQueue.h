// Circular queue is a ...
#pragma once
template <class T>
class CycleQueueClass
{
    private:
        T *items;
        size_t size, front = -1, rear = -1;

    public:
        CycleQueueClass(size_t size_)
        {
            items = new T[size_];
            size = size_;
        }
        bool isFull()
        {
            if (front == 0 && rear == size - 1)
                return true;
            if (front == rear + 1)
                return true;
            return false;
        }
        bool isEmpty()
        {
            if (front == -1)
                return true;
            return false;
        }
        void push(T x)
        {
            if (isFull())
                throw "Queue is full";
            else
            {
                if (front == -1) front = 0;
                rear = (rear + 1) % size;
                items[rear] = x;
            }
        }
        T pop()
        {
            if (isEmpty())
            {
                throw "Queue is empty";
            } else
            {
                T x = items[front];
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                } else 
                {
                    front = (front + 1) % size;
                }
                return x;
            }
        }
        ~CycleQueueClass()
        {
            delete[] items;
        }
};