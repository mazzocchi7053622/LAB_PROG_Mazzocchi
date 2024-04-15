#ifndef LAB_PROG_MAZZOCCHI_ESEMPIOCARTELLA_H
#define LAB_PROG_MAZZOCCHI_ESEMPIOCARTELLA_H

#include "../src_classi/Cartella.h"
#include "../src_classi/Nota.h"
#include "gtest/gtest.h"

class EsempioCartella : public::testing::Test{
protected:
    Cartella* cartella;
    std::string esTitoloNota = "Saluti";
    std::string esTestoNota = "Ciao mondo!";
    Nota nota = Nota (esTitoloNota, esTestoNota );

public:
    void SetUp() override;
    void TearDown() override;

};

#endif //LAB_PROG_MAZZOCCHI_ESEMPIOCARTELLA_H
