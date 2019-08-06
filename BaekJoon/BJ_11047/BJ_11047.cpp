#include<iostream>
#include<vector>
using namespace std;

int main() {
	// [입력]
	int N, K; // N: 동전의 종류, K: 동전 조합으로 만들고자 하는 돈의 합
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
	// 뒤에서부터 돈을 센다. 
	// 더 넣어야하는 돈이 해당 동전 값보다 크면, 추가할 수 있는 만큼 넣는다.
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