#include<iostream>

int reverse(int x) {
    int result_int = 0;
    long long result_long = 0;
    int x_tmp = x;
    while (x_tmp) {
        result_long *= 10;
        result_long += x_tmp % 10;
        x_tmp /= 10;
    }
    result_int = result_long;
    if (result_long - result_int) {
        return 0;
    }
    else {
        return result_int;
    }
}



void Longest_palindrome() {
    int a = 999;
    int b = 999;
    bool end = false;
    bool steep = false;

    while (!end) {
        if (a * b == reverse(a * b)) {
            std::cout << a << std::endl;
            std::cout << b << std::endl;
            end = true;
        }
        else {
            if (a == 100) {
                --b;
                a = 999;
            }
            else {
                --a;
            }
            steep = !steep;
        }
    }
}

void Smallest_Multiple(int n) {
    int result = 1;
    int multiple = 2;
    std::vector<int> vec;
    for (int i = 2; i < n + 1; ++i) {
        multiple = i;
        for (int j = 0; j < vec.size(); j++) {
            if (!(multiple % vec[j])) {
                multiple /= vec[j];
            }
        }
        vec.push_back(multiple);
        result *= multiple;
    }
    std::cout << result;
}

void Smallest_Multiple() {
    int arr[20]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    bool end = false;
    int start_value = 21;
    int count = 0;

    while (!end) {
        for (int i = 0; i < 20; ++i) {
            if (start_value % arr[i]) {
                count = 0;
                continue;
            }
            else {
                ++count;
            }
        }
        if (count == 20) {
            end = true;
        }
        else {
            count = 0;
            ++start_value;
        }
    }
    std::cout << start_value << std::endl;

}

int main() {
}
