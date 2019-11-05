#include<iostream>
using namespace std;

const int MAX_M = 7;
int N, M;
int numbers[MAX_M + 1] = { 1, };

void search(int nowIndex) {
	if (nowIndex > M) {
		for (int i = 1; i <= M; i++) {
			cout << numbers[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int nowNumber = 1; nowNumber <= N; nowNumber++) {
		numbers[nowIndex] = nowNumber;
		search(nowIndex + 1);
	}
}

int main() {
	cin >> N >> M;
	search(1);
}