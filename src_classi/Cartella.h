#ifndef LAB_PROG_MAZZOCCHI_CARTELLA_H

#include <string>
#include <list>
#include <algorithm>
#include "Nota.h"
#include "Subject.h"

class Cartella : public Subject {
private:
    std::list<Observer *> observerList; //lista di osservatori

protected:
    std::string nome; //nome della cartella
    std::list<Nota> listaNote; //lista di note
    std::list<Nota> notePreferite; //lista di note nei preferite
    std::list<Nota> noteBloccate; //lista di note bloccate

public:
    explicit Cartella(const std::string &n) : nome(n) {};  //costruttore

    ~Cartella() override = default; //la libreria <list> distrugge da sola gli elementi al proprio interno quando va fuori scopo
    const std::string &getNome() const;
    void setNome(const std::string &nome);

    //aggiungi e rimuovi nota alla cartella
    bool addNota(const Nota &nota);
    bool removeNota(const std::string titolo);

    int getSize() const;//restituisce il numero di note

    //blocca/sblocca nota, aggiunge/rimuove dai preferiti
    void bloccaNota(const Nota &nota);
    void sbloccaNota(const Nota &nota);
    bool makeFavourite(Nota &nota);
    bool removeFavourite(const Nota &nota);
    std::list<std::string> listaBloccati();
    std::list<std::string> listaPreferiti();

    //ricerca nota tramite il titolo
    bool findNota(const std::string &titolo, Nota &nota) const;


    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() override;

};

#endif //LAB_PROG_MAZZOCCHI_CARTELLA_H
