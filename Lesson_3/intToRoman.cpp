#include<iostream>
#include<string>
#include<vector>

using namespace std;


string intToRoman(int num) {
	char Roman_numerals[9] = {'*', 'M', 'D', 'C', 'L', 'X', 'V', 'I', '*' };
	int Roman_numbers[9] = {5000, 1000, 500 ,100 ,50 ,10, 5, 1, 0 };
	int divider = 1000;
	string result;



	for (int i = 1; i < 8; ++i) {
		cout << num << endl;

		if (num / divider == 4) {
			if (((i % 2)) & (Roman_numbers[i - 1] - num <= Roman_numbers[i])) {
				result += Roman_numerals[i];
				result += Roman_numerals[i - 1];
				num = num - (Roman_numbers[i - 1] - Roman_numbers[i]);
			}
			else {
				result += Roman_numerals[i];
				result += Roman_numerals[i];
				result += Roman_numerals[i];
				num = num % divider;
			}
		}
		else if(num / divider == 3) {
			result += Roman_numerals[i];
			result += Roman_numerals[i];
			result += Roman_numerals[i];
			num = num % divider;
		}
		else if (num / divider == 2) {
			result += Roman_numerals[i];
			result += Roman_numerals[i];
			num = num % divider;
		}
		else if (num / divider == 1) {
			if ((!(i % 2)) & (Roman_numbers[i - 1] - num <= Roman_numbers[i + 1])) {
				result += Roman_numerals[i + 1];
				result += Roman_numerals[i - 1];
				num = num - (Roman_numbers[i - 1] - Roman_numbers[i + 1]);
			}
			else {
				result += Roman_numerals[i];
				num = num % divider;
			}
		}

		divider /= (i % 2) ? 2 : 5;
	}

	return result;
}

int main() {

	int number;

	//while (1) {
		cin >> number;

		cout << intToRoman(number) << endl;
		cout << endl;
	//}
}