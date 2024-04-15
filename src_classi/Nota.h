#ifndef LAB_PROG_MAZZOCCHI_NOTA_H
#define LAB_PROG_MAZZOCCHI_NOTA_H
#include<string>

class Nota {
protected:
    std::string titolo, testo; //rispettivamente titolo e testo della nota
    bool blocc ; //indica se la nota può essere modificata o meno, bloccandola
    bool pref ; //la nota è messa tra i preferiti per messa nella cartella apposita

public:
    Nota(const std::string& tit, const std::string& tes, bool b=false, bool p=false): titolo(tit), testo(tes), blocc(b), pref(p){};  //costruttore

    //set e get di tutti gli attributi
    const std::string &getTitolo() const;
    bool setTitolo(const std::string &titolo);
    const std::string &getTesto() const;
    bool setTesto(const std::string &testo);
    bool isBlocc() const;
    void setBlocc(bool blocc);
    bool isPref() const;
    bool setPref(bool pref);

    //overloading operatore ==
    bool operator==(const Nota& nota2) const;
    Nota operator=(const Nota& nota2);
};

#endif //LAB_PROG_MAZZOCCHI_NOTA_H