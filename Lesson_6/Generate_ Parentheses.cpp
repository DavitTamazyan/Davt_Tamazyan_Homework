//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.
//Memory Usage: 12 MB, less than 5.16% of C++ online submissions for Generate Parentheses.

class Solution {
public:
void createParenthesis(std::string& str, int &index, int count0, int count1, int n, std::vector <std::string > &result) {
	if (index == 2 * n - 1) {
		str[index] = ')';
		result.push_back(str);
		str[index] = ' ';
		--index;
		return;
	}

	if (count0 < n) {
		str[index] = '(';
		createParenthesis(str, ++index, ++count0, count1, n, result);
		--count0;
	}

	if ((count1 < n) & (count0 > count1)) {
		str[index] = ')';
		createParenthesis(str, ++index, count0, ++count1, n, result);
		--count1;
	}

	str[index] = ' ';
	--index;
	return;
}

std::vector <std::string > generateParenthesis(int n) {
	std::string str;
	std::vector <std::string > result;
	int i = 0;
	int index = 0;
	int count0 = 0;
	int count1 = 0;

	for (int i = 0; i < 2 * n; ++i) {
		str = str + ' ';
	}

	createParenthesis(str, index, 0, 0, n, result);

	return result;
}
};
