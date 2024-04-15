#include "EsempioCartella.h"

void EsempioCartella::SetUp()  {
    std::string nome = "Raccolta di note di esempio";
    cartella = new Cartella (nome );
}

void EsempioCartella::TearDown()  {
    delete cartella;
    cartella = nullptr;
}