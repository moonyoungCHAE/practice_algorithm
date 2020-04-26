#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack <int> s;
	int inputCount;
	cin >> inputCount;

	while (inputCount > 0) {
		inputCount--;

		string input;
		cin >> input;

		bool answer = true;
		for (int i = 0; i < input.size(); i++) {
			if (input.at(i) == '(')
				s.push(1);
			if (input.at(i) == ')') {
				if (s.empty()) {
					answer = false;
					break;
				}
				s.pop();
			}
			//cout << "size: " << s.size() << endl;
		}

		if (!s.empty())
			answer = false;

		if (answer)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("PAUSE");
}