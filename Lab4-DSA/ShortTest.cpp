#include "ShortTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cassert>
#include <crtdbg.h>
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
	    it.next();
	}

	assert(it.valid() == false);
	it.first();
	assert(it.valid() == true);

	// Others
	SortedBag sb2(relation1);
	sb2.add(1);
	sb2.add(2);
	sb2.add(3);
	sb2.add(4); // 1 2 3 4
	assert(sb2.size() == 4);
	SortedBagIterator it2 = sb2.iterator();
	assert(it2.valid() == true);
	it2.jumpForward(2);
	assert(it2.getCurrent() == 3);

	it2.first();
	it2.jumpForward(1);
	assert(it2.getCurrent() == 2);

	it2.first();
	sb2.add(2);
	sb2.add(2); // 1 2 2 2 3 4
    assert(sb2.nrOccurrences(2) == 3);
    it2.next();
    assert(it2.getCurrent() == 2);
	it2.jumpForward(3);
    assert(it2.getCurrent() == 3);

    it2.first();
    while(it2.valid()) {
//        std::cout << it2.getCurrent() << ' ';
        it2.getCurrent();
        it2.next();
    }

    it2.first();
    it2.jumpForward(10);
    assert(it2.valid() == false);

}
