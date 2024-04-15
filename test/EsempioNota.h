#ifndef LAB_PROG_MAZZOCCHI_ESEMPIOCARTELLA_H
#define LAB_PROG_MAZZOCCHI_ESEMPIOCARTELLA_H

#include "../src_classi/Cartella.h"
#include "../src_classi/Nota.h"
#include "gtest/gtest.h"

class EsempioNota : public::testing::Test{
protected:
    Nota* nota;

public:
    void SetUp() override;
    void TearDown() override;

};

#endif //LAB_PROG_MAZZOCCHI_ESEMPIOCARTELLA_H
