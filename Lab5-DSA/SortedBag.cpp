#include <iostream>
#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    this->relation = r;

	this->capacity = 1000;
	this->length = 0;

    this->info = new TElem [this->capacity];
    this->left = new int [this->capacity];
    this->right = new int [this->capacity];

    for(int i = 0; i < this->capacity - 1; i ++) {
        this->left[i] = i + 1;
        this->right[i] = i + 1;
    }
    this->left[this->capacity - 1] = -1;
    this->right[this->capacity - 1] = -1;

    this->root = -1;
    this->firstEmpty = 0;
}
// Time Complexity: Theta(m)

void SortedBag::resize() {
    this->capacity = this->capacity * 2;
    auto* newInfo = new TElem [this->capacity];
    int* newLeft = new int [this->capacity];
    int* newRight = new int [this->capacity];

    for(int i = 0; i < this->capacity / 2; i ++) {
        newInfo[i] = this->info[i];
        newLeft[i] = this->left[i];
        newRight[i] = this->right[i];
    }

    for(int i = this->capacity / 2; i < this->capacity - 1; i ++) {
        newLeft[i] = i + 1;
        newRight[i] = i + 1;
    }

    newLeft[this->capacity - 1] = -1;
    newRight[this->capacity - 1] = -1;
    delete[] this->left;
    delete[] this->right;
    delete[] this->info;

    this->info = newInfo;
    this->left = newLeft;
    this->right = newRight;
    this->firstEmpty = this->capacity / 2;
}
// Time Complexity: Theta(m)

void SortedBag::add(TComp e) {
	if(this->length == this->capacity) {
	    this->resize();
	}

    if(this->length == 0) {
        // The case when there is no element in the tree -> make it also the root.

        int newPosition = this->firstEmpty;
        this->info[newPosition] = e;
        this->firstEmpty = this->left[this->firstEmpty];

        this->right[newPosition] = -1;
        this->left[newPosition] = -1;
        this->root = newPosition;

    }
    else {
        // The case when there are elements in the tree.
        // in the left side -> elements which respect the relation, in the right side otherwise

        int newPosition = this->firstEmpty;
        this->info[newPosition] = e;
        this->firstEmpty = this->left[this->firstEmpty];
        this->left[newPosition] = -1;
        this->right[newPosition] = -1;

        int currentIndex = this->root;
        int prevIndex;

        while(currentIndex != -1) {
            if(this->relation(e, this->info[currentIndex])) {
                // The case when we follow the left side branch.
                prevIndex = currentIndex;
                currentIndex = this->left[currentIndex];
            }
            else {
                // The case when we follow the right side branch.
                prevIndex = currentIndex;
                currentIndex = this->right[currentIndex];
            }
        }

        if(this->relation(e, this->info[prevIndex])) {
            // Element is added in the left side.
            this->left[prevIndex] = newPosition;
        }
        else {
            // Element is added in the right side.
            this->right[prevIndex] = newPosition;
        }

    }
    this->length += 1;
}
// Time Complexity: O(height)


bool SortedBag::remove(TComp e) {
	int nrSuccessors = 0;

	int prevIndex = -1;
    int currentIndex = -1;
    int auxPrevIndex = -1;
    int auxCurrentIndex = this->root;

    while(auxCurrentIndex != -1) {
        if(this->info[auxCurrentIndex] == e) {
            prevIndex = auxPrevIndex;
            currentIndex = auxCurrentIndex;
        }
        if(this->relation(e, this->info[auxCurrentIndex])) {
            auxPrevIndex = auxCurrentIndex;
            auxCurrentIndex = this->left[auxCurrentIndex];
        }
        else {
            auxPrevIndex = auxCurrentIndex;
            auxCurrentIndex = this->right[auxCurrentIndex];
        }
    }

    if(currentIndex == -1) {
        return false;
    }
    if(this->left[currentIndex] != -1) {
        nrSuccessors += 1;
    }
    if(this->right[currentIndex] != -1) {
        nrSuccessors += 1;
    }


    if(nrSuccessors == 0) {
        // The node to be removed has no descendants.
        if(currentIndex == this->root) {
            // The case when the node is the root, i.e. is the only node in the tree.
            this->root = -1;
        }
        else {
            if(this->left[prevIndex] == currentIndex) {
                // The case when the node is on the left side.
                this->left[prevIndex] = -1;
            }
            else {
                // The case when the node is on the right side.
                this->right[prevIndex] = -1;
            }
        }

        this->left[currentIndex] = this->firstEmpty;
        this->right[currentIndex] = this->firstEmpty;
        this->firstEmpty = currentIndex;
        this->length -= 1;
        return true;
    }
    else if(nrSuccessors == 1) {
        // The node to be removed has only one descendant.
        if(currentIndex == this->root) {
            if(this->left[currentIndex] != -1) {
                this->root = this->left[currentIndex];
            }
            else {
                this->root = this->right[currentIndex];
            }
        }
        else {
            if(this->left[prevIndex] == currentIndex) {
                if (this->left[currentIndex] != -1) {
                    this->left[prevIndex] = this->left[currentIndex];
                } else if (this->right[currentIndex] != -1) {
                    this->left[prevIndex] = this->right[currentIndex];
                }
            } else if(this->right[prevIndex] == currentIndex) {
                if (this->left[currentIndex] != -1) {
                    this->right[prevIndex] = this->left[currentIndex];
                } else if (this->right[currentIndex] != -1) {
                    this->right[prevIndex] = this->right[currentIndex];
                }
            }
        }

        this->left[currentIndex] = this->firstEmpty;
        this->right[currentIndex] = this->firstEmpty;
        this->firstEmpty = currentIndex;
        this->length -= 1;
        return true;
    }
    else {
        // The node to be removed has 2 descendants.

        // Find the predecessor
        int positionPredecessor = currentIndex;
        positionPredecessor = this->left[positionPredecessor];
        while (this->right[positionPredecessor] != -1) {
            positionPredecessor = this->right[positionPredecessor];
        }

        TComp predecessor = this->info[positionPredecessor];
        this->remove(predecessor);
        this->info[currentIndex] = predecessor;
        return true;
    }

}
// Time Complexity: O(height)

bool SortedBag::search(TComp elem) const {
	int currentIndex = this->root;
	bool found = false;

	while(currentIndex != -1 && !found) {
	    if(this->info[currentIndex] == elem) {
	        found = true;
	    }
	    if(this->relation(elem, this->info[currentIndex])) {
	        currentIndex = this->left[currentIndex];
	    }
	    else {
	        currentIndex = this->right[currentIndex];
	    }
	}

    return found;
}
// Time Complexity: O(height)

int SortedBag::nrOccurrences(TComp elem) const {
	int currentIndex = this->root;
	int count = 0;
	while(currentIndex != -1) {
	    if(this->info[currentIndex] == elem) {
	        count += 1;
	    }

	    if(this->relation(elem, this->info[currentIndex])) {
	        currentIndex = this->left[currentIndex];
	    }
	    else {
	        currentIndex = this->right[currentIndex];
	    }
	}

    return count;
}
// Time Complexity: Theta(height)


int SortedBag::size() const {
    return this->length;
}
// Theta(1)

bool SortedBag::isEmpty() const {
	if(this->length == 0) {
        return true;
	}
	return false;
}
// Theta(1)

SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}
// Theta(1)

SortedBag::~SortedBag() {
	delete[] this->info;
	delete[] this->left;
	delete[] this->right;
}
// Theta(1)

void SortedBag::addOccurrences(int nr, TComp elem) {
    if(nr < 0) {
        throw std::exception();
    }

    if(this->length + nr >= this->capacity) {
        this->resize();
    }

    int prevIndex;
    int currentIndex = this->root;

    while(currentIndex != -1) {
        if(this->relation(elem, this->info[currentIndex])) {
            prevIndex = currentIndex;
            currentIndex = this->left[currentIndex];
        }
        else {
            prevIndex = currentIndex;
            currentIndex = this->right[currentIndex];
        }
    }

    while(nr) {
        int newPosition = this->firstEmpty;
        this->info[newPosition] = elem;
        this->firstEmpty = this->left[this->firstEmpty];
        this->left[newPosition] = -1;
        this->right[newPosition] = -1;

        if(this->root == -1) {
            this->root = newPosition;
            prevIndex = newPosition;
        }
        else {
            if(this->relation(elem, this->info[prevIndex])) {
                // Element is added in the left side.
                this->left[prevIndex] = newPosition;
                prevIndex = newPosition;
            }
            else {
                // Element is added in the right side.
                this->right[prevIndex] = newPosition;
                prevIndex = newPosition;
            }
        }
        this->length += 1;
        nr = nr - 1;
    }
}
// Time Complexity: O(height + nr)