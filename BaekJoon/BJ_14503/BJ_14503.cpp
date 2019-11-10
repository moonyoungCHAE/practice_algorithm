#include<iostream>
using namespace std;

const int MAX_N = 50, MAX_M = 50;
int matrix[MAX_N + 2][MAX_M + 2];
bool check[MAX_N + 2][MAX_M + 2];
int nowR, nowC, nowD;

// 반시계 방향으로 회전
int getNextD(int d) {
	if (d == 0)
		return 3;
	else
		return d-1;
}

int getLeftX(int x, int y, int d) {
	if (d == 0)
		return x;
	if (d == 3)
		return x + 1;
	if (d == 2)
		return x;
	if (d == 1)
		return x - 1;
}

int getLeftY(int x, int y, int d) {
	if (d == 0)
		return y - 1;
	if (d == 3)
		return y;
	if (d == 2)
		return y + 1;
	if (d == 1)
		return y;
}

int getBackX(int x, int y, int d) {
	if (d == 0)
		return x + 1;
	if (d == 3)
		return x;
	if (d == 2)
		return x - 1;
	if (d == 1)
		return x;
}

int getBackY(int x, int y, int d) {
	if (d == 0)
		return y;
	if (d == 3)
		return y + 1;
	if (d == 2)
		return y;
	if (d == 1)
		return y - 1;
}

// 청소는 된 상태
void search(int x, int y, int d) {
	// cout << "x: " << x << ", y: " << y << ", d: " << d << endl;
	int nowD = d;
	int nowX, nowY;
	for (int i = 1; i <= 4; i++) {
		nowX = getLeftX(x, y, nowD);
		nowY = getLeftY(x, y, nowD);
		nowD = getNextD(nowD);
		
		// 벽이라면 패스
		if (matrix[nowX][nowY] == 1)
			continue;
		// 이미 청소했다면 패스
		if (check[nowX][nowY])
			continue;
		check[nowX][nowY] = true;
		return search(nowX, nowY, nowD);
	}
	nowX = getBackX(x, y, d);
	nowY = getBackY(x, y, d);
	if (matrix[nowX][nowY] == 1)
		return;
	search(nowX, nowY, d);
}

int main() {
	fill(&matrix[0][0], &matrix[MAX_N + 2][MAX_M + 2], 1);
	fill(&check[0][0], &check[MAX_N + 2][MAX_M + 2], false);
	int N, M;
	cin >> N >> M;
	cin >> nowR >> nowC >> nowD;
	nowR++; nowC++;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> matrix[i][j];

	check[nowR][nowC] = true;
	search(nowR, nowC, nowD);
	int counting = 0;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (check[i][j])
				counting++;
		}

	cout << counting << endl;
}