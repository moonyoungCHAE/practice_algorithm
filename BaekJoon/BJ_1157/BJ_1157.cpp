#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<char, int> m;
	string input;
	cin >> input;


	for (int i = 0; i < input.size(); i++) {
		if (int(input.at(i)) >= 97) { // ¼Ò¹®ÀÚ
			input.at(i) = char(int(input.at(i)) - 32);
		}
		m[input.at(i)]++;
	}

	int maxCount = 0;
	char maxValue;
	bool duplicate = false;
	for (map<char, int>::iterator i = m.begin(); i != m.end(); i++) {
		if (i->second == maxCount) {
			duplicate = true;
		}
		if (i->second > maxCount) {
			maxCount = i->second;
			maxValue = i->first;
			duplicate = false;
		}
	}
	if (duplicate)
		cout << "?" << endl;
	else
		cout << maxValue << endl;
}