//
// Created by Maxime SITRUK on 02/01/2018.
//

#ifndef FOURMILIERE_ANT_H
#define FOURMILIERE_ANT_H


class AbstractAnt {

public:
    virtual int getType() const;
    virtual void setType(int type);
private:
    int type;
};


#endif //FOURMILIERE_ANT_H
