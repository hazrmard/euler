//Problem 2

#include <iostream>

using namespace std;

int main() {
	unsigned int lastFib = 0;
	unsigned temp = 0;
	unsigned int fib = 1;
	long evenSum = 0;
	while (fib < 4e6) {
		if (fib%2l==0) {
			evenSum = evenSum + (long) fib;
		}
		temp = fib;
		fib = fib + lastFib;
		lastFib = temp;
	}
	cout << "Sum is: " << evenSum << "\n";
}
