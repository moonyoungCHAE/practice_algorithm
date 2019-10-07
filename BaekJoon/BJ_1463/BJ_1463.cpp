#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}


	queue<int> q;
	q.push(N);

	int counting = 0;
	int nowNumber;
	bool findCounting = false;
	while (!findCounting) {
		int size = q.size();
		counting++;
		for (int i = 0; i < size; i++) {
			nowNumber = q.front();
			q.pop();
			if (nowNumber == 1) {
				findCounting = true;
				break;
			}
			if(nowNumber % 3 == 0)
				q.push(nowNumber / 3);
			if(nowNumber % 2 == 0)
				q.push(nowNumber / 2);
			q.push(nowNumber - 1);
		}
	}

	cout << counting - 1 << endl;
}