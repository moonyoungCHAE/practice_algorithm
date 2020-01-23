// 14499
#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 20, MAX_M = 20;
int map[MAX_N + 2][MAX_M + 2];
int dice[6];
int N, M;
int x, y;

bool move(int command) {
	int change[6];

	int toMoveX, toMoveY;
	if (command == 1) {
		toMoveX = x;
		toMoveY = y + 1;
	}

	if (command == 2) {
		toMoveX = x;
		toMoveY = y - 1;
	}

	if (command == 3) {
		toMoveX = x - 1;
		toMoveY = y;

	}

	if (command == 4) {
		toMoveX = x + 1;
		toMoveY = y;

	}

	// 이동불가
	if (toMoveX <= 0 || toMoveY <= 0
		|| toMoveX > N || toMoveY > M || map[toMoveX][toMoveY] == -1) {
		return false;
	}

	// 이동 
	x = toMoveX;
	y = toMoveY;

	// 주사위 굴리기
	if (command == 1) {
		change[0] = dice[0];
		change[1] = dice[1];
		change[2] = dice[4];
		change[3] = dice[5];
		change[4] = dice[3];
		change[5] = dice[2];
	}

	if (command == 2) {
		change[0] = dice[0];
		change[1] = dice[1];
		change[2] = dice[5];
		change[3] = dice[4];
		change[4] = dice[2];
		change[5] = dice[3];
	}

	if (command == 3) {
		change[0] = dice[5];
		change[1] = dice[4];
		change[2] = dice[2];
		change[3] = dice[3];
		change[4] = dice[0];
		change[5] = dice[1];
	}

	if (command == 4) {
		change[0] = dice[4];
		change[1] = dice[5];
		change[2] = dice[2];
		change[3] = dice[3];
		change[4] = dice[1];
		change[5] = dice[0];
	}

	for (int i = 0; i < 6; i++)
		dice[i] = change[i];

	// 바닥면 처리
	if (map[toMoveX][toMoveY] == 0) {
		map[toMoveX][toMoveY] = dice[5];
	}
	else {
		dice[5] = map[toMoveX][toMoveY];
		map[toMoveX][toMoveY] = 0;
	}
	return true;
}

int main() {
	for (int i = 0; i < MAX_N + 2; i++)
		for (int j = 0; j < MAX_M + 2; j++)
			map[i][j] = -1;

	for (int i = 0; i < 6; i++)
		dice[i] = 0;

	int commandCount;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &commandCount);
	x++; y++;

	int mapInfo;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			scanf("%d", &mapInfo);
			map[i][j] = mapInfo;
		}


	int command; // 이동해야할 방향
	int count = 1;
	while (commandCount > 0) {
		commandCount--;
		count++;
		//scanf("%d ", &command); 왜 이건 한 번 더 실행할까??????
		cin >> command;
		//cout << "command: " << command << ", x: " << x << ", y: " << y << endl;
		if (move(command))
			printf("%d\n", dice[4]);
	}
	//system("PAUSE");
}