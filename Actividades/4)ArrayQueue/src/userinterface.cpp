#include "userinterface.hpp"

using namespace std;
using namespace chrono;

UserInterface::UserInterface(){
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(111,999);
    auto randomInt = bind(distribution, generator);

    Queue<int> myCola;
    int myEntero;
    system("cls");

    for(int i(0); i<20; i++){
        myEntero = randomInt();

        cout <<"Encolando: " <<myEntero<<endl;

        myCola.enqueue(myEntero);
        
    }

    cout<<endl<<endl;

    cout<<"Contenido de cola: "<<endl;

    while (!myCola.isEmpty()){
        cout <<myCola.getFront()<<endl;

        myCola.dequeue();
    }

   
    cout<<endl<<endl;

    cout<<"[ENTER] para continuar...";

    cin.get();

    
}