//
// Created by Lina Rodriguez on 13/11/2022.
//

#ifndef FILOSOFOSCOMENSALES_FILOSOFO_H
#define FILOSOFOSCOMENSALES_FILOSOFO_H


class Filosofo {
    private:
        int filo;
        int hambre;
        bool state;
        Filosofo* next = nullptr;
        Filosofo* Prev;

    public:
    Filosofo(int filo, bool state, int hambre);
    ~Filosofo();

    void setInfo(int filo, bool state, int hambre);
    int getInfo();
    bool getState();
    int getHambre();
    void setNext(Filosofo*);
    void setState(bool);
    void setHambre(int);
    Filosofo *getNext();
    void setPrev(Filosofo*);
    Filosofo *getPrev();
    void print();
};

#endif //FILOSOFOSCOMENSALES_FILOSOFO_H
