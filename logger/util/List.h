//
// Created by Atreses on 24/03/2020.
//

#ifndef LOGS_LIST_H
#define LOGS_LIST_H

#include <iostream>


using namespace std;

template <class T>
class List {
public:
    List<T>();
    ~List<T>();
    T get(int index);
    void add(T element);
    bool contains(T element);
    static List<T> *of(T elements[]);
    int size();
private:
    vector<T> elements;
};


template<class T>
List<T>::List() {
    this->elements = vector<T>();
}

template<class T>
void List<T>::add(T element) {
    this->elements.push_back(element);
}

template<class T>
T List<T>::get(int index) {
    return this->elements[index];
}

template<class T>
bool List<T>::contains(T element) {
    for (auto it = this->elements.begin(); it != this->elements.end(); ++it) {
        if (*it.base() == element) {
            return true;
        }
    }
}

template<class T>
List<T> *List<T>::of(T elements[]) {
    List<T> *list = new List<T>();
    for (int i = 0; i < sizeof(elements)/sizeof(elements[0]); ++i) {
        list->add(elements[i]);
    }
    return list;
}

template<class T>
int List<T>::size() {
    return this->elements.size();
}

template<class T>
List<T>::~List<T>() {
    cout << "deleting some list..." << endl;
}

#endif //LOGS_LIST_H
