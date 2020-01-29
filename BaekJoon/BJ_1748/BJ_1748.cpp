#include<iostream>
using namespace std;

int getDigit(int number) {
	int digit = 1;
	while (number >= 10) {
		number /= 10;
		digit++;
	}
	return digit;
}

// 입력한 digit 자리수의 총합
long long getDigitSum(int digit) {
	if (digit == 0)
		return 0;

	int minNumber = 1, maxNumber = 1;
	
	for (int i = 1; i <= digit - 1; i++)
		minNumber *= 10;
	
	maxNumber = minNumber * 10 - 1;

	return digit * (maxNumber - minNumber + 1);
}

// number의 자리수 전체가 아닌 number까지의 총합
long long getElseSum(int number, int digit) {
	int minNumber = 1;
	for (int i = 1; i < digit ; i++)
		minNumber *= 10;
	return digit * (number - minNumber + 1);
}

int main() {
	int inputNumber;
	scanf("%d", &inputNumber);

	int digit = getDigit(inputNumber);
	long long digitSum = 0;
	if (digit == 1)
		digitSum = getElseSum(inputNumber, digit);
	else {
		for (int i = 1; i <= digit - 1; i++) {
			digitSum += getDigitSum(i);
		}
		digitSum += getElseSum(inputNumber, digit);
	}

	printf("%d", digitSum);
}