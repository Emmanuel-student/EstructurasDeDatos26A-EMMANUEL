#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <exception>
#include <string>

template <class T, int ARRAYSIZE = 1024>
class Queue{
private:
    T data[ARRAYSIZE];
    int frontPos= 0;
    int endPos = ARRAYSIZE - 1;

    void copyAll(const Queue<T, ARRAYSIZE>&);

public:
    class Exception : public std::exception {
private:
    std::string msg;

public:
    Exception() noexcept : msg("Error Indefinido") {}
    Exception(const Exception& ex) noexcept : msg(ex.msg) {}
    Exception(const std::string& m) : msg(m) {}
    Exception& operator =(const Exception& ex) noexcept {
        msg = ex.msg;

        return *this;
    }
    virtual ~Exception() { }
    virtual const char* what() const noexcept {
        return msg.c_str();
    }
};
    
    Queue();

    Queue(const Queue<T, ARRAYSIZE>&);

    bool isEmpty() const;

    bool isFull() const;

    void enqueue(const T&);

    T dequeue();

    T& getFront();

    Queue<T, ARRAYSIZE>& operator =(const Queue<T, ARRAYSIZE>&);


};
//Implementacion
template<class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE>&){
    
}

template<class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue() { }

template<class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue<T, ARRAYSIZE>& q){
    this->copyAll(q);
}

template<class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty() const{
    return this->frontPos == this->endPos + 1
            or (this->frontPos == 0 and this->endPos == ARRAYSIZE -1); //los () son por condicion compuesta
}

template<class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull() const{
    return this->frontPos == this->endPos + 2
            or (this->frontPos == 0 and this->endPos == ARRAYSIZE -2)
            or (this->frontPos == 1 and this->endPos == ARRAYSIZE -1);
}

template<class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T& e){
    if(this->isFull()){
        throw Exception("Desbordamiento de datos, enqueue");
    }

    this->data[this->endPos = (++this->endPos == ARRAYSIZE ? 0 : this->endPos)] = e;
}

template<class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue(){
    if(this->isEmpty()){
        throw Exception("Insuficiencia de datos, dequeue");
    }

    T result(this->data[this->frontPos]);

    this->frontPos = (++this->frontPos == ARRAYSIZE ? 0 : this->frontPos);

    return result;
}

template<class T, int ARRAYSIZE>
T& Queue<T, ARRAYSIZE>::getFront(){
    if (this->isEmpty()){
        throw Exception("Insuficiencia de Datos, getFront");
    }

    return this->data[this->frontPos];
}

template<class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator =(const Queue<T, ARRAYSIZE>& q){
    this->copyAll(q);

    return *this;
}



#endif // __QUEUE_HPP__