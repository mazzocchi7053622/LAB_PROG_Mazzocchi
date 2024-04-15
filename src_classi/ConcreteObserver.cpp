#include <iostream>
#include "ConcreteObserver.h"
#include "Subject.h"
#include "Cartella.h"

void ConcreteObserver::update(const Cartella& c) {
    std::cout<<"È stata modificata la cartella " <<c.getNome() <<" a cui sei iscritto adesso: le note presenti ora sono " <<c.getSize() <<std::endl;
}

void ConcreteObserver::subscribe(Subject* subject) {
    (*subject).addObserver(this);
    channelsList.push_back(subject);
}

void ConcreteObserver::unsubscribe(Subject* subject) {
    (*subject).removeObserver(this);

    auto i = std::find(channelsList.begin(), channelsList.end(), subject);
    if(i != channelsList.end()) {  //se ha trovato il nome tra gli abbonati lo rimuove
        channelsList.erase(i);
    }
}

ConcreteObserver::~ConcreteObserver() {
    if(channelsList.empty() )
        return;
    for(auto i = channelsList.begin(); i != channelsList.end(); i++){
        (*i)->removeObserver(this); //si disiscrive da ogni subject a sui era iscritto
    }
}
