#include <iostream>

using namespace std;

int main() {
	double sum = 0;
	long long n = 0;
	while (sum <= 12) {
		sum += 1.0/(++ n);
	}	
	cout << n << endl;
}