#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	cin >> input;


	int counting = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input.find("c=", i) == i) {
			i += 1;
		}

		if (input.find("c-", i) == i) {
			i += 1;
		}

		if (input.find("dz=", i) == i) {
			i += 2;
		}

		if (input.find("d-", i) == i) {
			i += 1;
		}

		if (input.find("lj", i) == i) {
			i += 1;
		}

		if (input.find("nj", i) == i) {
			i += 1;
		}

		if (input.find("s=", i) == i) {
			i += 1;
		}

		if (input.find("z=", i) == i) {
			i += 1;
		}
		counting++;
	}

	cout << counting << endl;
}