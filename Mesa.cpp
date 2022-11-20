//
// Created by Lina Rodriguez on 13/11/2022.
//

#include "Mesa.h"
#include <iostream>
#include "windows.h"

Mesa::Mesa() {
    header = nullptr;
    Tail = nullptr;
}

void Mesa::add(int filo, bool _state, int hambre) {
    Filosofo* nuevo = new Filosofo(filo, _state, hambre);
    if(header==nullptr){
        header = nuevo;
        header->setNext(header);
        Tail = header;
    }
    else {

        Filosofo *aux = header;
        while (aux->getNext() != header){
            aux = aux->getNext();
        }
        aux->setNext(nuevo);
        nuevo->setNext(header);
       header->setPrev(Tail);
   }
}
Mesa::~Mesa() {

}


void Mesa::Comer(int inicio, int quantum, int n_filosofos){

   int _inicio = inicio;
   int _quantum = quantum;
   int _nfilosofos = n_filosofos;

   Filosofo *aux = header;

  do{
      while (aux->getInfo()!= _inicio ){
          aux = aux->getNext();
      }

      Turno(aux);
      Sleep(_quantum);
      std::cout<<"Nuevo turno"<< std::endl;
      srand(time(NULL));
      _inicio = 1 + rand() % _nfilosofos;


      while (aux->getState()) {
          aux->setState(false);
          aux = aux->getNext();
      }

  }while(!isEmpty());

}

void Mesa::Turno(Filosofo* aux) {

   int aux1 = aux->getInfo();
   do{
       aux->setState(true);
       aux->setHambre(aux->getHambre() - 2);

       while(aux->getHambre()<0){
           if(aux->getHambre()<0){
               std::cout << remove(aux->getInfo()) <<" Salio de la cena " << std::endl;
               if(isEmpty()){
                   system("pause");

               }
           }else if( !search(aux->getInfo())){
               aux = aux->getNext();
           }else{
               system("pause");
           }

       }

       std::cout << std::endl;
       std::cout << "Filosofo " << aux->getInfo();

       if(aux->getState() == 0){
           std::cout << "\t Estado Pensando" ;
       }else{
           std::cout << "\t Estado Comiendo" ;
       }

       std::cout << " \t Hambre " << aux->getHambre() << std::endl;

       aux = aux->getNext();
       aux = aux->getNext();

   }while(aux->getInfo()!=aux1 && !aux->getState() && !aux->getNext()->getState());



}



int Mesa::remove(int filo) {
   int cont=1;
   Filosofo *aux = header;
   Filosofo *ant = nullptr;

   while(cont<=filo){
       if(header==nullptr){
           return 0;
       }
       else if(header->getNext()==header){
           int x;
           x = header->getInfo();
           header = nullptr;
           return x;
       }
       ant = aux;
       aux = aux->getNext();
       cont++;
   }
   ant->setNext(aux->getNext());
   header = aux->getNext();
   return aux->getInfo();
}

bool Mesa::search(int filo) {
   if(isEmpty()){
       return false;
   }
   else{
       Filosofo *aux = header;
       Filosofo *prev = nullptr;
       while (aux->getNext() != header && aux->getInfo() != filo){
           prev = aux;
           aux = aux->getNext();
       }
       if(aux->getNext() != header){
           header = aux;
           return true;
       }
       else{
           return false;
       }
   }
}
void Mesa::print() {
   Filosofo *aux = header;
   do{
       std::cout<<" -> "<<aux->getInfo();
       aux = aux->getNext();
   }while (aux != header);
}
bool Mesa::isEmpty() {
   if(header==nullptr){
       return true;
   }
   else{
       return false;
   }}

void Mesa::eliminar(int filo) {
   int _filo = filo;
   Filosofo *auxcab = header;
   Filosofo *aux;

   if(auxcab->getInfo()==filo){
       if(auxcab->getInfo() == header->getInfo()){
           header = header->getNext();
           Tail->setNext(header);
       }else if(auxcab->getInfo()==Tail->getInfo()){
           aux->setNext(header);
           Tail->setInfo(aux->getInfo(), aux->getState(), aux->getHambre());
       }else{
           aux->setNext(auxcab->getNext());
       }

       auxcab = aux;
       aux = aux->getNext();
   }
}
