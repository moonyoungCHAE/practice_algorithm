#include<iostream>
using namespace std;

int main() {
	const int MAX_SIZE = 300;

	int N, M;
	cin >> N >> M;

	int number[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			number[i][j] = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> number[i][j];

	int testCase;
	cin >> testCase;
	
	int x1, y1, x2, y2;
	while (testCase > 0) {
		testCase--;

		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) {
			int temp = x2;
			x2 = x1;
			x1 = x2;
		}

		if (y1 > y2) {
			int temp = y2;
			y2 = y1;
			y1 = y2;
		}
		x1--;
		y1--;
		x2--;
		y2--;
		
		long long total = 0;
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				total += number[i][j];

		cout << total << endl;
	}
}