#include<iostream>
using namespace std;

int main() {
	// 입력 및 초기화
	int moneyToPay;
	cin >> moneyToPay;

	int moneyToGet = 1000 - moneyToPay;
	int coins[] = { 500, 100, 50, 10, 5, 1 };


	// 가장 큰 동전 순으로, 해당 동전이 받아야하는 돈보다 클 때, 줄 수 있는 만큼 최대한 준다.
	int coinCount = 0;
	for (int i = 0; i < 6; i++) {
		if (moneyToGet >= coins[i]) {
			coinCount += (moneyToGet / coins[i]);
			moneyToGet -= ((moneyToGet / coins[i]) * coins[i]);
		}
	}

	cout << coinCount << endl;
}