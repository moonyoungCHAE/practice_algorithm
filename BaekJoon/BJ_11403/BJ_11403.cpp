#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> vec;
int matrix[100][100];

void check(int start, int mid) {
	matrix[start][mid] = 1;
	
	for (int i = 0; i < vec[mid].size(); i++) {
		if(matrix[start][vec[mid][i]] == 0)
			check(start, vec[mid][i]);
	}
}

int main() {
	int N;
	cin >> N;

	vec.resize(N);
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1) {
				vec[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			matrix[i][j] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			check(i, vec[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//system("PAUSE");
}