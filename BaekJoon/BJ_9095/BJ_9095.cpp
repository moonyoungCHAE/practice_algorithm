#include<iostream>
#include<string>
using namespace std;

int totalCount = 0;

void check( int number) {
	if (number == 0) {
		totalCount++;
		return;
	}

	for (int i = 3; i > 0; i--) {
		if (i > number)
			continue;
		check(number - i);
	}
}

int main() {
	int TEST_CASE;
	cin >> TEST_CASE;

	int N;
	while (TEST_CASE > 0) {
		TEST_CASE--;
		cin >> N;
		
		totalCount = 0;
		check(N);
		cout << totalCount << endl;
	}

	system("PAUSE");
}