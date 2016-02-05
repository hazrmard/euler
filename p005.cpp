// Problem 5

#include <iostream>

using namespace std;

int main() {
	int flag = 1;
	long number = 2520;
	while (flag==1) {
		for (int i=1; i<=20; i++) {
			if (number % i != 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << number << endl;
			return 0;
		}
		else {
			flag = 1;
			number++;
		}
	}
}
