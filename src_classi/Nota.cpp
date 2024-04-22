#include "Nota.h"

const std::string &Nota::getTitolo() const {
    return titolo;
}

bool Nota::setTitolo(const std::string &titolo) {  //permette di modificare il titolo solo se non risulta bloccata
    if(!this->blocc){
        this->titolo = titolo;
        return true;
    }
    else{
        return false;
    }
}

const std::string &Nota::getTesto() const {
    return testo;
}

bool Nota::setTesto(const std::string &testo) { //permette di modificare il testo solo se non risulta bloccata
    if(!this->blocc){
        this->testo = testo;
        return true;
    }
    else{
        return false;
    }
}

bool Nota::isBlocc() const {
    return blocc;
}

void Nota::setBlocc(bool blocc) {
    this->blocc = blocc;
}

bool Nota::isPref() const {
    return pref;
}

bool Nota::setPref(bool pref) {
    if(!this->blocc){
        this->pref = pref;
        return true;
    }
    else{
        return false;
    }
}

bool Nota::operator==(const Nota &nota2) const {
    if(this->titolo == nota2.titolo && this->testo == nota2.testo && this->blocc == nota2.blocc && this->pref == nota2.pref)
        return true;
    else{
        return false;
    }
}