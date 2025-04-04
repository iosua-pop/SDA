#include "TestExtins.h"
#include "TestScurt.h"
#include "time.h"
#include <iostream>
using namespace std;



int main() {
	clock_t begin = clock();

	/* here, do your time-consuming job */
	testAll();
	testAllExtins();

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "That's all!" << endl;

	printf("Proccesed in : %f seconds\n", time_spent);

}
