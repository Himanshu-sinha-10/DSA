#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	int smallOutput = factorial(n - 1);
	int output = n * smallOutput;
	return output;
}

int main() {
	cout << factorial(4) << endl;
}
