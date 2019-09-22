#include<iostream>
#include<string>
using namespace std;

int sheepCount = 0, wolfCount = 0;
void checkMatrix(int i, int j, char matrix[][252]) {
	if (matrix[i][j] == 'o')
		sheepCount++;

	if (matrix[i][j] == 'v')
		wolfCount++;

	matrix[i][j] = '#';
	if (matrix[i + 1][j] != '#')
		checkMatrix(i + 1, j, matrix);

	if (matrix[i - 1][j] != '#')
		checkMatrix(i - 1, j, matrix);

	if (matrix[i][j + 1] != '#')
		checkMatrix(i, j + 1, matrix);

	if (matrix[i][j - 1] != '#')
		checkMatrix(i, j - 1, matrix);
}
int main() {
	const int MAX_MATRIX = 252;
	char matrix[MAX_MATRIX][MAX_MATRIX];

	for (int i = 0; i < MAX_MATRIX; i++)
		for (int j = 0; j < MAX_MATRIX; j++)
			matrix[i][j] = '#';

	int R, C;
	cin >> R >> C;

	string input;
	for (int i = 1; i <= R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			matrix[i][j + 1] = input.at(j);
		}
	}
	
	int totalSheepCount = 0, totalWolfCount = 0;
	for (int i = 1; i <= R; i++) 
		for (int j = 1; j <= C; j++) 
			if (matrix[i][j] != '#') {
				sheepCount = 0, wolfCount = 0;
				checkMatrix(i, j, matrix);
				if (sheepCount > wolfCount)
					totalSheepCount += sheepCount;
				else
					totalWolfCount += wolfCount;
			}

	cout << totalSheepCount << " " << totalWolfCount << endl;
}
