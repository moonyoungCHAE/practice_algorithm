#include<iostream>
#include<string>
#include<stack>
using namespace std;

int getNum(string input, int num_start, int num_end) {
	int result = (int)input.at(num_start) - 48;
	for (int i = num_start + 1; i <= num_end; i++) {
		result *= 10;
		result += (int)input.at(i) - 48;
	}
	return result;
}

int main() {
	string input;
	cin >> input;

	stack<int> values;
	int num_start = 0;
	int now_value = 0;
	char flag;
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) != '+' && input.at(i) != '-')
			continue;

		now_value += getNum(input, num_start, i - 1);
		if (input.at(i) == '-') {
			values.push(now_value);
			now_value = 0;
			flag = '-';
		}
		else {
			flag = '+';
		}
		num_start = i + 1;
	}

	if (flag == '-') {
		values.push(getNum(input, num_start, input.length() - 1));
	}
	else if (values.empty()) {
		now_value += getNum(input, num_start, input.length() - 1);
		values.push(now_value);
	}
	else {
		now_value += getNum(input, num_start, input.length() - 1);
		values.push(now_value);
	}

	int result = 0;
	while (!values.empty()) {
		int value = values.top();
		values.pop();
		if (!values.empty()) {
			result -= value;
		}
		else {
			result += value;
			break;
		}
	}

	cout << result << endl;
}