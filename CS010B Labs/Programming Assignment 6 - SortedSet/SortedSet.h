#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"
using namespace std;

class SortedSet : public IntList {
    public:
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        bool in(int value) const;
        SortedSet operator|(const SortedSet& rhs);
        SortedSet operator&(const SortedSet& rhs);
        void add(int value);
        void push_front(int value) override;
        void push_back(int value) override;
        void insert_ordered(int value) override;
        SortedSet operator|=(const SortedSet& rhs);
        SortedSet operator&=(const SortedSet& rhs);
};

#endif