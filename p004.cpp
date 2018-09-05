// Problem 4

#include <iostream>
#include <cmath>
#include <string>

int isPalindrome(long);

using namespace std;

int main() {
	long largest = 0;
	for (int i=100; i<1000; i++){
		for (int j=100; j<1000; j++) {
			long product = i*j;
			if (isPalindrome(product) and product > largest) {
				largest = product;
			}
		}
	}
	cout << largest << endl;
}


int isPalindrome(long number) {
	string snumber = to_string(number);
	int len = snumber.length();
	int flag = 1;
	for (int i=0; i<len/2; i++) {
		if (snumber[i] != snumber[len-i-1]) {
			flag = 0;
			break;
		}
	}
	return flag;
}
