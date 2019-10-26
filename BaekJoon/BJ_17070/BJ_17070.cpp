#include<iostream>
#include<queue>
using namespace std;

struct Pipe {
	pair<int, int> index_a;
	pair<int, int> index_b;
	int direction; // -- : 0, | : 1, \ : 2

	Pipe(pair<int, int> input_a, pair<int, int> input_b, int input_direction) :
		index_a(input_a), index_b(input_b), direction(input_direction) {};
};

int main() {
	const int MAX_N = 16;
	int matrix[MAX_N + 2][MAX_N + 2];
	for (int i = 0; i < MAX_N + 2; i++)
		for (int j = 0; j < MAX_N + 2; j++)
			matrix[i][j] = 1;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> matrix[i][j];

	int totalCount = 0;
	queue<Pipe> pipes;
	pipes.push(Pipe(make_pair(1, 1), make_pair(1, 2), 0));

	pair<int, int> now_a, now_b;
	int now_direction;
	pair<int, int> new_a, new_b;
	int new_a_x, new_a_y, new_b_x, new_b_y;
	int new_direction;
	while (!pipes.empty()) {
		Pipe nowPipe = pipes.front();
		pipes.pop();
		now_a = nowPipe.index_a;
		now_b = nowPipe.index_b;
		now_direction = nowPipe.direction;

		//if (now_a.first > N || now_a.second > N
		//	|| now_b.first > N || now_b.second > N)
		//	continue;
		if (now_b.first == N && now_b.second == N) {
			totalCount++;
			continue;
		}


		// 대각선 이동 --  공통 사항
		new_a_x = now_a.first;
		new_a_y = now_a.second + 1;
		new_b_x = now_b.first + 1;
		new_b_y = now_b.second + 1;
		new_direction = 2;
		if (matrix[new_b_x][new_b_y] == 0
			&& matrix[new_b_x - 1][new_b_y] == 0 && matrix[new_b_x][new_b_y - 1] == 0) {
			pipes.push(Pipe(make_pair(new_a_x, new_a_y), make_pair(new_b_x, new_b_y), new_direction));
		}

		if (now_direction == 0) {
			// 옆으로 이동
			new_a_x = now_a.first;
			new_a_y = now_a.second + 1;
			new_b_x = now_b.first;
			new_b_y = now_b.second + 1;
			new_direction = 0;
			if (matrix[new_b_x][new_b_y] == 0) {
				pipes.push(Pipe(make_pair(new_a_x, new_a_y), make_pair(new_b_x, new_b_y), new_direction));
			}
		}

		if (now_direction == 1) {
			// 아래로 이동
			new_a_x = now_a.first + 1;
			new_a_y = now_a.second;
			new_b_x = now_b.first + 1;
			new_b_y = now_b.second;
			new_direction = 1;
			if (matrix[new_b_x][new_b_y] == 0) {
				pipes.push(Pipe(make_pair(new_a_x, new_a_y), make_pair(new_b_x, new_b_y), new_direction));
			}
		}

		if (now_direction == 2) {
			// 가로로
			new_a_x = now_a.first + 1;
			new_a_y = now_a.second + 1;
			new_b_x = now_b.first;
			new_b_y = now_b.second + 1;
			new_direction = 0;
			if (matrix[new_b_x][new_b_y] == 0) {
				pipes.push(Pipe(make_pair(new_a_x, new_a_y), make_pair(new_b_x, new_b_y), new_direction));
			}

			// 세로로
			new_a_x = now_a.first + 1;
			new_a_y = now_a.second + 1;
			new_b_x = now_b.first + 1;
			new_b_y = now_b.second;
			new_direction = 1;
			if (matrix[new_b_x][new_b_y] == 0) {
				pipes.push(Pipe(make_pair(new_a_x, new_a_y), make_pair(new_b_x, new_b_y), new_direction));
			}
		}
	}
	cout << totalCount << endl;
}