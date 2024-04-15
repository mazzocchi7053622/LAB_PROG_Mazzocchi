#ifndef LAB_PROG_MAZZOCCHI_CONCRETEOBSERVER_H
#define LAB_PROG_MAZZOCCHI_CONCRETEOBSERVER_H

#include "Observer.h"
#include <list>
#include <algorithm>

class ConcreteObserver : public Observer {
protected:
    std::string nome;
    std::list<Subject*> channelsList; //lista di puntatori ai canali a cui l'observer è abbonato

public:
    explicit ConcreteObserver(const std::string& n) : nome(n) {}

    ~ConcreteObserver() override; //se il ConcreteObject è iscritto a qualche canale lo disiscrive, altrimenti non fa nulla

    void update(const Cartella& c) override; //numero di note nella cartella
    virtual void subscribe(Subject* subject);
    virtual void unsubscribe(Subject* subject);
};
#endif //LAB_PROG_MAZZOCCHI_CONCRETEOBSERVER_H
