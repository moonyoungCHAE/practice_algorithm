#include<iostream>
#include<algorithm>
using namespace std;

int height[9];
bool selected[9];
int result[7];
void find(int index, int totalCount, int total) {
	if (index >= 9) {
		if (totalCount == 7 && total == 100) {
			int index = 0;
			for (int i = 0; i < 10; i++) {
				if (selected[i])
					result[index++] = height[i];
			}
		}
		return;
	}

	if (total > 100)
		return;
	if (totalCount > 7)
		return;

	// 포함할 때
	selected[index] = true;
	find(index + 1, totalCount + 1, total + height[index]);
	// 포함안할 때
	selected[index] = false;
	find(index + 1, totalCount, total);
}

int main() {
	for (int i = 0; i < 9; i++)
		cin >> height[i];

	fill(&selected[0], &selected[9], false);
	find(0, 0, 0);
	sort(result, result + 7);
	for (int i = 0; i < 7; i++) {
		cout << result[i] << endl;
	}
}