#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	cin >> input;

	int alpaCount[26];
	for (int i = 0; i < 26; i++) {
		alpaCount[i] = 0;
	}
	for (int i = 0; i < input.size(); i++) {
		alpaCount[int(input.at(i)) - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alpaCount[i] << " ";
	}
}