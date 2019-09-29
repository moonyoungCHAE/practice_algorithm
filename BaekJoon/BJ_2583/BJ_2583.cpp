#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 100;
bool matrix[MAX_SIZE + 2][MAX_SIZE + 2];
int area = 0;

void findArea(int x, int y) {
	//cout << "x: " << x << "y: " << y << endl;
	area++;
	matrix[x][y] = false;
	if (matrix[x + 1][y]) {
		findArea(x + 1, y);
	}
	if (matrix[x - 1][y]) {
		findArea(x - 1, y);
	}
	if (matrix[x][y + 1]) {
		findArea(x, y + 1);
	}
	if (matrix[x][y - 1]) {
		findArea(x, y - 1);
	}
}

int main() {
	for (int i = 0; i < MAX_SIZE + 2; i++)
		for (int j = 0; j < MAX_SIZE + 2; j++)
			matrix[i][j] = true;
	

	int N, M, inputSquareCount;
	cin >> N >> M >> inputSquareCount;

	// 패딩 접근할 수 없도록
	for (int i = 0; i <  MAX_SIZE + 2; i++) {
		matrix[i][0] = false;
		matrix[i][N + 1] = false;
		matrix[0][i] = false;
		matrix[M + 1][i] = false;
	}

	int x1, y1, x2, y2;
	while (inputSquareCount > 0) {
		inputSquareCount--;
		cin >> x1 >> y1 >> x2 >> y2;
		x1++; y1++; x2++; y2++;
		if (x1 > x2) {
			int temp = x2;
			x2 = x1;
			x1 = temp;
		}

		if (y1 > y2) {
			int temp = y2;
			y2 = y1;
			y1 = temp;
		}

		// x1 < x2, y1 < y2
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				matrix[x][y] = false;
			}
		}
	}
	vector<int> areas;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!matrix[i][j])
				continue;
			area = 0;
			findArea(i, j);
			areas.push_back(area);
		}
	}
	sort(areas.begin(), areas.end());

	cout << areas.size() << endl;
	for (int i = 0; i < areas.size(); i++) {
		cout << areas[i] << " ";
	}
	system("PAUSE");
}