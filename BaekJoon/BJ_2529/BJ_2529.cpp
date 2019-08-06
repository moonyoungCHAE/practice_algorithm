#include<iostream>
using namespace std;
// 최소, 최대 초기화 잘못해서 삽질함! > min, max값 조건문에 초기값도 확인해줄 것
// int 값 초과 > long long으로 변경!! (10자리 int 못쓴다.)
int K;
long long minNumber = 1, maxNumber = -1;
bool checked[10] = { false, };

void checkInequality(int before_number, int thIndex, long long nowNumber, char * inequality) {
	if (thIndex > K + 1)
		return;
	if (thIndex == K + 1) {
		if (nowNumber < minNumber || minNumber == 1)
			minNumber = nowNumber;
		if (nowNumber > maxNumber || maxNumber == -1)
			maxNumber = nowNumber;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (checked[i])
			continue;
		if ((inequality[thIndex - 1] == '<') && (before_number < i)) {
			checked[i] = true;
			checkInequality(i, thIndex + 1, nowNumber * 10 + i, inequality);
			checked[i] = false;
		}

		if ((inequality[thIndex - 1] == '>') && (before_number > i)) {
			checked[i] = true;
			checkInequality(i, thIndex + 1, nowNumber * 10 + i, inequality);
			checked[i] = false;
		}
	}
}

int main() {
	cin >> K;

	char * inequality = new char[K];
	for (int i = 0; i < K; i++)
		cin >> inequality[i];

	for (int i = 0; i < 10; i++) {
		checked[i] = true;
		checkInequality(i, 1, i, inequality);
		checked[i] = false;
	}

	int digits = 1;
	for (int i = 0; i < K; i++)
		digits *= 10;

	if (maxNumber / digits == 0)
		cout << 0;
	cout << maxNumber << endl;

	if (minNumber / digits == 0)
		cout << 0;
	cout << minNumber << endl;

}