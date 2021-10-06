#pragma once
#include "IndexedList.h"


class ListIterator{
    //DO NOT CHANGE THIS PART
	friend class IndexedList;
private:
	const IndexedList& list;
	int currentElement;
		
    ListIterator(const IndexedList& lista);
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;

    //changes the current element from the iterator to the previous element, or,
    // if the current element was the first, makes the iterator invalid
    //throws an exception if the iterator is not valid
    void previous();

};

