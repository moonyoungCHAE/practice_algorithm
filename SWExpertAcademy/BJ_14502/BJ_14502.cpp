#include<iostream>
#include<queue>
using namespace std;

int matrix[10][10];
int copy_matrix[10][10];
int maxVirusArea = -1;
int virusArea = 0;
int N, M;

/*
 - DFS, 별도의 check 변수를 만드는 것보다 Queue로 하는 게 훨씬 편하다!
 - 벽 세울 때 모든 경우의 수를 하는 건 좀 아니지 않나..? 생각했는데,
   내 생각보다 큰 케이스도 모든 경우 세는 것 가능
*/

void callCheckVirus() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			copy_matrix[i][j] = matrix[i][j];


	queue <int> checkVirus_i;
	queue <int> checkVirus_j;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (copy_matrix[i][j] == 2) {
				checkVirus_i.push(i);
				checkVirus_j.push(j);
			}
		}

	while (!checkVirus_i.empty()) {
		int i = checkVirus_i.front();
		int j = checkVirus_j.front();
		checkVirus_i.pop();
		checkVirus_j.pop();
		if (copy_matrix[i + 1][j] == 0) {
			copy_matrix[i + 1][j] = 2;
			checkVirus_i.push(i + 1);
			checkVirus_j.push(j);
		}

		if (copy_matrix[i - 1][j] == 0) {
			copy_matrix[i - 1][j] = 2;
			checkVirus_i.push(i - 1);
			checkVirus_j.push(j);
		}

		if (copy_matrix[i][j + 1] == 0) {
			copy_matrix[i][j + 1] = 2;
			checkVirus_i.push(i);
			checkVirus_j.push(j + 1);
		}

		if (copy_matrix[i][j - 1] == 0) {
			copy_matrix[i][j - 1] = 2;
			checkVirus_i.push(i);
			checkVirus_j.push(j - 1);
		}
	}

	virusArea = 0;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (copy_matrix[i][j] == 0)
				virusArea++;
		}

	if (maxVirusArea == -1 || virusArea > maxVirusArea)
		maxVirusArea = virusArea;
}

void makeWall(int wallCount) {
	if (wallCount >= 3) {
		callCheckVirus();
		return;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = 1;
				makeWall(wallCount + 1);
				matrix[i][j] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i <= 11; i++)
		for (int j = 0; j <= 11; j++)
			matrix[i][j] = 1;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = 1;
				makeWall(1);
				matrix[i][j] = 0;
			}
		}
	}

	cout << maxVirusArea << endl;
	system("PAUSE");
}