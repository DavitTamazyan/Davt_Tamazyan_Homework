class bitset {
public:

	bitset(int size) {
		int* table = new int[size];
		///
		this->table = table;
		this->size = size;
		FillArray(table, size);
	}

	~bitset() {
		delete[] table;
	}

	bool GetValue(char index) {
		return table[index];
	}

	void SetValue(char index) {
		table[index] = 1;
	}

private:
	int* table;
	int size;

	void FillArray(int* arr, int size) {
		for (int i = 0; i < size; ++i) {
			arr[i] = 0;
		}
	}

	void PrintArray(int* arr, int size) {
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
