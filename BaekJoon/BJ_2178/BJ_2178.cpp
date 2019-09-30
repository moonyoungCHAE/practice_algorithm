#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;


int main() {
	const int MAX_SIZE = 100;

	bool canMove[MAX_SIZE + 2][MAX_SIZE + 2];
	int routes[MAX_SIZE + 2][MAX_SIZE + 2];
	for (int i = 0; i < MAX_SIZE + 2; i++)
		for (int j = 0; j < MAX_SIZE + 2; j++) {
			canMove[i][j] = false; // 1: 이동 가능, 0: 이동 불가
			routes[i][j] = 0;
		}

	int N, M;
	cin >> N >> M;

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			if (input.at(j) == '1')
				canMove[i + 1][j + 1] = true;
			else
				canMove[i + 1][j + 1] = false;
		}
	}
	queue<pair<int, pair<int, int>>> q; // count(routes), x, y
	q.push(make_pair(1, make_pair(1, 1)));

	int xs[] = { 1, 0, -1, 0 };
	int ys[] = { 0, 1, 0, -1 };
	int route, x, y;
	int minValue = -1;
	while(!q.empty()){
		route = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();

		if (x == N && y == M) {
			if (minValue == -1 || minValue > route)
				minValue = route;
		}

		if (routes[x][y] == 0 || routes[x][y] > route) {
			routes[x][y] = route;
		}

		for (int i = 0; i < 4; i++) {
			if (!canMove[x + xs[i]][y + ys[i]])
				continue;
			if (x + xs[i] < 1 || x + xs[i] > N)
				continue;
			if (y + ys[i] < 1 || y + ys[i] > M)
				continue;
			if (routes[x + xs[i]][y + ys[i]] == 0 || routes[x + xs[i]][y + ys[i]] > route + 1) {
				routes[x + xs[i]][y + ys[i]] = route + 1;
				q.push(make_pair(route + 1, make_pair(x + xs[i], y + ys[i])));
			}
		}
	}
	cout << minValue << endl;
	system("PAUSE");
}