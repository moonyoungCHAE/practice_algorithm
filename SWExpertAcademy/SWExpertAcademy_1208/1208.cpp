#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int numbers[100];

	for (int tCount = 1; tCount <= 10; tCount++) {
		int dump;
		cin >> dump;

		int input;
		for (int i = 0; i < 100; i++) {
			cin >> numbers[i];
		}

		while (dump >= 0) {
			dump--;
			sort(numbers, numbers + 100);
			if (numbers[99] - numbers[0] <= 1)
				break;
			numbers[0]++;
			numbers[99]--;
		}
		sort(numbers, numbers + 100);
		int diff = (numbers[99] - numbers[0]);
		cout << "#" << tCount << " " << diff << endl;
	}
}