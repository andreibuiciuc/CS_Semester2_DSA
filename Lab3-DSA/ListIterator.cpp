#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

using namespace  std;

ListIterator::ListIterator(const IndexedList& list) : list(list){
   this->currentElement = this->list.head;
}
// Complexity: Theta(1)


void ListIterator::first(){
    this->currentElement = this->list.head;
}
// Complexity: Theta(1)


void ListIterator::next(){
    if(this->currentElement == -1) {
        throw exception();
    }
    this->currentElement = this->list.next[this->currentElement];
}
// Complexity: Theta(1)


bool ListIterator::valid() const{
    if(this->currentElement == -1) {
        return false;
    }
	return true;
}
// Complexity: Theta(1)


TElem ListIterator::getCurrent() const{
   if(this->currentElement == -1) {
       throw exception();
   }
    return this->list.elems[this->currentElement];
}
// Complexity: Theta(1);

void ListIterator::previous() {
    if(this->currentElement == -1) {
        // The case when the iterator is not valid.
        throw exception();
    }

    if(this->currentElement == this->list.head) {
        // The case when the current element is the head, we make the iterator invalid.
        this->currentElement = -1;
    }
    else {
        int c = this->list.head;

        while(this->list.next[c] != this->currentElement) {
            c = this->list.next[c];
        }

        this->currentElement = c;
    }
}
// Complexity: O(n)