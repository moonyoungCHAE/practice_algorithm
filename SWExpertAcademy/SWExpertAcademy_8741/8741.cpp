#include<iostream>
#include<string>
using namespace std;


int main() {
	int T;
	cin >> T;

	string input;

	getline(cin, input);
	for(int tCount = 1; tCount <= T; tCount++){
		getline(cin, input);

		cout << "#" << tCount << " ";
		bool firstWord = true;
		for (int i = 0; i < input.size(); i++) {
			
			if (firstWord) {
				cout << char(toupper(input[i]));
				firstWord = false;
			}
			else if (input.at(i) == ' ') {
				firstWord = true;
			}
		}
		cout << endl;
	}
}