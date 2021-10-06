#include "ShortTest.h"
#include <assert.h>
#include "Bag.h"
#include "BagIterator.h"


void testAll() { 
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0); 
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);

//	b.remove(1);
//	assert(b.getRange() == 14);
//	b.add(20);
//	assert(b.getRange() == 23);
//    b.add(-10);
//    assert(b.getRange() == 30);
//
//    Bag b2;
//    assert(b2.getRange() == -1);
//    b2.add(2);
//    b2.add(2);
//    assert(b2.getRange() == 0);
//
//    Bag b3;
//    b3.add(1);
//    assert(b3.getRange() == 0);

	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}
}
