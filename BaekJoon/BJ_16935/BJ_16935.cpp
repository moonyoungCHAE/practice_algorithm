#include<iostream>
#include<cstring>
using namespace std;

int N, M;
const int MAX_N = 100, MAX_M = 100;
int matrix[MAX_N][MAX_M] = { 0, };
int temp[MAX_N][MAX_M] = { 0, };

// 1. ���Ϲ���
void case1() {
	int minN = 0, maxN = N - 1;
	while (minN < maxN) {
		for (int j = 0; j < M; j++)
			swap(matrix[minN][j], matrix[maxN][j]);
		minN++;
		maxN--;
	}
}

// 2. �¿����
void case2() {
	int minM = 0, maxM = M - 1;
	while (minM < maxM) {
		for (int i = 0; i < N; i++)
			swap(matrix[i][minM], matrix[i][maxM]);
		minM++;
		maxM--;
	}
}

// 3. ���������� 90��
void case3() {
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[j][N - 1 - i] = matrix[i][j];
		}
	}
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_M; j++)
			matrix[i][j] = temp[i][j];
	swap(N, M);
}

// 4. �������� 90��
void case4() {
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[M - 1 - j][i] = matrix[i][j];
		}
	}
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_M; j++)
			matrix[i][j] = temp[i][j];
	swap(N, M);
}

// 5. 
void case5() {
	memset(temp, 0, sizeof(temp));
	// 1�� �迭 to 2�� �迭
	for (int i = 0; i < N / 2; i++) 
		for (int j = 0; j < M / 2; j++) 
			temp[i][j + M / 2] = matrix[i][j];
		

	// 2�� �迭 to 3�� �迭
	for (int i = 0; i < N / 2; i++) 
		for (int j = M / 2; j < M; j++)
			temp[i + N / 2][j] = matrix[i][j];

	// 3�� �迭 to 4�� �迭
	for (int i = N / 2; i < N; i++)
		for (int j = M / 2; j < M; j++)
			temp[i][j - M / 2] = matrix[i][j];

	// 4�� �迭 to 1�� �迭
	for (int i = N / 2; i < N; i++)
		for (int j = 0; j < M / 2; j++)
			temp[i - N / 2][j] = matrix[i][j];

	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_M; j++)
			matrix[i][j] = temp[i][j];
}

// 6
void case6() {
	memset(temp, 0, sizeof(temp));
	// 1�� �迭 to 4�� �迭
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
			temp[i + N / 2][j] = matrix[i][j];

	// 2�� �迭 to 1�� �迭
	for (int i = 0; i < N / 2; i++)
		for (int j = M / 2; j < M; j++)
			temp[i][j - M / 2] = matrix[i][j];

	// 3�� �迭 to 2�� �迭
	for (int i = N / 2; i < N; i++)
		for (int j = M / 2; j < M; j++)
			temp[i - N / 2][j] = matrix[i][j];
	
	// 4�� �迭 to 3�� �迭
	for (int i = N / 2; i < N; i++)
		for (int j = 0; j < M / 2; j++)
			temp[i][j + M / 2] = matrix[i][j];

	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_M; j++)
			matrix[i][j] = temp[i][j];
}
int main() {

	int R;
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> matrix[i][j];

	int nowR;
	for (int countR = 0; countR < R; countR++) {
		cin >> nowR;
		if (nowR == 1) {
			case1();
		}
		else if (nowR == 2) {
			case2();
		}
		else if (nowR == 3) {
			case3();
		}
		else if (nowR == 4) {
			case4();
		}
		else if (nowR == 5) {
			case5();
		}
		else if (nowR == 6) {
			case6();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
}