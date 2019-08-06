#include<iostream>
#include<vector>
using namespace std;

int main() {
	// [�Է�]
	int N, K; // N: ������ ����, K: ���� �������� ������� �ϴ� ���� ��
	cin >> N >> K;

	int input;
	vector<int> coin;
	for (int i = 0; i < N; i++) {
		cin >> input;
		coin.push_back(input);
	}

	int moneySum = 0;
	int moneyCount = 0;
	int moneyToPush = K;
	// �ڿ������� ���� ����. 
	// �� �־���ϴ� ���� �ش� ���� ������ ũ��, �߰��� �� �ִ� ��ŭ �ִ´�.
	for (int i = N - 1; i >= 0; i--) {
		if (moneySum == K)
			break;
		if ((moneyToPush / coin.at(i)) >= 0) {
			moneySum += coin.at(i) * (moneyToPush / coin.at(i));
			moneyCount += (moneyToPush / coin.at(i));
			moneyToPush -= coin.at(i) * (moneyToPush / coin.at(i));
		}
	}

	cout << moneyCount << endl;
}