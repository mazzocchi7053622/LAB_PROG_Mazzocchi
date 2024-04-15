#include "EsempioCartella.h"

//Setter e Getter TITOLO
TEST_F (EsempioCartella, getTitoloCartellaTest){
    ASSERT_EQ (cartella->getNome(), "Raccolta di note di esempio" );
}

TEST_F (EsempioCartella, setTitoloCartellaTest){
    std::string name = "Una raccolta di note di esempio";
    cartella->setNome(name);
    ASSERT_EQ (cartella->getNome(), "Una raccolta di note di esempio" );
}


//Trova la Nota cercandola col titolo
TEST_F (EsempioCartella, getTrovaNotaTest ){ //ho già testato add e remove
    cartella->addNota(nota);
    ASSERT_TRUE(cartella->findNota(nota.getTitolo(), nota));
    // Verifica se la nota appena aggiunta può essere trovata nella cartella utilizzando il suo titolo come criterio di ricerca. Se la ricerca ha successo, l'asserzione passerà

    cartella->removeNota(nota.getTitolo() ); //Rimuove la nota dalla cartella utilizzando il suo titolo come identificatore
    ASSERT_FALSE(cartella->findNota(nota.getTitolo(), nota));
    //Verifica che la nota rimossa non possa più essere trovata nella cartella utilizzando il suo titolo come criterio di ricerca. Se la ricerca non ha successo, l'asserzione passerà.
}

//Aggiungi e Rimuovi Nota
TEST_F (EsempioCartella, addNotaTest){
    ASSERT_EQ ( cartella->getSize(), 0); //verifica la dimensione della cartella prima dell'aggiunta della nota
    cartella->addNota(nota );
    ASSERT_EQ ( cartella->getSize(), 1); //Verifica se effettivamente dopo l'aggiunta la cartella ha dimensione 1
}

TEST_F(EsempioCartella, removeNotaTest){
    cartella->addNota(nota); //Esegue la verifica di sopra al contrario
    ASSERT_EQ ( cartella->getSize(), 1);
    cartella->removeNota(nota.getTitolo() );
    ASSERT_EQ ( cartella->getSize(), 0); //Verifica se effettivamente dopo la rimozione la dimensione della cartella è zero

    // Cancellazione nota bloccata, ASSERT TRUE, controllare se il numero delle note sia cambiato
    cartella->addNota(nota);
    cartella->bloccaNota(nota); //Aggiunta di una nota bloccata
    ASSERT_FALSE(cartella->removeNota(nota.getTitolo())); //Ci si aspetta che la nota non venga rimossa dalla cartella e quindi che il metodo restituisca false
    ASSERT_TRUE(cartella->findNota( nota.getTitolo(), nota)); //di conseguenza dobbiamo ancora trovarla all'interno
    ASSERT_EQ (cartella->getSize(), 1); //e avere dimensione della cartella 1
}

//Test metodo getSize
TEST_F (EsempioCartella, getDimCartellaTest ){
    ASSERT_EQ (cartella->getSize(), 0 ); //controlla che la dim sia zero
    cartella->addNota(nota);
    ASSERT_EQ (cartella->getSize(), 1 ); //controlla che la dim sia 1 dopo l'aggiunta di una nuova nota
    cartella->addNota(nota);
    ASSERT_EQ (cartella->getSize(), 1 ); //non hai la possibilità di aggiungere nuovamente la stessa nota per cui non aumenta la dim
    cartella->removeNota(nota.getTitolo()); //rimuove la nota
    ASSERT_EQ (cartella->getSize(), 0 ); //controlla effettivamente la dim della cartella
    cartella->removeNota(nota.getTitolo()); //prova ad eliminare di nuovo la stessa nota
    ASSERT_EQ (cartella->getSize(), 0 ); //la dimensione non cambia perchè non dovrebbe trovarla nella cartella
}

//Modifica di note bloccate
TEST_F(EsempioCartella, bloccoNoteTest) {
    cartella->addNota(nota);
    nota.setBlocc(true);  //aggiunta alla cartella di una nota marcata come bloccata
    ASSERT_FALSE(cartella->makeFavourite(nota));
    //Verifica che non sia possibile impostare la nota come preferita se è bloccata. Ci si aspetta che questa operazione fallisca e quindi restituisca false.

    nota.setBlocc(false);
    ASSERT_TRUE(cartella->makeFavourite(nota));
    //la nota viene sbloccata e impostata tra i preferiti
}