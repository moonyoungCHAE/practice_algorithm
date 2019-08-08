#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string input;
	cin >> input;

	vector <int> numbers;
	vector <char> operators;
	operators.push_back('+');
	for (int i = 0; i < input.size(); i++) {
		if (i % 2 == 0) {
			numbers.push_back(input.at(i));
		}
		if (i % 2 == 1) {
			operators.push_back(input.at(i));
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers.at(i) << " ";
	}
	cout << endl;
	int start_bracket = -1, end_bracket = -1;
	int bracket_num = 0;
	int total_sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (operators.at(i) == '-') {
			if (start_bracket == -1) {
				start_bracket = i;
				bracket_num += numbers.at(i);
			}
			else {
				total_sum -= bracket_num;
				total_sum -= numbers.at(i);
			}
		}else{
			if (start_bracket == -1)
				total_sum += numbers.at(i);
			else
				bracket_num += numbers.at(i);
		}
		cout << "total_sum : " << total_sum << " , bracket_num: " << bracket_num << endl;
	}


	cout << total_sum << endl;
	system("PAUSE");
}