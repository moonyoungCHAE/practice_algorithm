#include<iostream>
#include<stack>
using namespace std;
/*
	hard coding 같아보여도, Queue 사용하는 것보다 비교대상이 적다면 그냥 변수 사용하는 것이 낫다.
	제출 형식 체크하기
*/
int getMax(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	for (int k = 1; k <= 10; k++) {
		int tCount;
		cin >> tCount;

		int count = 0;

		int input;

		int standard = 0, before = 0, before_before = 0, next = 0, next_next = 0;
		for (int i = 0; i < tCount; i++) {
			cin >> input;
			before_before = before;
			before = standard;
			standard = next;
			next = next_next;
			next_next = input;

			int max_under_standard = -1;
			max_under_standard = getMax(max_under_standard, before_before);
			max_under_standard = getMax(max_under_standard, before);
			max_under_standard = getMax(max_under_standard, next);
			max_under_standard = getMax(max_under_standard, next_next);
			if (max_under_standard < standard)
				count += (standard - max_under_standard);
		}

		// i - 2
		int max_under_standard = -1;
		int standard_ = next;
		int next_ = next;
		int before_ = standard;
		int before_before_ = before;
		max_under_standard = getMax(max_under_standard, before_);
		max_under_standard = getMax(max_under_standard, before_before_);
		max_under_standard = getMax(max_under_standard, next_);
		if (max_under_standard < standard_)
			count += (standard_ - max_under_standard);


		// i - 1
		max_under_standard = -1;
		standard_ = next_next;
		before_ = next;
		before_before_ = standard;
		max_under_standard = getMax(max_under_standard, before_);
		max_under_standard = getMax(max_under_standard, before_before_);

		if (max_under_standard < standard_)
			count += (standard_ - max_under_standard);
		cout << "#" << k << " " << count << endl;
	}
}