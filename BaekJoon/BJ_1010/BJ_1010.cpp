#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	const int MAX_N = 30;
	const int MAX_M = 30;
	long long matrix[MAX_N + 1][MAX_M + 1];

	int N, M;
	while (T > 0) {
		T--;
		cin >> N >> M;
		for (int i = 0; i < MAX_N + 1; i++)
			for (int j = 0; j < MAX_M + 1; j++)
				matrix[i][j] = 0;
		
		// ÃÊ±âÈ­
		for (int nowM = 1; nowM <= M - (N - 1); nowM++)
			matrix[1][nowM] = 1;

		
		int nowM;
		for (int nowN = 2; nowN <= N; nowN++) {
			for (nowM = nowN; nowM <= M - (N - nowN); nowM++) {
				matrix[nowN][nowM] += matrix[nowN][nowM - 1];
				matrix[nowN][nowM] += matrix[nowN - 1][nowM - 1];
			}
		}

		int totalCount = 0;
		for (int nowM = N; nowM <= M; nowM++) {
			totalCount += matrix[N][nowM];
		}
		cout << totalCount << endl;
	}
}