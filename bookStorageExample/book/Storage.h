//
// Created by Atreses on 29/03/2020.
//

#ifndef LOGS_STORAGE_H
#define LOGS_STORAGE_H

#include <iostream>
#include <map>
#include "../../logger/Logger.h";

using namespace std;

template <class T>
class Storage {
public:
    Storage();
    ~Storage();
    int add(T element);
    T get(int id);
    void deleteByIndex(int id);

private:
    int nextId;
    map<int, T> elements;

};

template<class T>
Storage<T>::Storage() {
    this->nextId = 1;
}

template<class T>
Storage<T>::~Storage() {
}

template<class T>
int Storage<T>::add(T element) {
    int elementId = this->nextId;
    elements.insert(pair<int, T>(this->nextId, element));
    nextId++;

    Logger::getInstance().debug("Successfully added new element");
    return elementId;
}

template<class T>
T Storage<T>::get(int index) {
    if (elements.count(index) == 0) {
        Logger::getInstance().warn("Element with given index not found!");
        return nullptr;
    }
    return elements.at(index);
}

template<class T>
void Storage<T>::deleteByIndex(int index) {
    if (elements.count(index) == 0) {
        Logger::getInstance().error("Element with given index not found! Cannot perform delete operation");
        return;
    }
    Logger::getInstance().info("Removed element");
    elements.erase(index);
}


#endif //LOGS_STORAGE_H
