#include<iostream>
using namespace std;

long long getMin(long long a, long long b) {
	if (a > b)
		return b;
	else
		return a;
}

int main() {
	const int MAX_N = 100;
	const int MAX_M = 100000;
	long long matrix[MAX_N + 1][MAX_N + 1];
	for (int i = 0; i < MAX_N + 1; i++)
		for (int j = 0; j < MAX_N + 1; j++)
			matrix[i][j] = 999999;

	int N, M;
	cin >> N >> M;

	int sourceIndex, destinIndex;
	long long cost;
	for (int i = 0; i < M; i++) {
		cin >> sourceIndex >> destinIndex >> cost;
		if (matrix[sourceIndex][destinIndex] > cost)
			matrix[sourceIndex][destinIndex] = cost;
	}


	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				matrix[i][j] = getMin(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || matrix[i][j] == 999999)
				cout << 0 << " ";
			else
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}