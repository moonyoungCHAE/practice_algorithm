#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	int inputA, inputB, totalMoney;
	while (T > 0) {
		T--;
		cin >> inputA >> inputB;

		totalMoney = 0;
		if (inputA == 0) {

		}
		else if (inputA == 1) {
			totalMoney += 5000000;
		}
		else if (inputA <= 3) { // 2, 3
			totalMoney += 3000000;
		}
		else if (inputA <= 6) {
			totalMoney += 2000000;
		}
		else if (inputA <= 10) {
			totalMoney += 500000;
		}
		else if (inputA <= 15) {
			totalMoney += 300000;
		}
		else if (inputA <= 21) {
			totalMoney += 100000;
		}

		if (inputB == 0) {
		}
		else if (inputB == 1) {
			totalMoney += 5120000;
		}
		else if (inputB <= 3) {
			totalMoney += 2560000;
		}
		else if (inputB <= 7) {
			totalMoney += 1280000;
		}
		else if (inputB <= 15) {
			totalMoney += 640000;
		}
		else if (inputB <= 31) {
			totalMoney += 320000;
		}

		cout << totalMoney << endl;
	}
}