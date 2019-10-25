#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;

	string input[10];
	int sum[10];
	for (int tCount = 1; tCount <= T; tCount++) {
		for (int i = 0; i < 10; i++) {
			cin >> input[i];
			sum[i] = 0;
		}
		for (int i = 0; i < 10; i++) {
			sum[i] += count(input[i].begin(), input[i].end(), '1') * 1;
			sum[i] += count(input[i].begin(), input[i].end(), '2') * 2;
			sum[i] += count(input[i].begin(), input[i].end(), '3') * 3;
			sum[i] += count(input[i].begin(), input[i].end(), '4') * 4;
			sum[i] += count(input[i].begin(), input[i].end(), '5') * 5;
			sum[i] += count(input[i].begin(), input[i].end(), '6') * 6;
			sum[i] += count(input[i].begin(), input[i].end(), '7') * 7;
			sum[i] += count(input[i].begin(), input[i].end(), '8') * 8;
			sum[i] += count(input[i].begin(), input[i].end(), '9') * 9;
		}

		int max = -1, min = -1;
		for (int i = 0; i < 10; i++) {
			if (max == -1 || max < sum[i])
				max = sum[i];
			if (min == -1 || min > sum[i])
				min = sum[i];
		}
		cout << "#" << tCount << " " << max << " " << min << endl;
	}
}