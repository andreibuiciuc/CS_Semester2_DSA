#include "IndexedList.h"
#include "ListIterator.h"
#include <exception>

using namespace std;

IndexedList::IndexedList() {
	this->capacity = 100;
    this->elems = new TElem[capacity];
    this->next = new int[capacity];
    this->head = -1;
    this->length = 0;

    for(int i = 0; i < this->capacity - 1; i ++) {
        this->next[i] = i + 1;
    }
    this->next[this->capacity-1] = -1;
    this->firstEmpty = 0;
}
// Complexity: Theta(n)


void IndexedList::resize() {
    this->capacity = this->capacity * 2;
    auto* newElems = new TElem [this->capacity];
    int* newNext = new int [this->capacity];

    for(int i = 0; i < this->capacity / 2; i ++) {
        newElems[i] = this->elems[i];
        newNext[i] = this->next[i];
    }

    for(int i = this->capacity / 2; i < this->capacity - 1; i ++) {
        newNext[i] = i + 1;
    }

    newNext[this->capacity-1] = -1;
    delete[] this->elems;
    delete[] this->next;
    this->elems = newElems;
    this->next = newNext;
    this->firstEmpty = this->capacity / 2;
}
// Complexity: Theta(n)


int IndexedList::size() const {
    return this->length;
}
// Complexity: Theta(1)


bool IndexedList::isEmpty() const {
    if(this->length == 0) {
        return true;
    }
	return false;
}
// Complexity: Theta(1)


TElem IndexedList::getElement(int pos) const {
    if(pos < 0 || pos >= this->length) {
        throw exception();
    }

    TElem current = this->head;
    int p = 0;

    while(p < pos) {
        current = this->next[current];
        p += 1;
    }
    return this->elems[current];
}
// Complexity: O(n)


TElem IndexedList::setElement(int pos, TElem e) {
    if(pos < 0 || pos >= this->length) {
        throw exception();
    }

    TElem current = this->head;
    TElem oldValue;
    int p = 0;

    while(p < pos) {
        current = this->next[current];
        p = p + 1;
    }

    oldValue = this->elems[current];
    this->elems[current] = e;
    return oldValue;
}
// Complexity: O(n)


void IndexedList::addToEnd(TElem e) {
    if(this->length == this->capacity) {
        this->resize();
    }

    if(this->length == 0) {
        // The case when the list is empty
        int newPosition = this->firstEmpty;
        this->elems[newPosition] = e;
        this->firstEmpty = this->next[this->firstEmpty];
        this->next[newPosition] = -1;

        this->head = newPosition;
        this->length += 1;
    }
    else {
        int newPosition = this->firstEmpty;
        this->elems[newPosition] = e;
        this->firstEmpty = this->next[this->firstEmpty];
        this->next[newPosition] = -1;

        TElem current = this->head;
        while (this->next[current] != -1) {
            current = this->next[current];
        }
        this->next[current] = newPosition;
        this->length += 1;
    }
}
// Complexity: O(n)


void IndexedList::addToPosition(int pos, TElem e) {
    if(pos < 0 || pos >= this->length) {
        throw exception();
    }

    if(this->length == this->capacity) {
        this->resize();
    }

    if(pos == 0) {
        // Add on the first position.
        int newPosition = this->firstEmpty;
        this->elems[newPosition] = e;
        this->firstEmpty = this->next[this->firstEmpty];

        this->next[newPosition] = this->head;
        this->head = newPosition;
        this->length += 1;
    }
    else {
        // Add arbitrarily in the list.
        int newPosition = this->firstEmpty;
        this->elems[newPosition] = e;
        this->firstEmpty = this->next[firstEmpty];

        TElem current = this->head;
        int p = 0;
        while(p < pos - 1) {
            current = this->next[current];
            p += 1;
        }
        this->next[newPosition] = this->next[current];
        this->next[current] = newPosition;
        this->length += 1;
    }
}
// Complexity: O(n)


TElem IndexedList::remove(int pos) {
    if(pos < 0 || pos >= this->length) {
        throw exception();
    }

    TElem current = this->head;
    TElem prev = -1;
    TElem removedElem;

    int p = 0;
    while(p < pos) {
        prev = current;
        current = this->next[current];
        p = p + 1;
    }

    removedElem = this->elems[current];

    if(current == this->head) {
        this->head = this->next[this->head];
    }
    else {
        this->next[prev] = this->next[current];
    }

    this->next[current] = this->firstEmpty;
    this->firstEmpty = current;
    this->length -= 1;
    return removedElem;
}
// Complexity: O(n)


int IndexedList::search(TElem e) const{
    TElem current = this->head;
    bool okay = false;
    int position = 0;

    while(current != -1 && !okay) {
        if(this->elems[current] == e) {
            okay = true;
        }
        else {
            position += 1;
        }
        current = this->next[current];
    }

    if(!okay) {
        return -1;
    }
    return position;
}
// Complexity: O(n)


ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}
// Complexity: Theta(1)

IndexedList::~IndexedList() {
	delete[] this->elems;
	delete[] this->next;
}
// Complexity: Theta(1)