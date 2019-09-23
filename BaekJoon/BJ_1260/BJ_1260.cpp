#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

const int MAX_SIZE = 1000;
vector<int> vec[MAX_SIZE + 1];
bool check[MAX_SIZE + 1];
queue<int> q;
vector<int> result;
stack<int> s;

void bfs(int start) {
	q.pop();
	if(!check[start])
		result.push_back(start);
	check[start] = true;

	for (int i = 0; i < vec[start].size(); i++) {
		if (!check[vec[start][i]])
			q.push(vec[start][i]);
	}

	if (!q.empty()) {
		return bfs(q.front());
	}
}

void dfs(int start) {
	result.push_back(start);
	check[start] = true;
	for (int i = 0; i < vec[start].size(); i++) {
		if (!check[vec[start][i]]) {
			dfs(vec[start][i]);
		}
	}
	if (!s.empty()) {
		s.pop();
	}
	if (!check[start]) {
		result.push_back(start);
	}
}
int main() {
	int N, M, start;
	cin >> N >> M >> start;


	int input_a, input_b;
	for (int i = 0; i < M; i++) {
		cin >> input_a >> input_b;
		vec[input_a].push_back(input_b);
		vec[input_b].push_back(input_a);
	}

	for (int i = 1; i <= N; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	for (int i = 0; i < MAX_SIZE + 1; i++)
		check[i] = false;

	s.push(start);
	dfs(start);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;


	for (int i = 0; i <= N; i++) {
		check[i] = false;
	}
	result.clear();
	q.push(start);
	bfs(start);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}