class bitset {
public:

	bitset(int init_value) {
		reg0 = init_value;
		reg1 = init_value;
		reg2 = init_value;
		reg3 = init_value;
	}

	bool check(char index) {
		if (index < 64) {
			return reg0 & (one << index);
		}
		else if (index < 128) {
			return reg1 & (one << (index - 64));
		}
		else if (index < 192) {
			return reg2 & (one << (index - 128));
		}
		else if (index < 256) {
			return reg3 & (one << (index - 192));
		}
	}

	void AddElement(char index) {
		if (index < 64) {
			reg0 |= (one << index);
		}
		else if (index < 128) {
			reg1 |= (one << (index - 64));
		}
		else if (index < 192) {
			reg2 |= (one << (index - 128));
		}
		else if (index < 256) {
			reg3 |= (one << (index - 192));
		}
	}

private:
	long long unsigned reg0;
	long long unsigned reg1;
	long long unsigned reg2;
	long long unsigned reg3;
	long long one = 1;
};

bool IsUniq(string s) {
	
	bitset table = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (table.check(s[i])) {
			return false;
		}
		else {
			table.AddElement(s[i]);
		}
	}
	return true;
}