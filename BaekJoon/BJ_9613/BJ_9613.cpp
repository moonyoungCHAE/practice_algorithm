#include<iostream>
#include<vector>
using namespace std;

// 입력으로 주어지는 수는 1000000을 넘지 않는다.
// ㄴ 을 보고, gcd의 총합의 데이터 타입을 int에서 long long으로 수정함

int getGCD(int a, int b) {
	// a < b로 만든다.
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}

	for (int gcd = a; gcd >= 1; gcd--) {
		if (a % gcd == 0 && b % gcd == 0)
			return gcd;
	}
	return 1;
}

// 가능한 모든 쌍의 최대공약수의 합
int main() {
	int T;
	cin >> T;

	vector<int> num;
	while (T > 0) {
		T--;
		
		int numSize;
		cin >> numSize;

		num.clear();
		for (int i = 0; i < numSize; i++) {
			int input;
			cin >> input;
			num.push_back(input);
		}

		long long totalGCD = 0;
		for (int i = 0; i < num.size(); i++) {
			for (int j = i + 1; j < num.size(); j++) {
				totalGCD += getGCD(num[i], num[j]);
			}
		}
		cout << totalGCD << endl;
	}
	system("PAUSE");
}