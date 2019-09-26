#include<iostream>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;

	while (T > 0) {
		T--;
		cin >> N >> M;
		
		int location_a, location_b;
		for (int i = 0; i < M; i++) {
			cin >> location_a >> location_b;
		}
		cout << N - 1 << endl;
	}
}