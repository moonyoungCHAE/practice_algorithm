#include<iostream>
#include<string>
using namespace std;
/*
string���� ���ӵ� 0, 1�� �׷��� ���� �ߴ�.
ó������ ������ for������ ��ȸ�ϸ鼭 ������ ������, ������ ���̰� �� �� ����.
string�� find�� ��ü ���ڸ� ������ Ȯ������ �ʰ� ������ ����.
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
		if (checkOne) { // 0���� ������ ��, 0�� ������ ����.
			oneBundle++;
			input.erase(0, input.find('1'));
			if (input.find('1') > input.size())
				break;
			checkOne = false;
			checkZero = true;
		}
		else { // 1���� ������ ��, 1�� ������ ����.
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