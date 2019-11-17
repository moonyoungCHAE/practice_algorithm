#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	cin >> input;
	string alpa;
	char alpa_char = 'a';
	while (alpa_char != 'z') {
		alpa = "";
		alpa += alpa_char;
		if (input.find(alpa) != string::npos) {
			cout << input.find(alpa) << " ";
		}
		else {
			cout << "-1 ";
		}
		alpa_char = char(int(alpa_char) + 1);
	}
	// zÀÏ ¶§
	alpa = "";
	alpa += alpa_char;
	if (input.find(alpa) != string::npos) {
		cout << input.find(alpa) << " ";
	}
	else {
		cout << "-1 ";
	}
}