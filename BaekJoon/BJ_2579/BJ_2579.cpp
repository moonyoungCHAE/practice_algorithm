#include<iostream>
using namespace std;

struct stairInfo {
	int value;
	int notContinuousSum; // 연결되는 것 1
	int continuousSum; // 연결되는 것 2
};

int getMax(int num1, int num2) {
	if (num1 > num2)
		return num1;
	else
		return num2;
}

/*
 Queue 만드니까 메모리 많이 잡아먹었음
*/

int main() {
	const int MAX_SIZE = 300;
	stairInfo stair[MAX_SIZE + 1];
	int stairSize;
	cin >> stairSize;

	for (int i = 1; i <= stairSize; i++) {
		cin >> stair[i].value;
	}

	stair[1].notContinuousSum = stair[1].value;
	stair[1].continuousSum = 0;

	stair[2].notContinuousSum = stair[2].value;
	stair[2].continuousSum = stair[1].value + stair[2].value;

	for (int i = 3; i <= stairSize; i++) {
		stair[i].continuousSum = stair[i - 1].notContinuousSum + stair[i].value;
		stair[i].notContinuousSum = getMax(stair[i - 2].continuousSum, stair[i - 2].notContinuousSum) + stair[i].value;
	}
	cout << getMax(stair[stairSize].continuousSum, stair[stairSize].notContinuousSum) << endl;
}
