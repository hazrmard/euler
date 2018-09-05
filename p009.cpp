// Problem 9
// 3 conditions:
// a + b + c == 1000
// a^2 + b^2 == c^2
// c > b > a

#include <iostream>
#include <cmath>

long solution(void);

using namespace std;

int main() {
	cout << solution() << endl;
	return 0;
}

long solution() {
	for (int b=2; b < 1000; b++) {
		for (int a=1; a<b; a++) {
			 if (a*a + b*b == pow(1000 - a - b, 2)) {
				return a * b * (1000-a-b);
			}
		}
	}
	return -1l;
}
