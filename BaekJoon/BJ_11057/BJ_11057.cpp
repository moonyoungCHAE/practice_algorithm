#include<iostream>
using namespace std;

struct NumberInfo {
	int numbers[10]; // 현재 numberInfo Index 기준에서 0, 1 .. 9 에 해당하는 숫자
};

int main() {
	int N;
	cin >> N;

	const int MAX_N = 1000;
	NumberInfo numberInfo[MAX_N + 1];

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			numberInfo[i].numbers[j] = 0;
		}
	}

	for (int i = 0; i < 10; i++)
		numberInfo[1].numbers[i] = 1;

	for (int index = 2; index <= N; index++) {
		for (int i = 0; i < 10; i++) {
			for (int j = i; j < 10; j++) {
				numberInfo[index].numbers[j] += numberInfo[index - 1].numbers[i];
				numberInfo[index].numbers[j] %= 10007;
			}
		}
	}

	int totalCount = 0;
	for (int i = 0; i < 10; i++) {
		totalCount += numberInfo[N].numbers[i];
	}
	cout << totalCount % 10007 << endl;
}