// Problem 8

#include <iostream>
#include <string>

using namespace std;

long product(int, int, string);
int nextStartPosition(int, int, string);
long largestProduct(int, string);

int main() {
	string s = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	cout << largestProduct(13,s) << endl;
	return 0;	
}


long largestProduct(int n, string s) {
	int len = s.length();
	int index = nextStartPosition(0, n, s); // find position to start from
	cout << index << endl;
	long p = product(index, n, s);		// calculate initial product
	long p2=p;				// set up second product for comparison
	while (index+n < len) {			// loop till last set of n digits
		if (s[index+n]=='0') {		// if next digit is zero:
			index = nextStartPosition(index+1, n, s);		// move pointer to after that zero
			p2 = product(index, n, s); // calculate new product
			p = p2 > p ? p2 : p;	// make it largest product if applicable
			continue;
		}
		else {		// if next digit not 0, calculate new product
			p2 *= (int)(s[index+n]-'0');	// multiple product w/ next digit
			p2 /= (int)(s[index]-'0');	// divide product by leaving digit
			p = p2 > p ? p2 : p;		// see if new product is larger
			index ++;			// advance set of digits under consideration
		}
		
	}
	return p;
}

// calculate product of next len integers
long product(int start, int len, string s) {
	long product=1;
	for (int i=start; i<start+len; i++) {
		product *= (int)(s[i]-'0');
	}
	return product;
}

// find next stretch of non-zero numbers of length len
int nextStartPosition(int start, int len, string s) {
	int i = start;
	int j =start;
	while (j-i<len+1) {
		i = (s[j]=='0') ? j+1 : i;
		j++;	
	}
	return i;
}
