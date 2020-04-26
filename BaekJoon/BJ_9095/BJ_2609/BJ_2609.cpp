#include<iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	// A > B로 설정
	if (B > A) {
		int tmp = A;
		A = B;
		B = tmp;
	}

	// 최대공약수
	for (int number = A; number >= 1; number--) {
		if (B % number == 0 && A % number == 0) {
			cout << number << endl;
			break;
		}
	}

	// 최소공배수
	int number = A;
	while (!(number % A == 0 && number % B == 0)) {
		number++;
	}
	cout << number << endl;
}