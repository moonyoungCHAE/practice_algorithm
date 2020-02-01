// 6588
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
using namespace std;

const int MAX_N = 1000000;
bool decimal[MAX_N + 1];

bool isDecimal(int number) {
	if (number <= 1)
		return false;
	int checkNumber = 2;
	while (checkNumber <= sqrt(number)) {
		if (number % checkNumber == 0) {
			return false;
		}
		checkNumber++;
	}
	return true;
}

void checkGoldbachConjecture(int number) {
	int numberA, numberB;
	for (int checkNumber = 3; checkNumber <= (number/2); checkNumber += 2) {
		if (!decimal[checkNumber]) // 소수가 아닐 때
			continue;
		numberA = checkNumber;
		numberB = number - numberA;

		if (decimal[numberB]) {
			if (numberA > numberB) {
				int temp = numberA;
				numberA = numberB;
				numberB = temp;
			}

			printf("%d = %d + %d \n", number, numberA, numberB);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong.");
}

int main() {
	// 초기화
	memset(decimal, false, sizeof(decimal));

	for (int i = 1; i <= MAX_N; i++) {
		if (i % 2 == 0)
			decimal[i] = false;
		else
			decimal[i] = isDecimal(i);
	}

	// 변수 검증
	int inputNumber;
	while (true) {
		scanf("%d", &inputNumber);
		if (inputNumber == 0)
			break;
		checkGoldbachConjecture(inputNumber);
	}
}