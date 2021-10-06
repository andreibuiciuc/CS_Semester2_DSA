#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(SortedSet& m) : multime(m)
{
	this->current = this->multime.head;
}
// Theta(1)

void SortedSetIterator::first() {
	this->current = this->multime.head;
}
// Theta(1)

void SortedSetIterator::next() {
	if(this->current == nullptr) {
        throw exception();
	}
	this->current = this->current->next;
}
// Theta(1)


TElem SortedSetIterator::getCurrent()
{
    if(this->current == nullptr) {
        throw exception();
    }
	return this->current->info;
}
// Theta(1)


bool SortedSetIterator::valid() const {
	if(this->current != nullptr) {
        return true;
	}
	return false;
}
// Theta(1)

void SortedSetIterator::last() {
    this->current = this->multime.tail;
}
// Theta(1)

void SortedSetIterator::prev() {
    if(this->current == nullptr) {
        throw exception();
    }
    this->current = this->current->prev;
}
// Theta(1)

TComp SortedSetIterator::remove() {
    if(this->current == nullptr) {
        // If the iterators is not valid.
        throw exception();
    }
    else
    {
        if(this->current == this->multime.tail) {
            // The case when we remove the last node.
            TComp removedElem = this->current->info;
            this->current = nullptr;
            this->multime.remove(removedElem);
            return removedElem;
        }
        else {
            // The basic case.
            TComp removedElem = this->current->info;
            this->current = this->current->next;
            this->multime.remove(removedElem);
            return removedElem;
        }
    }
}
// O(n)