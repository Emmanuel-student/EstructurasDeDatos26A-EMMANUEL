#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <exception>
#include <string>

template<class T, int ARRAYSIZE = 1024>
class Stack {
private:
    T data[ARRAYSIZE];
    int top = -1;

    void copyAll(const Stack<T, ARRAYSIZE>&);

public:
class Exception : public std::exception{
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

    Stack();

    Stack(const Stack&);

    bool isEmpty() const;

    bool isFull() const;
    
    void push(const T&);
    
    T pop();
    
    T& getTop();
    
    
    
    Stack<T, ARRAYSIZE>& operator = (const Stack<T, ARRAYSIZE>&);
};

//iMPLEMENTACION

template<class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& s){
    if(this == &s){
        return;
    }
    
    int i(0);

    while (i<= s.top){
        this->data[i] = s.data[i];

        i++;
    }
    
    this->top = s.top;
    
}

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() { }

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack& s) {
    this->copyAll(s);
}

template<class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() const{
    return this->top == -1;
}

template<class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() const{
    return this->top == ARRAYSIZE -1;
}

template<class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& e){
    if(this->isFull()){
        throw Exception("Desbordamiento de Datos, push");
    }

    this->data[++this->top] = e;
}

template<class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop(){
    if(this->isEmpty()){
        throw Exception ("Induficiencia de datos, pop");
    }

    return this->data[this->top--];    
}

template<class T, int ARRAYSIZE>
T& Stack<T, ARRAYSIZE>::getTop(){
    if(this->isEmpty()){
        throw Exception("Insuficiencia de datos, getTop");
    }

    return this->data[this->top];
}

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator = (const Stack<T, ARRAYSIZE>& s){
    this->copyAll(s);

    return *this;
}



#endif // __STACK_HPP__