#include<iostream>
#include<string>
using namespace std;

int main() {
	// 입력
	string standardWords;
	string compareWords;
	cin >> compareWords >> standardWords;

	// 앞/뒤로 넣을 수 있는 모든 경우 넣는다.
	// compareWords에 추가로 넣는 글자는 standardWords와 같은 글자로 넣는다고 가정
	string nowWords;
	int minDiff = 100;
	for (int i = 0; i < (standardWords.length() - compareWords.length() + 1); i++) {
		int nowDiff = 0;
		for (int j = 0; j < compareWords.length(); j++) {
			if (compareWords.at(j) != standardWords.at(i + j))
				nowDiff++;
		}

		if (minDiff > nowDiff)
			minDiff = nowDiff;
	}

	cout << minDiff << endl;
}