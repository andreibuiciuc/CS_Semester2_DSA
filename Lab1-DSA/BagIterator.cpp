#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->current = 0;
}
// Theta(1)

void BagIterator::first() {
	this->current = 0;
}
// Theta(1)

void BagIterator::next() {
    if(this->current == this->bag.nrPositions) {
        throw exception();
    }
    else {
        this->current ++;
    }
}
//Theta(1)

bool BagIterator::valid() const {
    if(this->current < this->bag.nrPositions) {
        return true;
    }
    else {
        return false;
    }
}
// Theta(1)


TElem BagIterator::getCurrent() const
{
    if(this->current == this->bag.nrPositions) {
        throw exception();
    }
    return this->bag.elements[this->bag.positions[this->current]];
}
//Theta(1)