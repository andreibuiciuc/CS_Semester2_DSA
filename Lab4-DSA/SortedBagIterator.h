#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

    SLL* copy;
    int minPos;
    int currentFreq;

public:

	TComp getCurrent();
	bool valid() const;
	void next();
	void first();

    // moves the current element from the iterator k steps forward, or makes the iterator invalid
    // if there are less than k elements left in the SortedBag.
    //
    // throws an exception if the iterator is invalid or if k is negative or zero
    void jumpForward(int k);


    ~SortedBagIterator();
};

