#include<iostream>
#include<vector>
using namespace std;

int main() {
	int TEST_CASE;
	cin >> TEST_CASE;

	const int MAX_SIZE = 40;
	vector<pair<int, int>> counts; // 0 count, 1 count
	
	counts.push_back(make_pair(1, 0));
	counts.push_back(make_pair(0, 1));

	int N;
	while (TEST_CASE > 0) {
		TEST_CASE--;

		cin >> N;

		if (N < counts.size()) {
			cout << counts.at(N).first << " " << counts.at(N).second << endl;
			continue;
		}

		int nowNumber = counts.size(); // 이제 추가할 숫자
		int zeroCount, oneCount;
		while (counts.size() - 1 < N) {
			zeroCount = counts[nowNumber - 1].first + counts[nowNumber - 2].first;
			oneCount = counts[nowNumber - 1].second + counts[nowNumber - 2].second;
			counts.push_back(make_pair(zeroCount, oneCount));
			nowNumber++;
		}
		cout << counts.at(N).first << " " << counts.at(N).second << endl;
	}
}