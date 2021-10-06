#include <cassert>
#include <exception>
#include <iostream>

#include "ShortTest.h"
#include "IndexedList.h"
#include "ListIterator.h"


void testAll() {
    IndexedList list = IndexedList();
    assert(list.isEmpty());
    list.addToEnd(1);
    assert(list.size() == 1);
    list.addToPosition(0,2);
    assert(list.size() == 2);

    ListIterator it = list.iterator();
    assert(it.valid());
    it.next();
    assert(it.getCurrent() == 1);
    it.first();
    assert(it.getCurrent() == 2);

    assert(list.search(1) == 1);
    assert(list.setElement(1,3) == 1);
    assert(list.getElement(1) == 3);
    assert(list.remove(0) == 2);
    assert(list.size() == 1);

    it.first();
    assert(it.getCurrent() == 3);

    IndexedList list2 = IndexedList();
    assert(list2.isEmpty());
    list2.addToEnd(1);
    list2.addToEnd(2);
    list2.addToEnd(3);
    list2.addToPosition(0, 0);
    // 0 1 2 3
    assert(list2.size() == 4);

    ListIterator it2 = list2.iterator();
    assert(it2.valid());
    it2.next();
    it2.next();
    it2.next(); // at 3
    assert(it2.getCurrent() == 3);

    it2.previous();
    assert(it2.getCurrent() == 2);
    it2.previous();
    assert(it2.getCurrent() == 1);
    it2.previous();
    assert(it2.getCurrent() == 0);
    it2.previous();
    assert(it2.valid() == false);

    it2.first();
    it2.next();
    assert(it2.getCurrent() == 1);
    it2.previous();
    assert(it2.getCurrent() == 0);
    it2.next();
    assert(it2.getCurrent() == 1);

}
