#include<iostream>
using namespace std;

int N, S;
const int MAX_N = 20;
int matrix[MAX_N];
int totalCount = 0;
bool checked[MAX_N];

// 이번 index를 포함해야 한다.
void search(int index, long long sum) {
	if (index >= N) {
		int trueCount = 0;
		for (int i = 0; i < N; i++) {
			if (checked[i])
				trueCount++;
		}
		if (trueCount == 0)
			return;

		if (sum == S) {
			totalCount++;
		}
		return;
	}

	// 이번 index를 포함하는 경우
	checked[index] = true;
	search(index + 1, sum + matrix[index]);

	// 이번 index를 포함하지 않는 경우
	checked[index] = false;
	search(index + 1, sum);
}

int main() {
	cin >> N >> S;

	memset(matrix, 0, sizeof(matrix));
	for (int i = 0; i < N; i++)
		cin >> matrix[i];
	
	memset(checked, false, sizeof(checked));
	search(0, 0);
	cout << totalCount << endl;
	system("PAUSE");

}