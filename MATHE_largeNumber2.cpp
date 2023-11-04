//
// Created by Kalen Suen on 2023/10/27.
//
#include "iostream"
#include "vector"

using namespace std;


class BigInteger {
    int sign;

    // digits are stored reversely here
    vector<short int> digits;

private:
    // num should be less than or equal to 9
    void addAtDigit(int index, int num) {
        if (index == digits.size()) {
            digits.push_back(1);
            return;
        }
        if (digits[index] + num <= 9) {
            digits[index] += num;
            return;
        } else {
            digits[index] = (digits[index] + num) - 10;
            addAtDigit(index + 1, 1);
            return;
        }
    }

    void minusAtDigit(int index, int num) {
        if (index == digits.size()) {
            digits.push_back(1);
            return;
        }
        if (digits[index] - num >= 0) {
            digits[index] -= num;
            return;
        } else {
            digits[index] = (digits[index] - num) + 10;
            minusAtDigit(index + 1, 1);
            return;
        }
    }

public:
    BigInteger(string number) {
        digits.reserve(number.size());
        if (number[0] == '-') sign = -1;
        else sign = 1;

        //reverse(number.begin(), number.end());
        if (sign == -1) number.front() = '\0';

        for (int i = number.size() - 1; number[i] != '\0' && i >= 0; --i)
            digits.push_back(number[i] - '0');

    }

    int getDigit(int index) {
        return digits[index];
    }

    BigInteger operator+(BigInteger &b) {
        BigInteger a = *this;
        if (a.sign * b.sign == 1) {
            for (int i = 0; i < b.digits.size(); ++i)
                a.addAtDigit(i, b.getDigit(i));
            return a;
        }
        if (a.sign * b.sign == -1) {
            if (a.absIsBiggerThan(b)) {
                for (int i = 0; i < b.digits.size(); ++i)
                    a.minusAtDigit(i, b.getDigit(i));
                return a;
            } else {
                for (int i = 0; i < a.digits.size(); ++i)
                    b.minusAtDigit(i, a.getDigit(i));
                return b;
            }
        }
    }

    BigInteger operator-(BigInteger b) {
        BigInteger a = *this;
        b.sign = -b.sign;
        return (a + b);
    }

    BigInteger operator%(BigInteger &b) {
        BigInteger a = *this;
        while (true) {
            a = a - b;
            if (!a.absIsBiggerThan(b))
                return a;
        }
    }

    bool absIsBiggerThan(BigInteger &b) {
        if (digits.size() > b.digits.size()) {
            return true;
        } else if (digits.size() == b.digits.size()) {
            for (int i = digits.size() - 1; i >= 0; --i) {
                if (digits[i] > b.digits[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }

    string to_str() {
        string result;
        if (sign == -1) result.push_back('-');

        bool a = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 0 && a)
                continue;
            a = false;
            result.push_back(digits[i] + '0');
        }
        return result;
    }

};

int main() {
    std::ios::sync_with_stdio(false);

    string numa, numb;
    cin >> numa >> numb;

    BigInteger a(numa), b(numb);

    cout << (a % b).to_str() << endl;

}