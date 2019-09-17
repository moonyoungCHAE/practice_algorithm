#include<iostream>
using namespace std;

/*
1. 문제를 잘 이해하기 (바구니의 크기 - 개수 헷갈림)
2. 변수를 더 만들더라도 쉽게 코드 짜기 (basketStart + M ... 보다는 basketEnd 변수 그냥 만들기)
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