#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator; 
class Bag {

private:
	TElem* elements;    // array of unique elements from the Bag
	int* positions;   // array of positions
	int nrElements;     // number of distinct elements in the Bag
	int nrPositions;    // number of positions / total number of elements in the Bag
	int capacityE;      // initial capacity for the array of elements
	int capacityP;      // initial capacity for the array of positions

    void resizeE();     // private method that resizes the array of elements
    void resizeP();     // private method that resizes the array of positions

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	// Constructor
	Bag();

	// Adds an element to the Bag
	void add(TElem e);

	// Removes one occurrence of an element from the Bag
	// Returns true if an element was removed, false otherwise (if the element was not in the Bag)
	bool remove(TElem e);

	// Checks if an element appears is the Bag
	bool search(TElem e) const;

	// Returns the number of occurrences for an element in the Bag
	int nrOccurrences(TElem e) const;

	// Returns the number of elements from the Bag
	int size() const;

	// Returns an iterator for this Bag
	BagIterator iterator() const;

	// Checks if the Bag is empty
	bool isEmpty() const;

    //returns the difference between the maximum and the minimum element (assume integer values)
    //if the Bag is empty the range is -1
    int getRange() const;

    // Destructor
	~Bag();
};