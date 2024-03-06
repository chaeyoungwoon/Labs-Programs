#include <iostream>

using namespace std;

#include "SortedSet.h"

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &createCopy) : IntList(createCopy){}

SortedSet::SortedSet(const IntList &listCopy) : IntList(listCopy){
    IntList::remove_duplicates();
    IntList::selection_sort();
}

SortedSet::~SortedSet(){}

bool SortedSet::in(int value) const{
    for (IntNode* current = head; current != nullptr; current = current->next){
        if(current->value == value){
            return true;
        }
    }
    return false;
}

SortedSet & SortedSet operator|(const SortedSet& rhs){
    SortedSet *set1 = new SortedSet();

    if ()
}