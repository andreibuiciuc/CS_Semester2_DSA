#include <iostream>
#include "SortedSet.h"
#include "SortedSetIterator.h"


SortedSet::SortedSet(Relation relation) {
    this->relation = relation;
    this->head = nullptr;
    this->tail = nullptr;
}
// Theta(1)

bool SortedSet::add(TComp elem) {
    if(this->head == nullptr) {
        // This is the case when the Set is empty.
        Node* newNode = new Node;
        newNode->info = elem;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        this->head = newNode;
        this->tail = newNode;
        return true;
    }

    Node* currentNode = this->head;
    bool okay = true;
    bool done = false;

    while(currentNode != nullptr && !done) {
        if(currentNode->info == elem) {
            // The element already exist in the Set, so it cannot be added.
            okay = false;
            done = true;
        }
        else if(this->head == currentNode && this->relation(elem, currentNode->info)) {
            // The case when the element is added at the beginning of the dll.
            Node* newNode = new Node;
            newNode->info = elem;
            newNode->next = this->head;
            newNode->prev = nullptr;
            this->head->prev = newNode;
            this->head = newNode;
            done = true;
        }
        else if(this->tail == currentNode && this->relation(currentNode->info, elem)) {
            // The case when the element is added at the end of the dll.
            Node* newNode = new Node;
            newNode->info = elem;
            newNode->next = nullptr;
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
            done = true;
        }
        else if(this->relation(currentNode->info, elem) && this->relation(elem, currentNode->next->info)) {
            if(currentNode->next->info != elem) {
                Node *newNode = new Node;
                newNode->info = elem;
                newNode->next = currentNode->next;
                newNode->prev = currentNode;
                currentNode->next->prev = newNode;
                currentNode->next = newNode;
                done = true;
            }
        }

        currentNode = currentNode->next;
    }

    if(!okay){
        return false;
    }
    else
        return true;
}
// Best Case: Theta(1)
// Worst Case: Theta(n)
// Total Complexity: O(n)

bool SortedSet::remove(TComp elem) {
	Node* currentNode = this->head;
	bool okay = false;

	while(currentNode != nullptr && currentNode->info != elem) {
	    currentNode = currentNode->next;
	}

	if(currentNode != nullptr) {
	    if(currentNode == this->head) {
            if(currentNode == this->tail) {
                // This is the case when we remove the node which is both head and tail.
                this->head = nullptr;
                this->tail = nullptr;
                delete currentNode;
                okay = true;
            }
            else {
                // This is the case when we remove the fist node.
                this->head = this->head->next;
                this->head->prev = nullptr;
                delete currentNode;
                okay = true;
            }
	    }
	    else if(currentNode == this->tail) {
	        // This is the case when we remove the last node.
	        this->tail = this->tail->prev;
	        this->tail->next = nullptr;
	        delete currentNode;
	        okay = true;
	    }
	    else {
	        // This is the case when we remove a node somewhere in the dll.
	        currentNode->next->prev = currentNode->prev;
	        currentNode->prev->next = currentNode->next;
            delete currentNode;
	        okay = true;
	    }
	}
    return okay;
}
// Best Case: Theta(1)
// Worst Case: Theta(n)
// Total Complexity: O(n)

bool SortedSet::search(TComp elem) const {
	Node* currentNode = this->head;
	bool okay = false;

	while(currentNode != nullptr && !okay) {
	    if(currentNode->info == elem) {
	        okay = true;
	    }
	    currentNode = currentNode->next;
	}

    return okay;
}
// Best Case: Theta(1)
// Worst Case: Theta(n)
// Total Complexity: O(n)

int SortedSet::size() const {
	int count = 0;
	Node* currentNode = this->head;

	while(currentNode != nullptr) {
	    count = count + 1;
	    currentNode = currentNode->next;
	}

	return count;
}
// Theta(n)

bool SortedSet::isEmpty() const {
	if(this->head == nullptr) {
        return true;
	}
	return false;
}
// Theta(1)

SortedSetIterator SortedSet::iterator() {
	return SortedSetIterator(*this);
}
// Theta(1)

SortedSet::~SortedSet() {
	Node* currentNode = this->head;
	Node* nextNode;
	while(currentNode != nullptr) {
	   nextNode = currentNode->next;
	   delete currentNode;
	   currentNode = nextNode;
	}
}
// Theta(n)

