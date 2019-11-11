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

// bracketStart: �迭�� �� index--> ������ ��ġ 1+(2 --> index 1
// totalNum: ��ü �������� ��, bTotalNum: ��ȣ �ȿ����� ��
void DFS(int totalNum, int index) {
	if (index >= input.size()) {
		if (totalNum > maxNum)
			maxNum = totalNum;
		return;
	}

	int newNum;
	// ��ȣ�� ��ġ�� ���
	newNum = calculate(totalNum, input.at(index + 1) - 48, input.at(index));
	DFS(newNum, index + 2);

	// ��ȣ�� ġ�� ���
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

	// ���ۺ��� ��ȣ�� ���� ���� ��
	DFS(input.at(0) - 48, 1);

	// ���ۺ��� ��ȣ�� �� ��
	if (N >= 5)
		DFS(calculate(input.at(0) - 48, input.at(2) - 48, input.at(1)), 3);
	cout << maxNum << endl;
}