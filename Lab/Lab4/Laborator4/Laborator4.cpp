#include "TestExtins.h"
#include "TestScurt.h"


#include <iostream>
using namespace std;


int main() {
	testAll();
	cout << "Finalizeaza teste scurte cu succes" << endl;

	testAllExtins();
	cout << "Finalizeaza teste extinse cu succes" << endl;

	cout << "That's all!" << endl;
	return 0;
}

