#include <iostream>
#include "Mesa.h"
#include "Filosofo.h"
#include "Filosofo.cpp"
#include "Mesa.cpp"
#include "windows.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n_filosofos;
    int filosofo_inicio;
    int quantum;
    int simulacion;

    std::cout <<"Seleccione el tipo de simulacion"<< std::endl;
    std::cout <<"1. Simulacion asistida por el usuario"<< std::endl;
    std::cout <<"2. Simulacion aleatoria "<< std::endl;
    std::cin>>simulacion;

    switch(simulacion){

        case 1:
            do{
                std::cout <<"Ingrese el numero de filosofos " << std::endl;
                std::cin >>n_filosofos;
            }while(n_filosofos < 3 || n_filosofos > 20);

             do{
                std::cout <<"Ingrese el numero de filosofo que empieza la cena"<< std::endl;
                std::cin >>filosofo_inicio;
             }while(filosofo_inicio > n_filosofos);

            do{
                std::cout <<"Ingrese el timepo de duracion de cada comida (Quantum) "<< std::endl;
                std::cin >>quantum;
            }while(quantum > 100000 && quantum < 99 );
            break;

        case 2:

            srand(time(NULL));
            n_filosofos = 3 +  rand() % 20;
            filosofo_inicio = 1+ rand() % n_filosofos;
            quantum = 1000 + rand() % 10000 ;
            break;
    }

    std::cout << "Numero de filosofos en la cena: " << n_filosofos << std::endl ;

    /**
     * Sleep(t_comida);
     * **/

    std::cout << "Filosofo que inicia la cena: " << filosofo_inicio << std::endl;
    std::cout << "Tiempo de cada comida (Quantum): " <<quantum << std::endl;

    /**
     * Funcion random
     * srand(time(NULL));
     * int x = rand()%100;
     * std::cout<<"Random "<<x<< std::endl;
     **/
    
    int j = 10;
    Mesa mesa;
    for(int i = 1; i<=n_filosofos; i++){
        mesa.add(i, false, j);
    }

    mesa.print();
    mesa.Comer(filosofo_inicio, quantum, n_filosofos);

    return 0;
}
