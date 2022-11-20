//
// Created by Lina Rodriguez on 13/11/2022.
//

#include "Filosofo.h"
Filosofo::Filosofo(int _filo, bool _state, int _hambre){
    filo = _filo;
    state = _state;
    hambre = _hambre;
    next = nullptr;
    Prev = nullptr;
}

void Filosofo::setInfo(int _filo, bool _state, int _hambre){
    filo = _filo;
    state = _state;
    hambre = _hambre;
}

bool Filosofo::getState() {
    return state;
}

int Filosofo::getHambre(){
    return hambre;
}

int Filosofo::getInfo(){
    return filo;
}

void Filosofo::setNext(Filosofo* nuevo){
    next = nuevo;
}

Filosofo* Filosofo::getNext(){
    return next;
}

void Filosofo::setPrev(Filosofo* Prev){
    Prev = Prev;
}

Filosofo* Filosofo::getPrev() {
    return Prev;
}

void Filosofo::setState(bool _state) {
    state = _state;
}

void Filosofo::setHambre(int _hambre) {
    hambre = _hambre;
}

void Filosofo::print(){
    std::cout<< filo;
}
