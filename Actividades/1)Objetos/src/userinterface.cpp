#include "userinterface.hpp"

using namespace std;
void UserInterface::enterToContinue(){
    cout << "[ENTER] para continuar";
    cin.get();    
}
UserInterface::UserInterface(){
    Group myGroup;
    Student myStudent;
    Name myName;
    Date myDate;

    string myStr;
    float myFloat;
    char op;
    system("cls");

    cout<<"Captura de estudiantes" << endl << endl;

    do{

    cout << "Codigo: ";
    getline(cin, myStr);

    myStudent.setCode(myStr);

    cout<<"Apellido (s): ";
    getline(cin, myStr);

    myName.setLast(myStr);

    cout<<"Nombre (s): ";
    getline(cin, myStr);

    myName.setFirst(myStr);

    myStudent.setName(myName);

    cout <<"Fecha de Nacimiento (dd/mm/mmmm): ";
    getline(cin, myStr, '/');

    myDate.setDay(stoi(myStr));

    getline(cin, myStr, '/');

    myDate.setMonth(stoi(myStr));

    getline(cin, myStr);

    myDate.setYear(stoi(myStr));

    myStudent.setBirthDate(myDate);

    cout <<"Carrera: ";
    getline(cin, myStr);

    myStudent.setCareer(myStr);

    cout <<"Fecha de Inicio (dd/mm/mmmm): ";
    getline(cin, myStr, '/');

    myDate.setDay(stoi(myStr));

    getline(cin, myStr, '/');

    myDate.setMonth(stoi(myStr));

    getline(cin, myStr);

    myDate.setYear(stoi(myStr));

    myStudent.setStartDate(myDate);

    cout<<"Promedio: ";
    cin>>myFloat;

    myStudent.setGrade(myFloat);

    myGroup.addStudent(myStudent);

    cout << "Otro? (S/N): ";
    cin >> op;
    cin.ignore();

    op= toupper(op);

    } while(op =='S');

    cout<<endl<<endl;

    cout<<"Grupo Capturado: "<<endl<<endl;

    cout<<myGroup.toString()<<endl;

    cout<<endl<<endl;

    enterToContinue();

    
    
}

