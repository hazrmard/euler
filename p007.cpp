// Problem 7

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int isPrime(long long);

vector<long long> primes = {2};


int main() {
	int i=1;
	long long num = 3;
	while (i<10001) {
		if (isPrime(num)) {
			i++;
		}
		num++;
	}
	cout << primes.back() << endl;
}


int isPrime(long long num) {
	int flag=1;
	for (vector<long long>::iterator i=primes.begin(); i!=primes.end(); i++) {
		if (num % *i == 0) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		primes.push_back(num);
		return 1;
	}
	return 0;
}
