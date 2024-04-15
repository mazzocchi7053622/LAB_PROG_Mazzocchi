#include "EsempioNota.h"

void EsempioNota::SetUp()  {
    std::string esTitoloNota = "Saluti";
    std::string esTestoNota = "Ciao mondo!";
    nota = new Nota(esTitoloNota, esTestoNota );
}

void EsempioNota::TearDown()  {
    delete nota;
    nota = nullptr;
}