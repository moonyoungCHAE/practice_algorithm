#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int N = 50, M = 50;
char matrix[N + 2][M + 2];
bool visited[N + 2][M + 2];
char nowChar;
bool result = false;
int startX, startY;

string getDirection(int i) {
	if (i == 0)
		return "right";
	if (i == 1)
		return "down";
	if (i == 2)
		return "left";
	if (i == 3)
		return "up";
}

bool canMove(string direction, char nowChar, int nowX, int nowY) {
	if (direction == "up")
		nowX -= 1;

	if (direction == "down")
		nowX += 1;

	if (direction == "right")
		nowY += 1;
	
	if (direction == "left")
		nowY -= 1;

	if (matrix[nowX][nowY] == nowChar 
		&& nowX >= 1 && nowX <= N 
		&& nowY >= 1 && nowY <= M
		&& !visited[nowX][nowY])
		return true;
	return false;
}

int addX(string direction) {
	if (direction == "up")
		return -1;
	if (direction == "down")
		return 1;
	return 0;
}

int addY(string direction) {
	if (direction == "right")
		return 1;
	if (direction == "left")
		return -1;
	return 0;
}

// 현재 inputX, inputY를 포함한 count
void dfs(int inputX, int inputY, int count) {
	if (result)
		return;

	int nowX, nowY;
	for (int i = 0; i < 4; i++) {
		string nowDirection = getDirection(i);
		nowX = inputX + addX(nowDirection);
		nowY = inputY + addY(nowDirection);
		if (nowX == startX && nowY == startY && count + 1 >= 4) {
			result = true;
			return;
		}
		if (canMove(nowDirection, nowChar, inputX, inputY)) {
			visited[nowX][nowY] = true;
			dfs(nowX, nowY, count + 1);
		}
	}
}

int main() {
	for (int i = 0; i < N + 2; i++)
		for (int j = 0; j < M + 2; j++)
			matrix[i][j] = '-';

	int N, M;
	cin >> N >> M;
	string input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			matrix[i][j + 1] = input.at(j);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (result) {
				break;
			}
			nowChar = matrix[i][j];
			memset(visited, false, sizeof(visited));
			startX = i;
			startY = j;
			visited[startX][startY] = true;
			dfs(i, j, 1);
		}
	}
	if (result)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}