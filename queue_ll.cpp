#include <iostream>
#include "queueADT.h"
using namespace std;
template <typename T>
struct node
{
    node<T> *next;
    T data;
    node<T>(T data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class Queue : public Queue_ADT<T>
{

public:
    node<T> *front;
    node<T> *rear;
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    bool Is_Empty()
    {
        return front == NULL;
    }
    bool Is_Full()
    {
        return false; // always false because linked list is un-limited....
    }
    int get_lengh()
    {
        node<T> *temp = front;
        int i = 0;
        while (temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        return i;
    }
    void Initialize() // DElete the previous Queue......
    {
        if (this->front == NULL)
            return;
        front = front;
        while (this->front != this->rear)
        {
            node<T> *to_del = this->front;
            this->front = this->front->next;
            delete to_del;
        }
        this->front = NULL;
        this->rear = NULL;
    }
    T Front()
    {
        if (this->front == NULL)
            throw("Queue is Empty\n");
        return (this->front->data);
    }
    T back()
    {
        if (this->rear == NULL)
            throw("Queue is Empty");
        return this->rear->data;
    }
    void Enqueue(T const &val)
    {
        node<T> *new_node = new node<T>(val);
        if (this->front == NULL)
        {
            this->front = new_node;
            this->rear = new_node;
            return;
        }
        this->rear->next = new_node;
        rear = new_node;
    }
    void Dequeue()
    {
        if (this->front == NULL)
            return;
        node<T> *to_del = this->front;
        this->front = this->front->next;
        delete to_del;
    }
    void Display()
    {
        if (front == NULL)
        {
            cout << "Queue Is Empty\n";
            return;
        }
        node<T> *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue<T>()
    {
        if (!this->Is_Empty())
            Initialize();
        cout << "~Queue<T> called\n";
    }
};
template <typename T>
void get_desired_queue(Queue<T> *q_par, Queue<T> *q_des)
{
    int length = q_par->get_lengh();
    Queue<T> *q_temp = new Queue<T>;
    for (int i = 0; i < length / 2; i++)
    {
        T data = q_par->Front();
        q_par->Dequeue();
        q_temp->Enqueue(data);
    }
    while (!q_par->Is_Empty() && !q_temp->Is_Empty())
    {
        T data = q_temp->Front();
        q_des->Enqueue(data);
        q_temp->Dequeue();
        data = q_par->Front();
        q_des->Enqueue(data);
        q_par->Dequeue();
    }
}
template <typename T>
bool check_triples(Queue<T> *q_par, int k)
{
    if (q_par->Is_Empty())
        return false;
    if (q_par->get_lengh() < k)
        return false;
    Queue<T> *temp = new Queue<T>;
    temp->Enqueue(q_par->Front());

    q_par->Dequeue();
    int i = 0;
    while (q_par->get_lengh() > 1)
    {
        if (i == k)
        {
            T data = temp->back();
            T data1 = q_par->Front();
            if (data + 1 == data1)
            {
                return false;
            }
        }
        if (i == k)
            i = 0;
        i++;
        temp->Enqueue(q_par->Front());
        q_par->Dequeue();
    }
    return true;
}
int main()
{
    Queue<char> *q = new Queue<char>;
    q->Enqueue('a');
    q->Enqueue('b');
    q->Enqueue('c');
    q->Enqueue('d');
    q->Enqueue('e');
    q->Enqueue('f');
    q->Enqueue('g');
    q->Enqueue('h');
    q->Display();
    Queue<char> *q1 = new Queue<char>;
    get_desired_queue(q, q1);
    q1->Display();
    Queue<int> *q2 = new Queue<int>;
    q2->Enqueue(1);
    q2->Enqueue(2);
    q2->Enqueue(3);
    // q2->Enqueue(4);
    q2->Enqueue(5);
    q2->Enqueue(7);
    q2->Enqueue(11);
    q2->Enqueue(12);
    q2->Enqueue(13);
    q2->Display();
    if (check_triples(q2, 2))
        cout << "True\n";
    else
        cout << "false\n";
    delete q2;
    delete q1;
    delete q;
}
