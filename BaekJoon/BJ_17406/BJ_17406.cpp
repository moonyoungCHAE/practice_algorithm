#include<iostream>
#include<cstring>
using namespace std;

int N, M, K;
const int MAX_K = 6;
const int MAX_N = 50, MAX_M = 50;
bool check[MAX_K];
int matrix[MAX_N + 2][MAX_M + 2];
int tmp[MAX_N + 2][MAX_M + 2];
int rotationSquence[MAX_K];
int rArr[MAX_K];
int cArr[MAX_K];
int sArr[MAX_K];

int getMin(int i) {
	int sum = 0;
	for (int j = 1; j <= M; j++) {
		sum += tmp[i][j];
	}
	return sum;
}

// [3] 최소값을 구한다.
int minSum = 0;
void getMinSum() {
	int nowSum;
	for (int i = 1; i <= N; i++) {
		nowSum = getMin(i);
		if (minSum == 0 || nowSum < minSum)
			minSum = nowSum;
	}
}
// [2] 회전한다.
void makeRotate(int r, int c, int s) {
	int nowTmp[MAX_N + 2][MAX_M + 2];
	memcpy(nowTmp, tmp, sizeof(tmp));
	int i, j;
	while (s > 0) {
		// 위쪽 (->)
		i = r - s;
		for (j = c - s; j < c + s; j++) {
			nowTmp[i][j + 1] = tmp[i][j];
		}

		// 오른쪽 (위->아래)
		j = c + s;
		for (i = r - s; i < r + s; i++) {
			nowTmp[i + 1][j] = tmp[i][j];
		}

		// 아래 (<-)
		i = r + s;
		for (j = c + s; j > c - s; j--) {
			nowTmp[i][j - 1] = tmp[i][j];
		}

		// 왼쪽 (아래->위)
		j = c - s;
		for (i = r + s; i > r - s; i--) {
			nowTmp[i - 1][j] = tmp[i][j];
		}
		s--;
	}
	memcpy(tmp, nowTmp, sizeof(nowTmp));
}

// [1] 배열을 돌릴 순서를 정한다.
// 이미 check된 index이다. 이미 rotationIndex 자리에 값 들어간 상태이다.
void makeRotationSeq(int index, int rotationIndex, int size) {
	if (size >= K) {
		// rotation 시작
		memcpy(tmp, matrix, sizeof(tmp));
		for (int i = 0; i < K; i++) {
			int nowIndex = rotationSquence[i];
			makeRotate(rArr[nowIndex], cArr[nowIndex], sArr[nowIndex]);
		}
		// 최소값
		getMinSum();
	}

	if (rotationIndex >= K) {
		return;
	}

	for (int i = 0; i < K; i++) {
		if (i == index)
			continue;
		if (!check[i]) {
			check[i] = true;
			rotationSquence[rotationIndex + 1] = i;
			makeRotationSeq(i, rotationIndex + 1, size + 1);
			check[i] = false;
		}
	}
}

int main() {
	memset(matrix, 0, sizeof(matrix));

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < K; i++)
		cin >> rArr[i] >> cArr[i] >> sArr[i];

	for (int i = 0; i < K; i++) {
		memset(check, 0, sizeof(check));
		check[i] = true;
		rotationSquence[0] = i;
		makeRotationSeq(i, 0, 1);
	}
	cout << minSum << endl;
}