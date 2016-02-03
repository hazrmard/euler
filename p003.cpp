//Problem 3

#include <iostream> // cout
#include <cstdlib> // atoll
#include <cmath> //sqrt
#include <list> //list

using namespace std;

int main(int argc, char *argv[]) {
	unsigned long long number = atoll(argv[1]);
	unsigned long long max_prime = 1;
	list<long long> primes;
	int flag = 1;		// 1: prime, 0: not prime. Assume prime unless proven otherwise.
	unsigned long long square_root = sqrt(number);	// largest prime factor can only be as large as sqrt
	
	//find the nexts prime by dividing by discovered primes
	for (long long i=2; i<=square_root; i+=1) {
		for (list<long long>::iterator it = primes.begin(); it != primes.end(); ++it) {
			if (i % *it == 0) {
				flag = 0;	// if divisible, i is not prime -> next i
				break;
			}
		}
	// if number is prime, add to list of primes, check if prime factor
		if (flag) {
			primes.push_back(i);
			if (number % i ==0) {
				max_prime = i;
			}
		}
		flag = 1;
	}
	cout << max_prime << endl;
}
