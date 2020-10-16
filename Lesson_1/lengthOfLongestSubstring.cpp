#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s) {

	if (s == "") {
		return 0;
	}

	int length = 1;
	int length_tmp = 1;
	int counter = 0;
	int* arr = new int[s.size() + 1];

	for (int i = 0; i < s.size(); i++) {
		length = 1;
		for (int j = i + 1; (j < s.size()) & (s[i] != s[j]); j++) {
			length++;
		}
		arr[i] = length;
	}

	length = 1;

	for (int i = 0; i < s.size(); i++) {
		length_tmp = 0;
		if (length < arr[i]) {
			counter = arr[i];
			for (int j = i + 1; counter > 0; j++) {
				if (arr[j] < counter) {
					counter = arr[j];
				}
				else {
					counter--;
				}
				length_tmp++;
			}
		}
		if (length_tmp > length) {
			length = length_tmp;
		}
	}

	delete[] arr;

	return length;

}

int main() {

	return 0;
}