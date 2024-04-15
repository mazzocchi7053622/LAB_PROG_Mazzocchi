#ifndef LAB_PROG_MAZZOCCHI_OBSERVER_H
#define LAB_PROG_MAZZOCCHI_OBSERVER_H

class Subject;
class Cartella;

class Observer {
public:
    virtual void update(const Cartella& c)=0;

    virtual ~Observer() = default;
};

#endif //LAB_PROG_MAZZOCCHI_OBSERVER_H
