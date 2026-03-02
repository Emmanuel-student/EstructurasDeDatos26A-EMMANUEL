#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <string>
#include <iostream>

#include "name.hpp"
#include "date.hpp"

class Student{
private:
    std::string code;
    Name name;
    Date birthDate;
    std::string career;
    Date starDate;
    float grade;

public:
    Student();
    Student(const Student&);

    std::string getCode()const;
    Name getName()const;
    Date getBirthDate()const;
    std::string getCareer()const;
    Date getStartDate()const;
    float getGrade()const; 

    std::string toString()const;

    void setCode(const std::string&);
    void setName(const Name&);
    void setBirthDate(const Date&);
    void setCareer(const std::string&);
    void setStartDate(const Date&);
    void setGrade(const float&);

    Student& operator = (const Student&);


    bool operator == (const Student&) const;
    bool operator != (const Student&) const;
    bool operator < (const Student&) const;
    bool operator <= (const Student&) const;
    bool operator > (const Student&) const;
    bool operator >= (const Student&) const;

    friend std::ostream& operator << (std::ostream&, const Student&); //Operador de Salida
    friend std::istream& operator >> (std::istream&, Student&); //Operador de Entrada

};
#endif // __STUDENT_HPP__