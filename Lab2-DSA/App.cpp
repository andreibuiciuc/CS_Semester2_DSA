#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;

int main() {
	testAll();
	testAllExtended();

	cout << "Test end" << endl;
	system("pause");

	_CrtDumpMemoryLeaks();
}