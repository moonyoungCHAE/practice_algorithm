#include<iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	// A > B�� ����
	if (B > A) {
		int tmp = A;
		A = B;
		B = tmp;
	}

	// �ִ�����
	for (int number = A; number >= 1; number--) {
		if (B % number == 0 && A % number == 0) {
			cout << number << endl;
			break;
		}
	}

	// �ּҰ����
	int number = A;
	while (!(number % A == 0 && number % B == 0)) {
		number++;
	}
	cout << number << endl;
}