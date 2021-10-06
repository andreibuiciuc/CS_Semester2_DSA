#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->copy = new SLL [this->bag.capacity];

    for(int i = 0; i < this->bag.capacity; i ++) {
        this->copy[i].head = this->bag.T[i].head;
    }

    // Find the first valid value in the hash table
    int position = 0;
    while(position < this->bag.capacity && this->copy[position].head == nullptr) {
        position += 1;
    }

    if(position == this->bag.capacity) {
        // The case when there is no element in the hash table.
        this->minPos = -1;
        this->currentFreq = -1;
    }
    else {
        // Find the compare value (minimum or maximum)
        TComp compare = this->copy[position].head->info;
        this->minPos = position;
        this->currentFreq = this->copy[position].head->frequency;
        position += 1;

        for (int i = position; i < this->bag.capacity; i++) {
            if (this->copy[i].head != nullptr) {
                if (this->bag.relation(this->copy[i].head->info, compare)) {
                    compare = this->copy[i].head->info;
                    this->minPos = i;
                    this->currentFreq = this->copy[i].head->frequency;
                }
            }
        }
    }
}
// Time Complexity: Theta(m)

TComp SortedBagIterator::getCurrent() {
    if(this->minPos == -1) {
        throw exception();
    }
    return this->copy[this->minPos].head->info;

}
// Time Complexity: Theta(1)

bool SortedBagIterator::valid() const {
    if(this->minPos == -1) {
        return false;
    }
    return true;
}
// Time Complexity: Theta(1)

void SortedBagIterator::next() {
    if(this->minPos == -1) {
        throw exception();
    }
    if(this->currentFreq > 1) {
        this->currentFreq -= 1;
    }
    else if(this->currentFreq == 1) {
        // We should move to find the next minimum.
        this->copy[this->minPos].head = this->copy[this->minPos].head->next;

        // Find the first valid value in the hash table.
        int position = 0;
        while(position < this->bag.capacity && this->copy[position].head == nullptr) {
            position += 1;
        }

        if(position == this->bag.capacity) {
            // The case when there is no element in the hash table. The iterator becomes invalid.
            this->minPos = -1;
            this->currentFreq = -1;
        }
        else {
            // Find the compare value (minimum or maximum)
            TComp compare = this->copy[position].head->info;
            this->minPos = position;
            this->currentFreq = this->copy[position].head->frequency;
            position += 1;

            for (int i = position; i < this->bag.capacity; i++) {
                if (this->copy[i].head != nullptr) {
                    if (this->bag.relation(this->copy[i].head->info, compare)) {
                        compare = this->copy[i].head->info;
                        this->minPos = i;
                        this->currentFreq = this->copy[i].head->frequency;
                    }
                }
            }
        }
    }

}
// Time Complexity: Theta(m)

void SortedBagIterator::jumpForward(int k) {
    if(this->minPos == -1) {
        // Iterator is not valid
        throw exception();
    }
    if(k <= 0) {
        throw exception();
    }

    if(this->bag.length < k) {
        // In this case, make the iterator invalid
        this->minPos = -1;
        this->currentFreq = -1;
    }
    else {
        // The case when we can jump forward k steps.
        while(k) {
            if(this->currentFreq > 1) {
                this->currentFreq -= 1;
            }
            else if(this->currentFreq == 1) {
                // We should move to find the next minimum.
                this->copy[this->minPos].head = this->copy[this->minPos].head->next;

                // Find the first valid value in the hash table.
                int position = 0;
                while(position < this->bag.capacity && this->copy[position].head == nullptr) {
                    position += 1;
                }

                // Find the compare value (minimum or maximum)
                TComp compare = this->copy[position].head->info;
                this->minPos = position;
                this->currentFreq = this->copy[position].head->frequency;
                position += 1;

                for (int i = position; i < this->bag.capacity; i++) {
                    if (this->copy[i].head != nullptr) {
                        if (this->bag.relation(this->copy[i].head->info, compare)) {
                            compare = this->copy[i].head->info;
                            this->minPos = i;
                            this->currentFreq = this->copy[i].head->frequency;
                        }
                    }
                }
            }
            k = k - 1;
        }
    }
}
// Time Complexity: Theta(k * m)

void SortedBagIterator::first() {
    delete[] this->copy;

    this->copy = new SLL [this->bag.capacity];
    for(int i = 0; i < this->bag.capacity; i ++) {
        this->copy[i].head = this->bag.T[i].head;
    }

    // Find the first valid value in the hash table
    int position = 0;

    while(position < this->bag.capacity && this->copy[position].head == nullptr) {
        position += 1;
    }

    if(position == this->bag.capacity) {
        // The case when there is no element in the hash table.
        this->minPos = -1;
        this->currentFreq = -1;
    }
    else {
        // Find the compare value (minimum or maximum)
        TComp compare = this->copy[position].head->info;
        this->minPos = position;
        this->currentFreq = this->copy[position].head->frequency;
        position += 1;

        for (int i = position; i < this->bag.capacity; i++) {
            if (this->copy[i].head != nullptr) {
                if (this->bag.relation(this->copy[i].head->info, compare)) {
                    compare = this->copy[i].head->info;
                    this->minPos = i;
                    this->currentFreq = this->copy[i].head->frequency;
                }
            }
        }
    }
}
// Time Complexity: Theta(m)

SortedBagIterator::~SortedBagIterator() {
    delete[] this->copy;
}
// Time Complexity: Theta(1)
