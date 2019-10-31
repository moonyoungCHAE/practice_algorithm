#include<iostream>
using namespace std;

int main() {
	const int MAX_N = 300, MAX_M = 300;
	int matrix[MAX_N + 2][MAX_N + 2] = { 0, };

	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> matrix[i][j];

	pair<int, int> startPoint; // ¿Ş, À§
	int nowWidthSize, nowHeightSize;

	while (R > 0) {
		R--;
		nowHeightSize = N;
		nowWidthSize = M;
		startPoint.first = 1;
		startPoint.second = 1;

		while (nowWidthSize > 0 && nowHeightSize > 0) {
			int temp = matrix[startPoint.first][startPoint.second]; // ¿Ş, À§
			
			int i, j;
			// ¿Ş <- ¿À
			// i, j : Ã¹ µµÂøÁö
			i = startPoint.first;
			j = startPoint.second;
			for (int count = 0; count < nowWidthSize - 1; count++) {
				matrix[i][j] = matrix[i][j + 1];
				j++;
			}

			// ¾Æ·¡ -> À§
			// i, j Ã¹ µµÂøÁö
			i = startPoint.first;
			j = startPoint.second + nowWidthSize - 1;
			for (int count = 0; count < nowHeightSize - 1; count++) {
				matrix[i][j] = matrix[i + 1][j];
				i++;
			}

			// ¿À -> ¿Ş
			// i, j : Ã¹ µµÂøÁö
			i = startPoint.first + nowHeightSize  - 1;
			j = startPoint.second + nowWidthSize - 1;
			for (int count = 0; count < nowWidthSize - 1; count++) {
				matrix[i][j] = matrix[i][j - 1];
				j--;
			}


			// À§ -> ¾Æ·¡
			i = startPoint.first + nowHeightSize - 1;
			j = startPoint.second;
			// i, j Ã¹ µµÂøÁö
			for (int count = 0; count < nowHeightSize - 2; count++) {
				matrix[i][j] = matrix[i - 1][j];
				i--;
			}
			matrix[startPoint.first + 1][startPoint.second] = temp;

			nowHeightSize -= 2;
			nowWidthSize -= 2;
			startPoint.first += 1;
			startPoint.second += 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
}