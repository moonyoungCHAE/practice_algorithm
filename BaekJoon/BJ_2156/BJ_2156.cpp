#include<iostream>
#include<queue>
using namespace std;

int getMax(int num1, int num2, int num3) {
	if (num1 >= num2 && num1 >= num3)
		return num1;
	if (num2 >= num1 && num2 >= num3)
		return num2;
	if (num3 >= num1 && num3 >= num2)
		return num3;
}

int main() {
	const int MAX_N = 10000;
	int wine[MAX_N + 1];
	wine[0] = 0;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> wine[i];

	int wine_0[MAX_N + 1];
	int wine_1[MAX_N + 1];
	int wine_2[MAX_N + 1];

	for (int i = 0; i < MAX_N + 1; i++) {
		wine_0[i] = 0;
		wine_1[i] = 0;
		wine_2[i] = 0;
	}

	wine_1[1] = wine[1];
	for (int i = 2; i <= N; i++) {
		wine_0[i] = getMax(wine_0[i - 1], wine_1[i - 1], wine_2[i - 1]);
		wine_1[i] = wine_0[i - 1] + wine[i];
		wine_2[i] = wine_1[i - 1] + wine[i];
	}

	int maxTotal = wine_0[N];
	if (wine_1[N] > maxTotal)
		maxTotal = wine_1[N];
	if (wine_2[N] > maxTotal)
		maxTotal = wine_2[N];

	cout << maxTotal << endl;
}