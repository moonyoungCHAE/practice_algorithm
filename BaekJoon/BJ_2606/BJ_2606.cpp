#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	const int MAX_COMPUTER_COUNT = 100;	
	int computerCount;
	int pairCount;

	cin >> computerCount >> pairCount;

	vector<int> vec[MAX_COMPUTER_COUNT + 1];
	int i, j;
	for (int nowPairCount = 0; nowPairCount < pairCount; nowPairCount++) {
		cin >> i >> j;
		vec[i].push_back(j);
		vec[j].push_back(i);
	}
	
	queue<int> q;
	for (int i = 0; i < vec[1].size(); i++) {
		q.push(vec[1][i]);
	}

	bool check[MAX_COMPUTER_COUNT + 1];
	for (int i = 0; i < MAX_COMPUTER_COUNT + 1; i++)
		check[i] = false;

	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();

		int nodeToCheck;
		for (int i = 0; i < vec[node].size(); i++) {
			nodeToCheck = vec[node][i];
			if (!check[nodeToCheck]) {
				q.push(nodeToCheck);
				check[nodeToCheck] = true;
			}
		}
		check[node] = true;
	}


	int count = 0;
	for (int i = 2; i <= computerCount; i++) {
		if (check[i])
			count++;
	}
	cout << count << endl;
}