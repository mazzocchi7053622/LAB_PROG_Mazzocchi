#include <iostream>
#include "Cartella.h"

std::list<Nota> Cartella::notePreferite;
std::list<Nota> Cartella::noteBloccate;

const std::string &Cartella::getNome() const {
    return nome;
}

void Cartella::setNome(const std::string &nome) {
    this->nome = nome;
    notifyObservers();
}

bool Cartella::addNota(const Nota &nota) {
    auto i = std::find(listaNote.begin(), listaNote.end(), nota); //ritorna la pos della nota
    if (i != listaNote.end()) { //se la pos è diversa dalla fine = la nota è già presente
        return false; //non posso aggiungere se è già all'interno
    }

    listaNote.push_back(nota); //non esiste dentro la cartella una nota con questo nome

    if (nota.isPref()) //se la nota da aggiungere è marcata preferita la aggiunge direttamente alla apposita lista
        notePreferite.push_back(nota);

    if(nota.isBlocc()) //se la nota da aggiungere è marcata bloccata la aggiunge direttamente alla apposita lista
        noteBloccate.push_back(nota);

    notifyObservers();
    return true;
}

bool Cartella::removeNota(const std::string titolo) {
    for (auto i : listaNote) {
        if (i.getTitolo() == titolo) {
            if (i.isBlocc()) { //se trova la nota ma è bloccata ne impedisce la cancellazione
                std::cout<< "La nota è bloccata: impossibile cancellare" << std::endl;
                return false;
            }
            //altrimenti procede a rimuoverla
            listaNote.remove(i);
            notePreferite.remove(i);
            notifyObservers();
            return true;
        }
    }
    return false; //se la nota non è proprio presente all'interno della cartella
}


int Cartella::getSize() const { //non passare nulla sotto o uguale a double per riferimento, solo strinnghe e oggetti complicati
    return listaNote.size();
}

void Cartella::bloccaNota(const Nota &nota) {
    auto i = std::find(listaNote.begin(), listaNote.end(), nota);

    if (i != listaNote.end()) {
        i->setBlocc(true);
        noteBloccate.push_back(*i);
    } else {
        std::cout << "Nota non trovata nella lista." << std::endl;
    }
}

void Cartella::sbloccaNota(const Nota &nota) {

    auto i = std::find(listaNote.begin(), listaNote.end(), nota);
    if (i != listaNote.end()) {
        i->setBlocc(false);
        noteBloccate.remove(*i);
    }
}


bool Cartella::makeFavourite(Nota &nota) {
    bool pref = false;
    auto i = std::find(listaNote.begin(), listaNote.end(), nota);

    if (i != listaNote.end()) {
        if (i->isBlocc()) {  //se trovo la nota e non è bloccata la metto tra i preferiti
            std::cout << "Nota non modificabile." << std::endl;
            pref = false;
        }
        else {
            i->setPref(true);
            notePreferite.push_back(*i);
            std::cout << "Nota modificata e aggiunta ai preferiti." << std::endl;
            pref = true;
        }
    }
    return pref;
}

bool Cartella::removeFavourite(const Nota &nota) {
    auto i = std::find_if(notePreferite.begin(), notePreferite.end(), [&](const Nota& n){ return n.getTitolo() == nota.getTitolo(); });
    if(i != notePreferite.end() && !i->isBlocc()) {  //la nota è presente in lista e non è bloccata = posso modificarla
        notePreferite.erase(i);
        return true;
    }
    else{
        std::cout<< "La nota è bloccata, non può essere modificata" << std::endl;
        return false;
    }
}

std::list<std::string> Cartella::listaBloccati() {
    std::list<std::string> titlesList;
    for (const auto &i: noteBloccate) {
        titlesList.push_back(i.getTitolo());
    }
    return titlesList;
}

std::list<std::string> Cartella::listaPreferiti() {
    std::list<std::string> titlesList;
    for (const auto &i: notePreferite) {
        titlesList.push_back(i.getTitolo());
    }
    return titlesList;
}

bool Cartella::findNota(const std::string &title, Nota &nota) const {
    for (const auto &i: listaNote)
        if (i.getTitolo() == title) {
            nota = i;
            return true;
        }
    return false;
}



void Cartella::addObserver(Observer *o) {
    auto i = std::find(observerList.begin(), observerList.end(), o); //ritorna la pos che punta all'observer
    if (i == observerList.end()) {
        observerList.push_back(o); // se l'osservatore non è già iscritto, lo iscrive
        return;
    }
    std::cout << "L'osservatore è già presente nella lista" << std::endl;
}

void Cartella::removeObserver(Observer *o) {
    auto i = std::find(observerList.begin(), observerList.end(), o); //ritorna la pos che punta all'observer
    if (*i == o) {
        observerList.remove(o); // se l'osservatore c'è lo disiscrive
        return;
    }
}

void Cartella::notifyObservers() {
    if (observerList.empty())
        return;
    for (auto &i: observerList)
        i->update(*this);
}