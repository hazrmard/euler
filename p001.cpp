// Problem 1

#include <iostream>

using namespace std;

int main() {
	cout << "Sum of multiples is: ";
	unsigned int sum=0;
	int isMultiple=0;
	for (int i=1; i<1000; i++) {
		isMultiple = (i%3==0 || i%5==0)? 1 : 0;
		if (isMultiple) {
			sum = sum + i;
		}
	}
	cout << sum << "\n";
	return 0;
}
