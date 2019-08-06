#include<iostream>
using namespace std;

int main() {
	/*
	���� �� �ִ� �ִ� ���� �����.
	if ���� �ο� >= K ... ��
	else (K - ���� �ο�)��ŭ�� ������ ������ ����ȯ��.
	*/
	int N, M, K;
	cin >> N >> M >> K;

	int team_count = 0;
	int max_team_for_N = N / 2;
	int max_team_for_M = M / 1;

	int left_N, left_M;
	int team_N, team_M;
	if (max_team_for_N >= max_team_for_M) {
		team_count = max_team_for_M;
		team_N = 2 * team_count;
		left_N = (N - 2 * team_count);
		team_M = team_count;
		left_M = (M - 1 * team_count);
	}
	else {
		team_count = max_team_for_N;
		team_N = 2 * team_count;
		left_N = (N - 2 * team_count);
		team_M = team_count;
		left_M = (M - 1 * team_count);
	}

	K -= (left_N + left_M);
	if (K <= 0)
		cout << team_count << endl;
	else if (K < 3)
		cout << team_count - 1 << endl;
	else if (K % 3 == 0)
		cout << team_count - (K / 3) << endl;
	else
		cout << team_count - (K / 3) - 1 << endl;
}