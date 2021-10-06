#pragma once
#include "SortedBag.h"

class SortedBag;

struct Stack{
    int* elems;
    int index;
};

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

    Stack stack{};
    int currentPosition;

public:
	TComp getCurrent();
	bool valid() const;
	void next();
	void first();

    ~SortedBagIterator();
};

