#include "EsempioNota.h"

//Setter e Getter TITOLO
TEST_F (EsempioNota, getTitoloNotaTest){
    ASSERT_EQ (nota->getTitolo(), "Saluti" );
}

TEST_F (EsempioNota, setTitoloNotaTest){
    std::string nome = "Saluti a tutti";
    nota->setTitolo(nome);
    ASSERT_EQ (nota->getTitolo(), "Saluti a tutti");
}

//Setter e Getter TESTO
TEST_F (EsempioNota, getTestoNotaTest){
    ASSERT_EQ (nota->getTesto(), "Ciao mondo!" );
}

TEST_F (EsempioNota, setTestoNotaTest){
    std::string nome = "Ciao universo!";
    nota->setTesto(nome);
    ASSERT_EQ (nota->getTesto(), "Ciao universo!");
}

//Test metodo di blocco nota
TEST_F (EsempioNota, getBloccoNotaTest){
    ASSERT_FALSE(nota->isBlocc());
}

TEST_F (EsempioNota, setBloccoNotaTest){
    bool blocc = true;
    nota->setBlocc(blocc);
    ASSERT_TRUE(nota->isBlocc());
}

//Test di impostazione della nota come preferita
TEST_F (EsempioNota, getPrefNotaTest){
    ASSERT_FALSE(nota->isPref());
}

TEST_F (EsempioNota, setPrefNotaTest){
    bool pref = true;
    nota->setPref(pref);
    ASSERT_TRUE(nota->isPref());
}