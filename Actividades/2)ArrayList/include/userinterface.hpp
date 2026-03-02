#ifndef __USERINTERFACE_HPP__
#define __USERINTERFACE_HPP__

#include <iostream>
#include <random>
#include <chrono>
#include <functional>
#include <fstream>

#include "list.hpp"
#include "student.hpp"

class UserInterface{
private:
    List<Student, 50>* myListRef;

    void mainView();

    void enterToContinue();

public:
    UserInterface(List<Student, 50>&);


};

#endif // __USERINTERFACE_HPP__