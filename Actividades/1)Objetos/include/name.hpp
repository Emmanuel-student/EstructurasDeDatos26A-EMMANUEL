#ifndef __NAME_HPP__
#define __NAME_HPP__

#include <string>
#include <iostream>

class Name{
private:
    std::string last;
    std::string first;

public:
    Name();
    Name(const Name&);
    Name(const std::string&, const std::string&);

    std::string getLast()const;
    std::string getFirst()const;

    std::string toString()const;

    void setLast(const std::string&);
    void setFirst(const std::string&);


    Name& operator = (const Name&);


    bool operator == (const Name&) const;
    bool operator != (const Name&) const;
    bool operator < (const Name&) const;
    bool operator <= (const Name&) const;
    bool operator > (const Name&) const;
    bool operator >= (const Name&) const;

    friend std::ostream& operator << (std::ostream&, const Name&); //Operador de Salida
    friend std::istream& operator >> (std::istream&, Name&); //Operador de Entrada


};


#endif // __NAME_HPP__