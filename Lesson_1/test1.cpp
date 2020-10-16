int test1() {
	int multipleof3;
	int multipleof5;
	int multipleof15;

	multipleof3 = ((3 + 999) / 2) * 999 / 3;
	multipleof5 = ((5 + 1000) / 2) * 1000 / 5;
	multipleof15 = ((15 + 999) / 2) * 990 / 15;

	return multipleof3 + multipleof5 - multipleof15;

}