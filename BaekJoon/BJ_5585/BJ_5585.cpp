#include<iostream>
using namespace std;

int main() {
	// �Է� �� �ʱ�ȭ
	int moneyToPay;
	cin >> moneyToPay;

	int moneyToGet = 1000 - moneyToPay;
	int coins[] = { 500, 100, 50, 10, 5, 1 };


	// ���� ū ���� ������, �ش� ������ �޾ƾ��ϴ� ������ Ŭ ��, �� �� �ִ� ��ŭ �ִ��� �ش�.
	int coinCount = 0;
	for (int i = 0; i < 6; i++) {
		if (moneyToGet >= coins[i]) {
			coinCount += (moneyToGet / coins[i]);
			moneyToGet -= ((moneyToGet / coins[i]) * coins[i]);
		}
	}

	cout << coinCount << endl;
}