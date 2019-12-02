#include<iostream>
using namespace std;

int main() {
	int E;
	int S;
	int M;

	const int MAX_E = 15;
	const int MAX_S = 28;
	const int MAX_M = 19;

	int inputE;
	int inputS;
	int inputM;
	 
	cin >> inputE >> inputS >> inputM;

	E = 1;
	S = 1;
	M = 1;
	int year = 1;
	while (true) {
		if (E == inputE && S == inputS && M == inputM)
			break;
		
		year++;
		E++;
		S++;
		M++;
		if (E > MAX_E)
			E = 1;
		if (S > MAX_S)
			S = 1;
		if (M > MAX_M)
			M = 1;
	}
	cout << year << endl;
}