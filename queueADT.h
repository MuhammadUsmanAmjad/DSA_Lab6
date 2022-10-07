#include <iostream>
using namespace std;
template <class T>
class Queue_ADT
{
    virtual bool Is_Empty() = 0;
    virtual bool Is_Full() = 0;
    virtual void Initialize() = 0;
    virtual T Front() = 0;
    virtual T back() = 0;
    virtual void Enqueue(T const &val) = 0;
    virtual void Dequeue() = 0;
};