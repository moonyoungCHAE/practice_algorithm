#include<iostream>
#include<vector>
using namespace std;

int main() {
	const int MAX_N = 500;
	vector<int> inputNumber[MAX_N];
	vector<int> changedNumber[MAX_N];

	
	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i + 1; j++) {
			cin >> input;
			inputNumber[i].push_back(input);
			changedNumber[i].push_back(input);
		}

	for(int i = 0; i < N - 1; i++)
		for (int j = 0; j <= i; j++) {
			if (changedNumber[i][j] + inputNumber[i + 1][j] > changedNumber[i + 1][j])
				changedNumber[i + 1][j] = changedNumber[i][j] + inputNumber[i + 1][j];
			if (changedNumber[i][j] + inputNumber[i + 1][j + 1] > changedNumber[i + 1][j + 1])
				changedNumber[i + 1][j + 1] = changedNumber[i][j] + inputNumber[i + 1][j + 1];
		}

	int max = -1;
	for (int j = 0; j < N; j++) {
		if (changedNumber[N - 1][j] > max)
			max = changedNumber[N - 1][j];
	}

	cout << max << endl;
}