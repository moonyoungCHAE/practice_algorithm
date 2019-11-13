#include<iostream>
#include<string.h>
using namespace std;


int N;
const int MAX_N = 49;
int number[MAX_N];
bool check[MAX_N];

void search(int index, int count) {
	if (count > 6) {
		return;
	}
	if (index >= N) {
		if (count != 6)
			return;
		for (int i = 0; i < N; i++) {
			if (check[i])
				cout << number[i] << " ";
		}
		cout << endl;
		return;
	}
	
	check[index] = true;
	search(index + 1, count + 1);

	check[index] = false;
	search(index + 1, count);
}
 
int main() {
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		memset(number, 0, sizeof(number));
		for (int i = 0; i < N; i++)
			cin >> number[i];

		for (int i = 0; i < N; i++)
			check[i] = false;

		search(0, 0);
		cout << endl;
	}
}