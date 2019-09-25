#include<iostream>
using namespace std;

const int MAX_SIZE = 50;
int matrix[MAX_SIZE + 2][MAX_SIZE + 2];

void search(int x, int y) {
	matrix[x][y] = 0;
	if (matrix[x + 1][y] == 1)
		search(x + 1, y);
	if (matrix[x - 1][y] == 1)
		search(x - 1, y);
	if (matrix[x][y + 1] == 1)
		search(x, y + 1);
	if (matrix[x][y - 1] == 1)
		search(x, y - 1);
}

int main() {

	int T;
	cin >> T;
	while (T > 0) {
		T--;

		for (int i = 0; i < MAX_SIZE + 2; i++)
			for (int j = 0; j < MAX_SIZE + 2; j++)
				matrix[i][j] = 0;

		int M, N, K;
		cin >> M >> N >> K;

		int x, y;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			matrix[x + 1][y + 1] = 1;
		}

		int count = 0;
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++) {
				if (matrix[i][j] == 1) {
					search(i, j);
					count++;
				}
			}

		cout << count << endl;
	}
}