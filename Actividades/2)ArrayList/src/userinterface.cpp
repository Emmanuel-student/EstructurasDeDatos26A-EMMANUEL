#include "userinterface.hpp"

using namespace std;
using namespace chrono;

void UserInterface::mainView(){/*
    //Codigo de valores aleatorios de 111-999
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(111,999);
    auto randomInt = bind(distribution, generator);
    

    int data;
    system("cls");

    for(int i(0); i<20; i++){
        data=randomInt();

        cout << "Insertando "<<data<<endl;

        this->myListRef->instData(this->myListRef->getLastPos(), data);
    }

    cout << endl<< endl; 

    Esta parte era de la primera explicación

    */

    Student myStudent;
    Name myName;
    Date myDate;

    string myStr;
    float myFloat;
    char op;
    int pos;
    system("cls");



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

    this->myListRef->instData(this->myListRef->getLastPos(), myStudent);

    cout << "Otro? (S/N): ";
    cin >> op;
    cin.ignore();

    op= toupper(op);

    } while(op =='S');



    cout <<"Contenido de la lista: "<<endl;

    cout<<this->myListRef->toString();

    cout<<endl<<endl;

    this->enterToContinue();

    /*****************       BUSQUEDAS       **************************** */

    //Busqueda lineal

    cout<<"Codigo para buscar (Busqueda Lineal): ";
    getline(cin, myStr);
    myStudent.setCode(myStr);

    pos = this->myListRef->findDataL(myStudent);

    cout << endl <<endl;

    if(pos == -1) {
        cout<<"El Estudiante con codigo "<< myStr << " NO existe en la lista";
    }
    else{
        cout<<"El Estudiante con codigo "<< myStr <<" Se encuentra en la posicion: " << pos << endl;
        
        cout << "Detalle del estudiante encontrado:" << endl;
        cout << this->myListRef->retreive(pos).toString()<<endl;
    }

    cout << endl <<endl;
    this->enterToContinue();

    //Busqueda Binaria (Dara error porque la lista de estudiantes no esta ordenada)

    cout<<"Codigo para buscar (Busqueda Binaria): ";
    getline(cin, myStr);
    myStudent.setCode(myStr);

    pos = this->myListRef->findDataB(myStudent);

    cout << endl <<endl;

    if(pos == -1) {
        cout<<"El Estudiante con codigo "<< myStr << " NO existe en la lista";
    }
    else{
        cout<<"El Estudiante con codigo "<< myStr <<" Se encuentra en la posicion: " << pos << endl;
        
        cout << "Detalle del estudiante encontrado:" << endl;
        cout << this->myListRef->retreive(pos).toString()<<endl;
    }

    cout << endl <<endl;
    this->enterToContinue();
    
    cout << "Elemento en la posicion 50: "<<endl;
    try{
    cout << this->myListRef->retreive(50).toString();
    } catch(const List<Student, 50>::Exception& ex){
    cout<<"Hubo un Error"<<endl;
    cout<< ex.what() <<endl;
    this->enterToContinue();  
    }

    cout<<endl<<endl;

    this->enterToContinue();

    cout << "Elemento en la posicion 5: "<<endl;
    try{
    cout << this->myListRef->retreive(5).toString()<<endl;
  } catch(const List<Student, 50>::Exception& ex){
    cout<<"Hubo un Error"<<endl;
    cout<< ex.what() <<endl;
    this->enterToContinue();
  }

    cout << "Escribiendo al archivo..."<<endl;

    ofstream myFile("milistadeestudiantes.txt", ios_base::trunc);    //se debe de capturar el nombre del archivo

    if(myFile.is_open()){
        myFile << *this->myListRef;

        myFile.close();  //Super importante cerrar el archivo

        cout << "Archivo escrito satisfactoriamente"<<endl;

    }
    else{
        cout << "el Archivo no se pudo abrir"<<endl;
    }

    std::cout <<"leyendo del archivo..." <<endl;

    ifstream myFile2("milistadeestudiantes.txt");

    if(myFile2.is_open()){
        myFile2 >> *this->myListRef;

        myFile2.close(); //Super importante cerrar el archivo

        std::cout<<"Archivo leido"<<endl;
    }
    else{
        std::cout<<"No se pudo Abrir el Archivo"<<endl;
    }

    std::cout<<endl<<endl;

    std::cout <<"Contenido de la lista: "<<endl;

    std::cout<<myListRef->toString();

    this->enterToContinue();

}

void UserInterface::enterToContinue(){
    std::cout << "[ENTER para continuar]...";
    cin.get();
}

UserInterface::UserInterface(List<Student, 50>& p) : myListRef(&p) { 
    this->mainView();
}
