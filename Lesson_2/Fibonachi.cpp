#include<iostream>

int main() {

	int a1 = 1;
	int a2 = 2;
	int count = 2;

	while ((a1 + a2) < 4000000) {
		count += ((a1 + a2) % 2) ? 0 : a1 + a2;
		a2 = a1 + a2;
		a1 = a2 - a1;
	}

	std::cout << count;
}