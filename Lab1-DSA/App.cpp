#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {

	testAll();
	cout << "Short tests over" << endl;
//	testAllExtended();
	cout << "All test over" << endl;
    cout << "That's all" << endl;

    _CrtDumpMemoryLeaks();
    return 0;
}