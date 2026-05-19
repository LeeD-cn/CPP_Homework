#include <iostream>
#include <cstdlib>
using namespace std;
template<typename T>
class Queue {
 public:
    Queue(int size = 0);
    Queue(const Queue<T>& q);
    virtual ~Queue();
    void In(const T& e);
    const T Out();
    bool Empty();
 private:
    T *buff;
    static const int Front = 0;
    int Tail;
    int max;
    void Error(int);
};

#define OVERFLOW 0
#define UNDERFLOW 1
template<typename T>
void Queue<T>::Error(int msg)
{
    switch(msg){
    case 0:
        cout << "error overflow!" << endl;
        break;
    case 1:
        cout << "error underflow!" << endl;
        break;
    }
}

template<typename T>
Queue<T>::Queue(int size)
{
    Tail = -1;
    buff = new T[max = size];
}

template<typename T>
Queue<T>::Queue(const Queue<T>& q)
{
    max = q.max;
    Tail = q.Tail;
    buff = new T[max];
    for(int i = Front; i <= Tail; i++)
    {
        buff[i] = q.buff[i];
    }
}

template<typename T>
Queue<T>::~Queue()
{
    delete []buff;
    cout << "destroy Queue" << endl;
}

template<typename T>
void Queue<T>::In(const T& e)
{
    if(Tail >= max - 1) 
    {
        Error(OVERFLOW); 
        return;
    }
    buff[++Tail] = e;
}

template<typename T>
const T Queue<T>::Out()
{
    if(Empty()) 
    {
        Error(UNDERFLOW); 
        return 0;
    }
    T t = buff[Front];
    for(int i = Front; i < Tail; i++)
    {
        buff[i] = buff[i+1];
    }
    Tail--;
    return t;
}

template<typename T>
bool Queue<T>::Empty()
{
    return (Tail < Front);
}

int main()
{
    Queue<int> q1(10);
    Queue<double> q2(5);
    cout << "q1" << endl;
    for(int i = 1; i <= 10; i++)
    {
        q1.In(i);
    }
    while(!q1.Empty())
    {
        cout << q1.Out() << endl;
    }
    cout << "q2 IN" << endl;
    for(int i = 0; i < 6; i++)
    {
        q2.In(i + 0.1);
    }
    cout << "q3 OUT" << endl;
    Queue<double> q3(q2);
    for(int i = 0; i < 6; i++)
    {
        cout << q3.Out() << endl;
    }
    return 0;
}