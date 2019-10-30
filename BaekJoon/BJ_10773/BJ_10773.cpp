#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> s;
	
	int K;
	cin >> K;
	int input;
	while (K > 0) {
		K--; 
		cin >> input;
		if (input != 0) {
			s.push(input);
		}
		if (input == 0 && !s.empty()) {
			s.pop();
		}
	}

	if (s.empty())
		cout << 0 << endl;
	else {
		int sum = 0;
		while (!s.empty()) {
			sum += s.top();
			s.pop();
		}
		cout << sum << endl;
	}
}