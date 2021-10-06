#include "ShortTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cassert>
#include <iostream>

bool relation1(TComp e1, TComp e2) {
	return e1 <= e2;
}

void testAll() {
	SortedBag sb(relation1);
	sb.add(5);
	sb.add(6);
	sb.add(0);
	sb.add(5);
	sb.add(10);
	sb.add(8);

	assert(sb.size() == 6);
	assert(sb.nrOccurrences(5) == 2);


	assert(sb.remove(5) == true);
	assert(sb.size() == 5);

	assert(sb.search(6) == true);
	assert(sb.isEmpty() == false);

	SortedBagIterator it = sb.iterator();
	assert(it.valid() == true);

	while (it.valid()) {
	    it.getCurrent();
		it.next();
	}

	assert(it.valid() == false);
	it.first();
	assert(it.valid() == true);

    //...
	SortedBag sb2(relation1);
	sb2.addOccurrences(3, 1);
    sb2.add(2);
    sb2.addOccurrences(1,3);
    sb2.add(5);
    sb2.addOccurrences(4,4);
    sb2.add(5);
    sb2.add(0);

    assert(sb2.size() == 12);
    assert(sb2.nrOccurrences(1) == 3);
    assert(sb2.nrOccurrences(2) == 1);
    assert(sb2.nrOccurrences(3) == 1);
    assert(sb2.nrOccurrences(4) == 4);
    assert(sb2.nrOccurrences(5) == 2);

	SortedBagIterator it2 = sb2.iterator();
    while (it2.valid()) {
        std::cout << it2.getCurrent() << " ";
        it2.next();
    }
    std::cout << '\n';

}

