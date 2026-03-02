#include "userinterface.hpp"
#include "list.hpp" //Buena practica
#include "student.hpp"

int main()
{
    List<Student, 50> myList;

    UserInterface myUI(myList);

    /*List<float> myList2;

    List<Student> myList3;

    UserInterface myUI(myList);*/
}
