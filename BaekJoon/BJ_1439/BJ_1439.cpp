#include<iostream>
#include<string>
using namespace std;
/*
string에서 연속된 0, 1의 그룹을 세야 했다.
처음부터 끝까지 for문으로 순회하면서 세려고 했지만, 문자의 길이가 길 때 문제.
string의 find로 전체 문자를 일일이 확인하지 않고 묶음을 셌음.
*/
int main() {
	string input;
	cin >> input;

	int oneBundle = 0, zeroBundle = 0;
	bool checkOne = false, checkZero = false;

	if (input.at(0) == '0')
		checkOne = true;
	else
		checkZero = true;

	while (input.size() > 0) {
		if (checkOne) { // 0부터 시작할 때, 0의 개수를 센다.
			oneBundle++;
			input.erase(0, input.find('1'));
			if (input.find('1') > input.size())
				break;
			checkOne = false;
			checkZero = true;
		}
		else { // 1부터 시작할 때, 1의 개수를 센다.
			zeroBundle++;
			input.erase(0, input.find('0'));
			if (input.find('0') > input.size())
				break;
			checkZero = false;
			checkOne = true;
		}
	}

	if (oneBundle >= zeroBundle) {
		cout << zeroBundle << endl;
	}
	else {
		cout << oneBundle << endl;
	}

}