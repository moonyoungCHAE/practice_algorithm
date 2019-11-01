#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string input;
	cin >> input;

	stack<char> s;
	int totalCount = 0;
	for (int i = 0; i < input.size() - 1; i++) {
		if (input.at(i) == '(' && input.at(i + 1) == ')') {
			totalCount += s.size();
			i++;
		}
		else if (input.at(i) == '(') {
			s.push('(');
		}
		else { // )
			totalCount += 1;
			if (!s.empty())
				s.pop();
		}
	}

	cout << totalCount + s.size() << endl;
}