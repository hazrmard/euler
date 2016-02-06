// Problem 10

#include <iostream>
#include <vector>

using namespace std;

int isPrime(long, vector<long>&);

int main() {
	long long sum=2;
	vector<long> primes = {2};
	for (long i=3; i<2e6; i+=2) {
		sum += isPrime(i, primes) ? i : 0;
	}
	cout << sum << endl;
	return 0;
}


int isPrime(long i, vector<long>& p) {
	for (vector<long>::iterator it=p.begin(); it!=p.end(); it++) {
		if (i % *it == 0) {
			return 0;
		}
	}
	p.push_back(i);
	return 1;
}
