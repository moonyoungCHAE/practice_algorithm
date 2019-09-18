#include<iostream>
#include<string>
using namespace std;

void countForNormal(int i, int j, char value, char (* matrix)[102]) {
	if (matrix[i][j] != value)
		return;
	
	matrix[i][j] = 'C';

	countForNormal(i + 1, j, value, matrix);
	countForNormal(i - 1, j, value, matrix);
	countForNormal(i, j + 1, value, matrix);
	countForNormal(i, j - 1, value, matrix);
}

int main() {
	int N;
	cin >> N;

	// 초기화
	char normalMatrix[102][102];
	char rgMatrix[102][102]; // 적녹색약
	for (int i = 0; i < 102; i++) 
		for (int j = 0; j < 102; j++) {
			normalMatrix[i][j] = '-';
			rgMatrix[i][j] = '-';
		}
	
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		
		for (int j = 0; j < N; j++) {
			normalMatrix[i + 1][j + 1] = input.at(j);
			rgMatrix[i + 1][j + 1] = input.at(j);

			if (input.at(j) == 'G')
				rgMatrix[i + 1][j + 1] = 'R';
		}
	}

	int normalCount = 0;
	int rgCount = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (normalMatrix[i][j] != 'C') {
				normalCount++;
				countForNormal(i, j, normalMatrix[i][j], normalMatrix);
			}
			if (rgMatrix[i][j] != 'C') {
				rgCount++;
				countForNormal(i, j, rgMatrix[i][j], rgMatrix);
			}
		}
	}

	cout << normalCount << " " << rgCount << endl;
}