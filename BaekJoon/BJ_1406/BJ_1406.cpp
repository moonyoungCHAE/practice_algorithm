#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
	stack<char> front;
	stack<char> back;


	// �ʱ�ȭ
	char input[100000];
	scanf("%s", input);

	int size = strlen(input);
	for (int i = 0; i < size; i++)
		front.push(input[i]);


	int commandCount;
	scanf("%d", &commandCount);

	char command;
	while (commandCount > 0) {
		commandCount--;
		scanf(" %c", &command);

		// back�� �ִ� ���� front�� �ش�.
		if (command == 'D' && !back.empty()) {
			front.push(back.top());
			back.pop();
		}

		// front�� �ִ� ���� back���� �ش�.
		else if (command == 'L' && !front.empty()) {
			back.push(front.top());
			front.pop();
		}

		else if (command == 'B' && !front.empty()) {
			front.pop();
		}

		else if (command == 'P') {
			char inputChar;
			scanf(" %c", &inputChar);
			front.push(inputChar);
		}
	}


	while (!front.empty()) {
		back.push(front.top());
		front.pop();
	}

	while (!back.empty()) {
		printf("%c", back.top());
		back.pop();
	}
}