class bitset {
public:

	bitset(int size) {
		this->size = ((size - 1) / reg_size) + 1;
		long long* table = new long long[size];
		this->table = table;
		FillArray(table, size);
	}

	~bitset() {
		delete[] table;
	}

	bool GetValue(char index) {
		return table[index / reg_size] & (one << (index % reg_size));;
	}

	void SetValue(char index) {
		table[index/ reg_size] |= (one << (index % reg_size));
	}

private:
	long long* table;
	int size;
	long long one = 1;
	int reg_size = sizeof(long long);

	void FillArray(long long* arr, int size) {
		for (int i = 0; i < size; ++i) {
			arr[i] = 0;
		}
	}

	void PrintArray(long long* arr, int size) {
		for (int i = 0; i < size; ++i) {
			cout << arr[i] << "'";
		}
	}
};
bool IsUniq(string s) {
	
	bitset table(700);

	for (int i = 0; i < s.size(); ++i) {
		if (table.GetValue(s[i])) {
			return false;
		}
		else {
			table.SetValue(s[i]);
		}
	}
	return true;
}
