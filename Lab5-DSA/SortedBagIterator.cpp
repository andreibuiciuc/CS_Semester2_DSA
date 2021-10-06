#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->stack.elems = new TElem [this->bag.length];
    this->stack.index = -1;

    int currentIndex = this->bag.root;
    while(currentIndex != -1) {
        this->stack.index += 1;
        stack.elems[stack.index] = currentIndex;
        currentIndex = this->bag.left[currentIndex];
    }

    if(this->stack.index != -1) {
        this->currentPosition = this->stack.elems[this->stack.index];
    }
    else {
        this->currentPosition = -1;
    }
}
// Time Complexity: Theta(n)

TComp SortedBagIterator::getCurrent() {
    if(this->currentPosition == -1) {
        throw exception();
    }
    return this->bag.info[this->currentPosition];
}
// Time Complexity: Theta(1)

bool SortedBagIterator::valid() const {
	if(this->currentPosition == -1) {
        return false;
	}
	return true;
}
// Time Complexity: Theta(1)

void SortedBagIterator::next() {
    if(this->currentPosition == -1) {
        throw exception();
    }

    int currentIndex = this->stack.elems[this->stack.index];
    this->stack.index -= 1;

    if(this->bag.right[currentIndex] != -1) {
        currentIndex = this->bag.right[currentIndex];
        while(currentIndex != -1) {
            this->stack.index += 1;
            this->stack.elems[this->stack.index] = currentIndex;
            currentIndex = this->bag.left[currentIndex];
        }
    }

    if(this->stack.index != -1) {
        this->currentPosition = this->stack.elems[this->stack.index];
    }
    else {
        this->currentPosition = -1;
    }
}
// Time Complexity: O(n)

void SortedBagIterator::first() {
    delete[] this->stack.elems;
    this->stack.elems = new TElem [this->bag.length];
    this->stack.index = -1;

    int currentIndex = this->bag.root;
    while(currentIndex != -1) {
        this->stack.index += 1;
        stack.elems[stack.index] = currentIndex;
        currentIndex = this->bag.left[currentIndex];
    }

    if(this->stack.index != -1) {
        this->currentPosition = this->stack.elems[this->stack.index];
    }
    else {
        this->currentPosition = -1;
    }
}
// Time Complexity: O(n)

SortedBagIterator::~SortedBagIterator() {
    delete[] this->stack.elems;
}
// Time Complexity: Theta(1)
