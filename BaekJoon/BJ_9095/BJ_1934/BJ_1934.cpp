#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	int A, B;
	while (T > 0) {
		T--;
		cin >> A >> B;

		int number = 1;
		while (true) {
			if ((A * number) % A == 0 && (A * number) % B == 0) {
				cout << A * number << endl;
				break;
			}

			if ((B * number) % A == 0 && (B * number) % B == 0) {
				cout << B * number << endl;
				break;
			}
			number++;
		}
	}
}