#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <exception>
#include <string>

//Definicion

using namespace std;


template <class T, int ARRAYSIZE = 1024>  //De esta manera se puede dejar un tamaño por defecto
class List {
private:
    T data[ARRAYSIZE];
    int last = -1;

    bool isValid(const int&) const;

    void copyAll(const List<T, ARRAYSIZE>&);

public:
class Exception : public exception{
private:
    string msg;

public:
    Exception() noexcept : msg("Error Indefinido") {}
    Exception(const Exception& ex) noexcept : msg(ex.msg) {}
    Exception(const string& m) : msg(m) {}
    Exception& operator =(const Exception& ex) noexcept {
        msg = ex.msg;

        return *this;
    }
    virtual ~Exception() { }
    virtual const char* what() const noexcept {
        return msg.c_str();
    }
};
    List();
    List(const List<T, ARRAYSIZE>&);

    bool isEmpty() const;

    bool isFull() const;

    void instData(const int&, const T& ); //pos, dato

    void delData(const int&); //pos

    int getFirstPos() const;

    int getLastPos() const;

    int getPrevpos(const int&) const; //pos

    int getNextPos(const int&) const; // pos

    int findData(const T&) const; //dato

    int findDataL(const T&) const;
    int findDataB(const T&) const;

    void sortData();

    T& retreive(const int&);

    std::string toString() const;

    void delAll();


    List<T, ARRAYSIZE>& operator =(const List<T, ARRAYSIZE>&);


    template <class X, int Z>
    friend ostream& operator << (ostream&, const List<X, Z>&);
    
    template <class X, int Z>
    friend istream& operator >> (istream&, List<X, Z>&);


};

//Implementacion


template<class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValid(const int& p) const {
    return p >= 0 and p <= this->last; //el ultimo es el last (el contador)  
}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE>& other) {
    int i(0);

    while (i <= other.last){
        this->data[i] = other.data[i];

        i++;
    }

    this->last = other.last;
}

template<class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List() {}

template<class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>&  other) {
    this->copyAll(other);
}

template<class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() const {
    return this->last == -1;
}

template<class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() const {
    return this->last == 499;
}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::instData(const int& p, const T& e) {  
    if(this->isFull()){
        throw Exception("Desbordamiento de datos, insData");
         
    }

    if(p != -1 and !this->isValid(p)){
        throw Exception("Posicion Invalida, insData");
    }

    int i(this->last);

    while (i > p){
        this->data[i] = this->data[i+1];

        i--;
    }

    this->data[p+1] = e;

    this->last++;
    
}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::delData(const int& p) {
    if(!this->isValid(p)){
        throw Exception("Posición Invalida, delData");
    }

    int i(p);

    while(i < this->last) {
        this->data[i] = this->data[i+1];

        i++;
    }

    this->last--;
}

template<class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPos() const {
    return this->isEmpty() ? -1: 0;
    
}

template<class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos() const {
    return this->last;
}

template<class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPrevpos(const int& p) const {
    return (p==0 or !this->isValid(p)) ? -1 : (p - 1);

}
template<class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int& p) const {
    return p == this->last or !this->isValid(p) ? - 1 : (p + 1);
}

template<class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findData(const T&) const {
    //Pendiente
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataL(const T& e) const {  //Busqueda lineal
  int i(0);

  while (i <= this->last){
    if(e == this->data[i]) {
      return i;
    }

    i++;

  }

  return -1;

}

template<class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataB(const T& e) const{ //Busqueda Binaria
    int i(0), j(this->last), m;

    while (i <= j) {
        m= (i + j) / 2;

        if(e == this->data[m]){
            return m;

        }

        if(e < this->data[m]){
            j = m - 1;
        }
        else{
            i = m + 1;
        }
    }

    return -1;
}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortData() {
    //Pendiente
}

template<class T, int ARRAYSIZE>
T& List<T, ARRAYSIZE>::retreive(const int& p) {
    if(!this->isValid(p)){
        throw Exception("Posicion invalida, retrieve");
    }

    return this->data[p];

}

template<class T, int ARRAYSIZE>
    string List<T, ARRAYSIZE>::toString() const {
    string result;

    int i(0);

    while (i <= this->last){
        result+= this->data[i].toString() + "\n";

        i++;
    }

    return result;
    
}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::delAll() {
    this->last = -1;
}
template<class T, int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator=(const List& other) {
    this->copyAll(other);

    return *this;
}


template<class X, int Z>
ostream& operator << (ostream& os, const List<X, Z>& l) {
    int i(0);

    while (i <=l.last){
        os << l.data[i]<<endl;

        i++;
    }

    return os;
    
}

template<class X, int Z>
istream& operator >> (istream& is, List<X, Z>& l) {
    X myObj;

    try{
    while (!is.eof()){
        is >> myObj;
    
        l.instData(l.getLastPos(), myObj);
    }
} catch(const invalid_argument& ex) { }
    catch (const typename List<X, Z>::Exception& ex) { }

    return is;
    

}


#endif // __LIST_HPP__