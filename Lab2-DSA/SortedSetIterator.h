#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	SortedSet& multime;
    Node* current;

	SortedSetIterator(SortedSet& m);

public:
	void first();
	void next();

    //removes and returns the current element from the iterator
    //after the operation the current element from the Iterator is the next element from the SortedSet, or,
    // if the removed element was the last one, the iterator is invalid
    //throws exception if the iterator is invalid
    TComp remove();


    TElem getCurrent();
	bool valid() const;
	void last();
	void prev();
};

