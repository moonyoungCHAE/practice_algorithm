#include<iostream>
using namespace std;

/*
1. ������ �� �����ϱ� (�ٱ����� ũ�� - ���� �򰥸�)
2. ������ �� ������� ���� �ڵ� ¥�� (basketStart + M ... ���ٴ� basketEnd ���� �׳� �����)
*/
int main() {
	int N, M;
	cin >> N >> M;
	M -= 1;

	int basketStart = 1;
	int basketEnd = 1 + M;

	int appleCount;
	cin >> appleCount;
	
	int toatlMovement = 0;
	int appleLocation;
	for (int i = 0; i < appleCount; i++) {
		cin >> appleLocation;

		if (appleLocation < basketStart) {
			toatlMovement += (basketStart - appleLocation);
			basketStart = appleLocation;
			basketEnd = basketStart + M;
		}
		else if (appleLocation > basketEnd){
			toatlMovement += (appleLocation - basketEnd);
			basketEnd = appleLocation;
			basketStart = basketEnd - M;
		}
	}

	cout << toatlMovement << endl;
}