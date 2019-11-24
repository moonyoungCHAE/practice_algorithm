#include<iostream>
#include<stack>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	stack<pair<int, int>> stack_;

	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		
		while (stack_.size() > 0) {
			if (stack_.top().first > input) {
				printf("%d ", (stack_.top().second + 1));
				break;
			}
			stack_.pop();
		}
		if (stack_.size() == 0) {
			printf("0 ");
		}
		stack_.push(make_pair(input, i));
	}
}