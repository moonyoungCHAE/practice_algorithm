#include<iostream>
#include<cstring>
using namespace std;

const int MAX_N = 100;
int N;
int matrix[MAX_N + 2][MAX_N + 2] = { 0, };
bool checked[MAX_N + 2][MAX_N + 2] = { false, };
int maxCount = 1;
int nowCount = 0;

// 이미 x, y checked 완료 / count 증가 완료
void dfs(int x, int y, double length) {
	//cout << "(" << x << "," << y << ") nowCount: " << nowCount << endl;
	if (matrix[x + 1][y] > length && !checked[x+1][y]) {
		checked[x + 1][y] = true;
		dfs(x + 1, y, length);
	}

	if (matrix[x - 1][y] > length && !checked[x - 1][y]) {
		checked[x - 1][y] = true;
		dfs(x - 1, y, length);
	}

	if (matrix[x][y + 1] > length && !checked[x][y + 1]) {
		checked[x][y + 1] = true;
		dfs(x, y + 1, length);
	}

	if (matrix[x][y - 1] > length && !checked[x][y - 1]) {
		checked[x][y - 1] = true;
		dfs(x, y - 1, length);
	}
}

int main() {
	for(int i = 0; i < MAX_N + 2; i++)
		for (int j = 0; j < MAX_N + 2; j++) {
			matrix[i][j] = 0;
		}

	cin >> N;

	int minValue = -1, maxValue = -1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			if (minValue == -1 || minValue > matrix[i][j])
				minValue = matrix[i][j];
			if (maxValue == -1 || maxValue < matrix[i][j])
				maxValue = matrix[i][j];
		}

	for (double length = minValue; length <= maxValue; length += 0.5) {
		memset(checked, false, sizeof(checked));
		nowCount = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (matrix[i][j] > length && !checked[i][j]) {
					checked[i][j] = true;
					dfs(i, j, length);
					nowCount++;
				}
			}

		if (nowCount > maxCount)
			maxCount = nowCount;
	}
	cout << maxCount << endl;
}