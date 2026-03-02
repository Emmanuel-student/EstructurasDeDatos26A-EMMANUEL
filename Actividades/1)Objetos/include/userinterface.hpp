#ifndef __USERINTERFACE_HPP__
#define __USERINTERFACE_HPP__

#include <iostream>
#include<string>

#include "group.hpp"
#include "student.hpp"
#include "name.hpp"
#include "date.hpp"
//Ya viene name y date en student pero es una buena practica el no suponer que una librería esta dentro de otra

class UserInterface{
private:
    void enterToContinue();

public:
    UserInterface();

};

#endif // __USERINTERFACE_HPP__