#include<iostream>
using namespace std;

int main() {
	const int MAX_SIZE = 1000;

	int N, M;
	cin >> N >> M;
	
	int index[MAX_SIZE + 1];
	for (int i = 0; i < MAX_SIZE + 1; i++)
		index[i] = -1;
	
	bool single[MAX_SIZE + 1];
	for (int i = 0; i < MAX_SIZE + 1; i++)
		single[i] = true;

	int input_a, input_b;
	int max_index = 0;
	for (int i = 0; i < M; i++) {
		cin >> input_a >> input_b;

		int index_a = index[input_a];
		int index_b = index[input_b];

		if (index_a == -1 && index_b == -1) { // 둘 다 체크가 안 됨
			index[input_a] = max_index;
			index[input_b] = max_index;
			max_index++;
		}
		else if (index_a == -1) { // input_a (체크 X) <-> input_b (체크 O)
			index[input_a] = index_b;
		}
		else if (index_b == -1) { // input_a (체크 O) <-> input_b (체크 X)
			index[input_b] = index_a;
		}
		else {
			if (index_a == index_b) { // 고리 연결
				continue;
			}
			if (index_a < index_b) { // 고리 연결
				single[index_a] = false;
			}
			else {
				single[index_b] = false;
			}
		}
	}


	int count = 0;
	for (int i = 1; i <= N; i++) {
		int nowIndex = index[i];
		if (single[nowIndex]) {
			count++;
			single[nowIndex] = false;
		}
	}

	cout << count << endl;
	system("PAUSE");
}