#include<iostream>
#include<queue>
using namespace std;

bool checkRange(int x, int y, int size) {
	if (x < 0)
		return false;
	if (x >= size)
		return false;
	if (y < 0)
		return false;
	if (y >= size)
		return false;
	return true;
}

bool checkDestination(int x, int y, int destination_x, int destionation_y) {
	if ((x == destination_x) && (y == destionation_y))
		return true;
	return false;
}

int main() {
	int const MAX_SIZE = 300;
	bool visited[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			visited[i][j] = false;

	int dy[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
	int dx[] = { -2, 2, -2, 2, -1, 1, -1, 1 };


	int T;
	cin >> T;

	int size;

	queue<pair<int, pair<int, int>>> q;
	int now_x, now_y;
	int destination_x, destination_y;
	for (int i = 0; i < T; i++) {
		cin >> size;
		cin >> now_x >> now_y;
		cin >> destination_x >> destination_y;

		if (now_x == destination_x && now_y == destination_y) {
			cout << 0 << endl;
			continue;
		}

		// ÃÊ±âÈ­
		while (!q.empty()) {
			q.pop();
		}

		for (int a = 0; a < size; a++)
			for (int b = 0; b < size; b++)
				visited[a][b] = false;

		q.push(make_pair(0, make_pair(now_x, now_y)));
		visited[now_x][now_y] = true;
		
		int now_count;
		while (!q.empty()) {
			now_count = q.front().first;
			pair<int, int> now_location = q.front().second;
			q.pop();
			now_x = now_location.first;
			now_y = now_location.second;


			bool findDestination = false;

			if (now_x == destination_x && now_y == destination_y) {
				break;
			}

			for (int i = 0; i < 8; i++) {
				if (!checkRange(now_x + dx[i], now_y + dy[i], size))
					continue;
				if (visited[now_x + dx[i]][now_y + dy[i]])
					continue;
				if (checkDestination(now_x + dx[i], now_y + dy[i], destination_x, destination_y)) {
					findDestination = true;
					break;
				}

				q.push(make_pair(now_count + 1, make_pair(now_x + dx[i], now_y + dy[i])));
				visited[now_x + dx[i]][now_y + dy[i]] = true;
			}

			if (findDestination) {
				break;
			}
		}

		cout << now_count + 1 << endl;
	}
}