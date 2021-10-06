#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    this->nrPositions = 0;
    this->nrElements = 0;
    this->capacityE = 100;
    this->capacityP = 100;
    this->elements = new TElem [this->capacityE];
    this->positions = new int [this->capacityP];
}
// Theta(1)


void Bag::resizeE() {
    this->capacityE = this->capacityE * 2;
    TElem* newElements = new TElem [this->capacityE];

    for(int i = 0; i < this->nrElements; i ++) {
        newElements[i] = this->elements[i];
    }

    delete[] this->elements;
    this->elements = newElements;
}
// Theta(NrElements)


void Bag::resizeP() {
    this->capacityP = this->capacityP * 2;
    int* newPositions = new int [this->capacityP];

    for(int i = 0; i < this->nrPositions; i ++) {
        newPositions[i] = this->positions[i];
    }

    delete[] this->positions;
    this->positions = newPositions;
}
// Theta(NrPositions)


void Bag::add(TElem elem) {
    if(this->capacityE == this->nrElements) {
        this->resizeE();
    }

    if(this->capacityP == this->nrPositions) {
        this->resizeP();
    }

	// First, we have to check if the element is already in the Bag
	bool found = false;
	int index = 0;
	int position;

	while(!found && index < this->nrElements) {
	    if(this->elements[index] == elem) {
	        found = true;
	        position = index;
	    }
	    index ++;
	}

	if(!found) {
	    // We have a new unique element.
	    this->elements[this->nrElements] = elem;
	    this->nrElements ++;
        this->positions[this->nrPositions] = this->nrElements - 1;
        this->nrPositions ++;
	}
	else {
	    // The element is already in the Bag.
        this->positions[this->nrPositions] = position;
        this->nrPositions ++;
	}
}
// Complexity is calculated without the resize case.
//  Best case: The element is in the Bag on the first position of elements: Theta(1)
// Worst case: The element is not in the Bag
//             The element is in the Bag, but on the last position of elements: Theta(nrElements)
// Total complexity: O(nrElements)


bool Bag::remove(TElem elem) {
    int index = 0;
    int position;
    int count = 0;

    while(index < this->nrPositions) {
        if(this->elements[this->positions[index]] == elem) {
            if(count == 0) {
                position = this->positions[index];
                this->positions[index] = this->positions[this->nrPositions-1];
                this->nrPositions --;
                count ++;
                index --;
            }
            else {
                count ++;
            }
        }
        index = index + 1;
    }

    if(count == 1) {
        this->elements[position] = NULL_TELEM;
    }

    if(count >= 1) {
        return true;
    }
    return false;
}
// Theta(nrPositions)


bool Bag::search(TElem elem) const {
	bool found = false;
	int index = 0;

	while(!found && index < this->nrElements) {
	    if(this->elements[index] == elem) {
	        found = true;
	    }
	    index ++;
	}

	if(found)
        return true;

	return false;
}
//  Best case: The element is in the Bag, on the first position of elements: Theta(1)
// Worst case: The element is not in the Bag, or on the last position of elements: Theta(nrElements)
// Total complexity: O(nrElements)


int Bag::nrOccurrences(TElem elem) const {
    int index = 0;
	int count = 0;

	while(index < this->nrPositions) {
	    if(this->elements[this->positions[index]] == elem) {
	        count ++;
	    }
	    index ++;
	}

	return count;
}
// Theta(NrPositions)


int Bag::size() const {
    return this->nrPositions;
}
// Theta(1)

bool Bag::isEmpty() const {
	if(this->nrPositions == 0) {
        return true;
	}
    return false;
}
// Theta(1)


int Bag::getRange() const {
    if(this->nrPositions == 0) {
        // The Bag is empty
        return -1;
    }

    int range, minimum, maximum, index;
    minimum = this->elements[0];
    maximum = this->elements[0];
    index = 1;

    while(index < this->nrElements) {
        if(this->elements[index] < minimum) {
            minimum = this->elements[index];
        }
        if(this->elements[index] > maximum) {
            maximum = this->elements[index];
        }

        index ++;
    }

    range = maximum - minimum;
    return range;
}


BagIterator Bag::iterator() const {
	return BagIterator(*this);
}
// Theta(1)


Bag::~Bag() {
	delete[] this->elements;
	delete[] this->positions;
}
// Theta(1)
