#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	cin >> N;

	const int MAX_N = 15;
	vector<pair<int, int>> vec [MAX_N + 1]; // day index에 소요 시간, 벌 수 있는 돈
	int day, money;
	for (int i = 1; i <= N; i++) {
		cin >> day >> money;
		vec[i].push_back(make_pair(day, money));
	}

	// maxMoney: index까지 벌 수 있는 돈
	int maxMoney[MAX_N + 1];
	for (int i = 0; i < MAX_N + 1; i++) {
		maxMoney[i] = 0;
	}

	pair<int, int> pair;
	int finishDay;
	int beforeMaxMoney = 0;
	for (int i = 1; i <= N; i++) {
		day = vec[i].at(0).first;
		money = vec[i].at(0).second;
		finishDay = i + day - 1;

		if (beforeMaxMoney > maxMoney[i])
			maxMoney[i] = beforeMaxMoney;
		
		// 시간 관계상 상담할 수 없음
		if (finishDay > N) {
			continue;
		}

		if (maxMoney[i - 1] + money > maxMoney[finishDay]) {
			maxMoney[finishDay] = maxMoney[i - 1] + money;
		}

		if (maxMoney[i] > beforeMaxMoney)
			beforeMaxMoney = maxMoney[i];

	}

	int totalMaxMoney = 0;
	for (int i = 1; i <= N ; i++) {
		if (maxMoney[i] > totalMaxMoney)
			totalMaxMoney = maxMoney[i];
	}

	cout << totalMaxMoney << endl;
}