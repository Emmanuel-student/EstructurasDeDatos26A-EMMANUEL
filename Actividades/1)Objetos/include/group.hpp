#ifndef __GROUP_HPP__
#define __GROUP_HPP__

#include <string>

#include "student.hpp"


class Group{
private:
    Student data[50];
    int size = 0;

public:
    Group();

    void addStudent(const Student&);

    void delStudent(const Student&);

    std::string toString() const;

    int findStudent(const Student&);

    void modStudent(const int&, const Student&);

};
#endif // __GROUP_HPP__