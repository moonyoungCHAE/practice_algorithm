#include<iostream>
#include<string>
using namespace std;

string input;
int maxNum = -9999;
int calculate(int a, int b, char calcul) {
	if (calcul == '+')
		return a + b;
	if (calcul == '-')
		return a - b;
	if (calcul == '*')
		return a * b;
	if (calcul == '/')
		return a / b;
}

// bracketStart: 배열을 연 index--> 연산자 위치 1+(2 --> index 1
// totalNum: 전체 진행중인 값, bTotalNum: 괄호 안에서의 값
void DFS(int totalNum, int index) {
	if (index >= input.size()) {
		if (totalNum > maxNum)
			maxNum = totalNum;
		return;
	}

	int newNum;
	// 괄호를 안치는 경우
	newNum = calculate(totalNum, input.at(index + 1) - 48, input.at(index));
	DFS(newNum, index + 2);

	// 괄호를 치는 경우
	int newSize = input.size() - 4;
	if (index <= newSize) {
		newNum = calculate(input.at(index + 1) - 48, input.at(index + 3) - 48, input.at(index + 2));
		newNum = calculate(totalNum, newNum, input.at(index));
		DFS(newNum, index + 4);
	}
}

int main() {
	int N;
	cin >> N;
	cin >> input;

	// 시작부터 괄호를 하지 않을 때
	DFS(input.at(0) - 48, 1);

	// 시작부터 괄호를 할 때
	if (N >= 5)
		DFS(calculate(input.at(0) - 48, input.at(2) - 48, input.at(1)), 3);
	cout << maxNum << endl;
}