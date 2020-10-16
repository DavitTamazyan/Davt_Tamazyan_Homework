
bool IsPowof2(int number) {
	return !(!number | number & (number - 1));
}

int IsPowof2_minus1(int number) {
	return !(number & (number + 1));
}