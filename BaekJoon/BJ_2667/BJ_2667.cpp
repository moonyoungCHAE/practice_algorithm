#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 25;
int matrix[MAX_SIZE + 2][MAX_SIZE + 2];
int danjiCount = 0;
void search(int i, int j) {
	matrix[i][j] = 0;
	danjiCount++;

	if (matrix[i + 1][j] == 1)
		search(i + 1, j);
	if (matrix[i - 1][j] == 1)
		search(i - 1, j);
	if (matrix[i][j + 1] == 1)
		search(i, j + 1);
	if (matrix[i][j - 1] == 1)
		search(i, j - 1);
}
int main(){
	int N;
	cin >> N; // <= 25

	for (int i = 0; i < MAX_SIZE + 2; i++) {
		for (int j = 0; j < MAX_SIZE + 2; j++) {
			matrix[i][j] = 0;
		}
	}

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			matrix[i + 1][j + 1] = input.at(j) - 48;
		}
	}

	vector<int> danjis;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			if (matrix[i][j] == 1){
				danjiCount = 0;
				search(i, j);
				danjis.push_back(danjiCount);
		}
	
	sort(danjis.begin(), danjis.end());
	cout << danjis.size() << endl;
	for (int i = 0; i < danjis.size(); i++)
		cout << danjis[i] << endl;
}