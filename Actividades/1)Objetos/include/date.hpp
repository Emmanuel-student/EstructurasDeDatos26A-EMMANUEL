#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <string>
#include <iostream>
#include <chrono>

class Date {
private:
    int year;
    int month;
    int day;

    bool isValid(const int&, const int&, const int&);
    int toInt()const;



public:
    Date();
    Date(const Date&);
    Date(const int&, const int&, const int&);

    int getYear()const;
    int getMonth()const;
    int getDay()const;

    std::string toString()const;

    void setYear(const int&);
    void setMonth(const int&);
    void setDay(const int&);

    bool operator == (const Date&) const;
    bool operator != (const Date&) const;
    bool operator < (const Date&) const;
    bool operator <= (const Date&) const;
    bool operator > (const Date&) const;
    bool operator >= (const Date&) const;
    
    Date& operator = (const Date&);

    friend std::ostream& operator << (std::ostream&, const Date&); //Operador de Salida
    friend std::istream& operator >> (std::istream&, Date&); //Operador de Entrada





};
#endif // __DATE_HPP__