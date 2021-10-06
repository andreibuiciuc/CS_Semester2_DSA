#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    this->relation = r;
    this->capacity = 1000;
    this->length = 0;
    this->T = new SLL [this->capacity];
    for(int i = 0; i < this->capacity; i ++) {
        this->T[i].head = nullptr;
    }
}
// Time Complexity: Theta(m)

int SortedBag::hashFunction(TComp element) const {
    if(element < 0) {
        element = 0 - element;
    }
    return element % this->capacity;
}
// Time Complexity: Theta(1)

void SortedBag::resize() {
    this->capacity = this->capacity * 2;
    SLL* newTable = new SLL [this->capacity];

    for(int i = 0; i < this->capacity; i ++) {
        newTable[i].head = nullptr;
    }

    for(int i = 0; i < this->capacity / 2; i ++) {
        Node* currentNode = this->T[i].head;

        while(currentNode != nullptr) {
            int position = this->hashFunction(currentNode->info);

            if(newTable[position].head == nullptr) {
                // The case when the position in the new hash table is unoccupied.
                Node* newNode = new Node;
                newNode->info = currentNode->info;
                newNode->frequency = currentNode->frequency;
                newNode->next = nullptr;
                newTable[position].head = newNode;
            }
            else {
                // The case when the position is already occupied in the table.
                Node *c = newTable[position].head;
                bool done = false;

                if(this->relation(currentNode->info, newTable[position].head->info)) {
                    Node *newNode = new Node;
                    newNode->info = currentNode->info;
                    newNode->frequency = currentNode->frequency;
                    newNode->next = newTable[position].head;
                    newTable[position].head = newNode;
                }
                else {
                    while (c != nullptr && !done) {
                        if(c->next == nullptr && this->relation(c->info, currentNode->info)) {
                            Node* newNode = new Node;
                            newNode->info = currentNode->info;
                            newNode->frequency = currentNode->frequency;
                            newNode->next = nullptr;
                            c->next = newNode;
                            done = true;
                        }
                        else if(this->relation(c->info, currentNode->info) && this->relation(currentNode->info, c->next->info)) {
                            Node* newNode = new Node;
                            newNode->info = currentNode->info;
                            newNode->frequency = currentNode->frequency;
                            newNode->next = c->next;
                            c->next = newNode;
                            done = true;
                        }
                        c = c->next;
                    }
                }
            }

            currentNode = currentNode->next;
        }
    }

    for(int i = 0; i < this->capacity / 2; i ++) {
        Node* currentNode = this->T[i].head;
        Node* nextNode;
        while(currentNode != nullptr) {
            nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }

    delete[] this->T;
    this->T = newTable;
}
// Time Complexity: O(n^2)

void SortedBag::add(TComp e) {
    if((double)(this->length / this->capacity) > loadFactor) {
        this->resize();
    }

    int position = this->hashFunction(e);

    if(this->T[position].head == nullptr) {
        // This is the case when there is no element in the SLL from this position.
        Node* newNode = new Node;
        newNode->info = e;
        newNode->frequency = 1;
        newNode->next = nullptr;

        this->T[position].head = newNode;
        this->length += 1;
        return;
    }
    if(this->T[position].head->info == e) {
        // This is the case when the element is already the head of the SLL from this position.
        this->T[position].head->frequency += 1;
        this->length += 1;
        return;
    }
    if(this->relation(e, this->T[position].head->info)) {
        // This is the case when the element can be added as the head of the SLL from this position.
        Node *newNode = new Node;
        newNode->info = e;
        newNode->frequency = 1;
        newNode->next = this->T[position].head;

        this->T[position].head = newNode;
        this->length += 1;
        return;
    }

    Node* currentNode = this->T[position].head;
    bool done = false;

    while(currentNode != nullptr && !done) {
        if(currentNode->info == e) {
            // This is the case when the element already exists.
            currentNode->frequency += 1;
            this->length += 1;
            done = true;
        }
        else if(currentNode->next == nullptr && this->relation(currentNode->info, e)) {
            // This is the case when the element can be added at the end of the SLL from this position.
            Node *newNode = new Node;
            newNode->info = e;
            newNode->frequency = 1;
            newNode->next = nullptr;
            currentNode->next = newNode;
            this->length += 1;
            done = true;
        }
        else if(this->relation(currentNode->info, e) && this->relation(e, currentNode->next->info)) {
            if(currentNode->next->info != e) {
                // This is the case when the element can be added in between tho nodes of the SLL.
                Node *newNode = new Node;
                newNode->info = e;
                newNode->frequency = 1;
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                this->length += 1;
                done = true;
            }
        }

        currentNode = currentNode->next;
    }
}
// Time Complexity: O(n)

bool SortedBag::remove(TComp e) {
    int position = this->hashFunction(e);

    Node* currentNode = this->T[position].head;
    Node* prevNode = nullptr;
    bool okay = false;

    while(currentNode != nullptr && currentNode->info != e) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode != nullptr && prevNode == nullptr) {
        if(currentNode->frequency > 1) {
            currentNode->frequency -= 1;
            this->length -= 1;
            okay = true;
        }
        else {
            this->T[position].head = this->T[position].head->next;
            delete currentNode;
            okay = true;
            this->length -= 1;
        }
    }
    else if(currentNode != nullptr) {
        if(currentNode->frequency > 1) {
            currentNode->frequency -= 1;
            this->length -= 1;
            okay = true;
        }
        else {
            prevNode->next = currentNode->next;
            delete currentNode;
            okay = true;
            this->length -= 1;
        }
    }

    return okay;
}
// Time Complexity: O(n)

bool SortedBag::search(TComp elem) const {
    int position = this->hashFunction(elem);

    Node* currentNode = this->T[position].head;
    bool okay = false;

    while(currentNode != nullptr && !okay) {
        if(currentNode->info == elem) {
            okay = true;
        }
        currentNode = currentNode->next;
    }
    return okay;
}
// Time Complexity: O(n)

int SortedBag::nrOccurrences(TComp elem) const {
    bool okay = false;
    int count = 0;
    int position = this->hashFunction(elem);
    Node* currentNode = this->T[position].head;

    while(currentNode != nullptr && !okay) {
        if(currentNode->info == elem) {
            count = currentNode->frequency;
            okay = true;
        }
        currentNode = currentNode->next;
    }
    return count;
}
// Time Complexity: O(n)

int SortedBag::size() const {
    return this->length;
}
// Time Complexity: Theta(1)

bool SortedBag::isEmpty() const {
    if(this->length == 0) {
        return true;
    }
    return false;
}
// Time Complexity: Theta(1)

SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}
// Time Complexity: Theta(1)

SortedBag::~SortedBag() {
	for(int i = 0; i < this->capacity; i ++) {
	    Node* currentNode = this->T[i].head;
	    Node* nextNode;
	    while(currentNode != nullptr) {
	        nextNode = currentNode->next;
	        delete currentNode;
	        currentNode = nextNode;
	    }
	}
    delete[] this->T;
}
// Time Complexity: Theta(n)
