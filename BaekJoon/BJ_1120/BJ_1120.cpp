#include<iostream>
#include<string>
using namespace std;

int main() {
	// �Է�
	string standardWords;
	string compareWords;
	cin >> compareWords >> standardWords;

	// ��/�ڷ� ���� �� �ִ� ��� ��� �ִ´�.
	// compareWords�� �߰��� �ִ� ���ڴ� standardWords�� ���� ���ڷ� �ִ´ٰ� ����
	string nowWords;
	int minDiff = 100;
	for (int i = 0; i < (standardWords.length() - compareWords.length() + 1); i++) {
		int nowDiff = 0;
		for (int j = 0; j < compareWords.length(); j++) {
			if (compareWords.at(j) != standardWords.at(i + j))
				nowDiff++;
		}

		if (minDiff > nowDiff)
			minDiff = nowDiff;
	}

	cout << minDiff << endl;
}