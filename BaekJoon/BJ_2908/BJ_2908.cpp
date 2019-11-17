#include<iostream>
using namespace std;

int main() {
	int inputA, inputB;
	cin >> inputA >> inputB;

	int newA = 0,  newB = 0;
	while (inputA > 10) {
		newA += inputA % 10;
		newA *= 10;
		inputA /= 10;
	}
	if (inputA > 0) {
		newA += inputA;
	}

	while (inputB > 10) {
		newB += inputB % 10;
		newB *= 10;
		inputB /= 10;
	}
	if (inputB > 0) {
		newB += inputB;
	}

	if (newA > newB)
		cout << newA << endl;
	else
		cout << newB << endl;
}