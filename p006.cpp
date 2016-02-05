// Problem 6
// a^2 - b^2 = (a+b)(a-b)

#include <iostream>

long sumOfSquares(int);
long squareOfSum(int);

using namespace std;

int main() {
	cout << squareOfSum(100) - sumOfSquares(100) << endl;	
}


long sumOfSquares(int num) {
	long sum = 0;
	for (int i=1; i<=num; i++) {
		sum += i*i;
	}
	return sum;
}

long squareOfSum(int num) {
	long sum = 0;
	for (int i=1; i<=num; i++) {
		sum += i;
	}
	return sum*sum;

}
