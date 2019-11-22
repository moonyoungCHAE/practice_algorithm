#include<iostream>
#include<string>
using namespace std;

int main() {
	int totalInput;
	cin >> totalInput;

	int totalCount = 0;
	while (totalInput > 0) {
		totalInput--;

		string input;
		cin >> input;

		int alpa[26];
		for (int i = 0; i < 26; i++)
			alpa[i] = -1;

		char nowAlpa;
		bool groupword = true;
		for (int i = 0; i < input.size(); i++) {
			nowAlpa = input.at(i);
			if (alpa[int(nowAlpa) - 97] == -1) {
				alpa[int(nowAlpa) - 97] = i;
			}
			else if (alpa[int(nowAlpa - 97)] == i - 1) {
				alpa[int(nowAlpa) - 97] = i;
			}
			else {
				groupword = false;
				break;
			}
		}
		if (groupword)
			totalCount++;
	}
	cout << totalCount << endl;
}