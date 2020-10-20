#include<iostream>
#include<vector>

using namespace std;

bool IsPrimeNumber(uint64_t number) {
	uint64_t number_tmp = number;
	for (uint64_t i = 2; i < number_tmp / 2 + 1; ++i) {
		if (!(number_tmp % i)) {
			return 0;
		}
	}
	return 1;

}

void PrintLargestPrimeFactor(uint64_t number, bool test) {
	uint64_t divider = 2;
	uint64_t number_tmp = number;

	vector< uint64_t> dividers;
	uint64_t result = 1;

	while (!IsPrimeNumber(number_tmp)) {
		if (!(number_tmp % divider)) {
			number_tmp = number_tmp / divider;
			dividers.push_back(divider);

		}
		++divider;
	}
	dividers.push_back(number_tmp);

	cout << number << " = ";

	for (int i = 0; i < dividers.size(); ++i) {
		if (i == dividers.size() - 1) {
			cout << dividers[i];
		}
		else {
			cout << dividers[i] << " * ";
		}
		result *= dividers[i];
	}

	if (test) {
		cout << endl << "result = " << result << "; " << "numer = " << number << endl;
		if (result == number) {
			cout << "***Test Passed***";
		}
	}

}

int main() {
	uint64_t a;

	cin >> a;
	PrintLargestPrimeFactor(a, true);
}