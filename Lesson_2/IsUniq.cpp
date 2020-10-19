class bitset {
public:
	using long64 = long long unsigned;
	bitset(int size) {
		this->size = ((size - 1) / reg_size) + 1;
		this->table = new long64[size];
		FillArray(table, size);
	}

	~bitset() {
		delete[] table;
	}

	bool GetValue(char index) {
		return table[index / reg_size] & (1ULL << (index % reg_size));;
	}

	void SetValue(char index) {
		table[index/ reg_size] |= (1ULL << (index % reg_size));
	}

private:
	long64* table;
	int size;
	int reg_size = sizeof(long64);

	void FillArray(long64* arr, int size) {
		for (int i = 0; i < size; ++i) {
			arr[i] = 0;
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
