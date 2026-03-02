#include "userinterface.hpp"

using namespace std;
using namespace chrono;

UserInterface::UserInterface(){
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(111,999);
    auto randomInt = bind(distribution, generator);

    Stack <int> myPila;
    int myEntero;
    system("cls");

    for(int i(0); i<20; i++){
        myEntero = randomInt();

        cout <<"Apilando: " <<myEntero<<endl;

        myPila.push(myEntero);
        
    }

    cout<<endl<<endl;

    Stack<int> myOtraPila(myPila);

    cout<<"Volcado de pila"<<endl;

    while (!myPila.isEmpty()){
        cout <<myPila.getTop()<<endl;

        myPila.pop();
    }

    try{
        myPila.pop();
    } catch (const typename Stack<int>::Exception& ex) {
        cout<<"Hubo un error: " << ex.what()<<endl;
        cout<<"[ENTER] para continuar...";
    
        cin.get();
    }

    cout<<endl<<endl;

    cout<<"Volcado de la otra pila"<<endl;

    while (!myOtraPila.isEmpty()){
        cout <<myOtraPila.pop()<<endl;

    }



    cout<<endl<<endl;


    cout<<endl<<endl;

    cout<<"[ENTER] para continuar...";

    cin.get();

    
}