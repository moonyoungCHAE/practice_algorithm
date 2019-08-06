#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> info;
vector<int> line;
bool checked[11] = { false, };

// 가능한 모든 경우에 대해 해당 번호에 적합한지 확인 후 적합 시 계속 진행
void search(int index) {
	if (index > N)
		return;
	if (index == N) {
		for (int i = 0; i < line.size(); i++)
			cout << line.at(i) << " ";
		cout << endl;
	}

	for (int i = 1; i <= N; i++) {
		if (checked[i])
			continue;
		int count = 0;
		for (int j = 0; j < line.size(); j++) {
			if (line.at(j) > i)
				count++;
		}
		if (count == info.at(i - 1)) {
			line.push_back(i);
			checked[i] = true;
			search(index + 1);
			if (!line.empty())
				line.pop_back();
			checked[i] = false;
		}
	}

}

int main() {
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		info.push_back(input);
	}

	search(0);
}