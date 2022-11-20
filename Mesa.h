//
// Created by Lina Rodriguez on 13/11/2022.
//
#include "Filosofo.h"

#ifndef FILOSOFOSCOMENSALES_MESA_H
#define FILOSOFOSCOMENSALES_MESA_H


class Mesa {
    private:
    Filosofo* header;
    Filosofo* Tail;

    public:
    Mesa();
    ~Mesa();
    void add(int _filo, bool _state, int _hambre);
    void Comer(int inicio, int _quantum, int n_filosofos);
    void Turno(Filosofo*);
    int remove(int filo);
    void eliminar(int filo);
    void print();
    bool search(int filo);
    bool isEmpty();
};


#endif //FILOSOFOSCOMENSALES_MESA_H
