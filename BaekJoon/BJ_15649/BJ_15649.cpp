#include<iostream>
using namespace std;

const int MAX_N = 8;
int number[MAX_N + 1];
int N, M;

// index까지 포함된 상태에서 call
void search(int index) {
	if (index >= M) {
		for (int i = 1; i <= M; i++) {
			cout << number[i] << " ";
		}
		cout << '\n';
		return;
	}

	bool check[MAX_N + 1] = { false, };
	for (int i = 1; i <= index; i++) {
		check[number[i]] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			number[index + 1] = i;
			search(index + 1);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		number[1] = i;
		search(1);
	}
}