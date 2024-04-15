#ifndef LAB_PROG_MAZZOCCHI_SUBJECT_H
#define LAB_PROG_MAZZOCCHI_SUBJECT_H
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void addObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notifyObservers()=0;
};

#endif //LAB_PROG_MAZZOCCHI_SUBJECT_H
