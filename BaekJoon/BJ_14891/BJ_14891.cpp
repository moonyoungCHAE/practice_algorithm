﻿// 14891
#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;

deque<int> gear[4];
bool rotated[4];

// 0, 1, 2, 3
bool isPossibleIndex(int index) {
	if (index < 0)
		return false;
	if (index >= 4)
		return false;
	return true;
}


void rotate(int rotateGearIndex, int rotateDirection) {
	rotated[rotateGearIndex] = true;
	int leftIndex = rotateGearIndex - 1;
	int rightIndex = rotateGearIndex + 1;

	// 왼, 오 회전할지 여부 확인
	if (isPossibleIndex(leftIndex)
		&& !rotated[leftIndex]
		&& gear[leftIndex].at(2) != gear[rotateGearIndex].at(6)) {
		rotate(leftIndex, rotateDirection * -1);
	}
	if (isPossibleIndex(rightIndex)
		&& !rotated[rightIndex]
		&& gear[rightIndex].at(6) != gear[rotateGearIndex].at(2)){
		rotate(rightIndex, rotateDirection * -1);
	}

	// 시계 방향
	if (rotateDirection == 1) {
		gear[rotateGearIndex].push_front(gear[rotateGearIndex].at(gear[rotateGearIndex].size() -1));
		gear[rotateGearIndex].pop_back();
	}
	if (rotateDirection == -1) {
		gear[rotateGearIndex].push_back(gear[rotateGearIndex].at(0));
		gear[rotateGearIndex].pop_front();
	}
}

int getScore() {
	int score = 0;
	if (gear[0].at(0) == 1)
		score += 1;

	if (gear[1].at(0) == 1)
		score += 2;

	if (gear[2].at(0) == 1)
		score += 4;

	if (gear[3].at(0) == 1)
		score += 8;
	return score;
}

int main() {
	// 입력
	int input;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &input);
		for (int j = 0; j < 8; j++){
			gear[i].push_front(input % 10);
		input /= 10;
		}
	}

	int K;
	scanf("%d", &K);

	int rotateGearIndex, rotateDirection; // 1: 시계방향, -1: 반시계방향
	while (K > 0) {
		K--;
		scanf("%d %d", &rotateGearIndex, &rotateDirection);
		for (int i = 0; i < 4; i++)
			rotated[i] = false;
		rotateGearIndex--;
		rotate(rotateGearIndex, rotateDirection);
	}
	printf("%d", getScore());

}