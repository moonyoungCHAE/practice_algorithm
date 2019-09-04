#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	int tCount = 1;
	while (tCount <= T) {
		int factorCount;
		cin >> factorCount;

		vector<int> factors;
		for (int i = 0; i < factorCount; i++) {
			int input;
			cin >> input;
			factors.push_back(input);
		}

		sort(factors.begin(), factors.end());
	
		int result = (factors.at(0) * factors.at(factorCount - 1));

		cout << "#" << tCount << " " << result << endl;
		tCount++;
	}
}