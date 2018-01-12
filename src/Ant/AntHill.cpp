//
// Created by Maxime SITRUK on 02/01/2018.
//

#include "AntHill.h"

AntHill::AntHill() {}

const vector<AbstractAnt> &AntHill::getAnthillRegistry() const {
    return anthillRegistry;
}

void AntHill::setAnthillRegistry(const vector<AbstractAnt> &anthillRegistry) {
    AntHill::anthillRegistry = anthillRegistry;
}

int AntHill::getId() const {
    return id;
}

void AntHill::setId(int id) {
    AntHill::id = id;
}

void AntHill::generateColony(int id) {
//    AntFactory antFactory;
    AbstractAnt *queenAnt = antFactory.create(1);
    AbstractAnt *warriorAnt = antFactory.create(2);
    AbstractAnt *workerAnt = antFactory.create(3);
    AbstractAnt *workerAnt2 = antFactory.create(3);
    anthillRegistry.push_back(*queenAnt);
    anthillRegistry.push_back(*warriorAnt);
    anthillRegistry.push_back(*workerAnt);
    anthillRegistry.push_back(*workerAnt2);
    setId(id);
}

void AntHill::addWorker() {
    cout << "addWorker" << endl;
//    AntFactory antFactory;
    cout << "addWorker 1" << endl;
    AbstractAnt *workerAnt = antFactory.create(3);
    cout << "addWorker 2" << endl;
//    anthillRegistry.
//    anthillRegistry.reserve(anthillRegistry.size()+1);
//    anthillRegistry.resize(anthillRegistry.size()+1);

//    vector<AbstractAnt> anthillRegistryCopy = this->getAnthillRegistry();
//    anthillRegistryCopy.push_back(*workerAnt);
//    this->setAnthillRegistry(anthillRegistryCopy);
    cout << workerAnt->getType() << endl;
    anthillRegistry.push_back(*workerAnt);
    cout << "addWorker 3" << endl;
}

void AntHill::addWarrior() {
//    AntFactory antFactory;
    AbstractAnt *warriorAnt = antFactory.create(2);
    anthillRegistry.push_back(*warriorAnt);
}
