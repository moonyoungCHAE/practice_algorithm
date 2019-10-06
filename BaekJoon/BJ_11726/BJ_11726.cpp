#include<iostream>
using namespace std;


int main() {
	const int MAX_N = 1000;
	int counting[MAX_N + 1];

	for (int i = 0; i < MAX_N + 1; i++)
		counting[i] = 0;

	int N;
	cin >> N;

	counting[1] = 1;
	counting[2] = 2;

	for (int i = 3; i <= N; i++) {
		counting[i] += counting[i - 1];
		counting[i] += counting[i - 2] ;
		counting[i] %= 10007;
	}

	cout << counting[N] % 10007 << endl;
}