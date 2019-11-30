#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool desc(pair<double, int> a, pair<double, int> b) {
	if (a.first > b.first)
		return true;
	if (a.first < b.first)
		return false;
	if (a.second > b.second)
		return false;
	else
		return true;
	//	return a.first > b.first;
}

// N: stage의 개수 (1 ~ N까지)
// stages: 이용자들의 stage 정보
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<long> stagePlayer;
	vector<long> stageFailPlayer;
	stagePlayer.assign(N + 1, 0); // 0 ~ N까지 할당
	stageFailPlayer.assign(N + 1, 0);

	int nowStage;
	for (int i = 0; i < stages.size(); i++) {
		nowStage = stages.at(i);
		if (nowStage != N + 1)
			stageFailPlayer[nowStage]++;
		if (nowStage == N + 1)
			nowStage = N;
		for (int j = 1; j <= nowStage; j++) {
			stagePlayer[j]++;
		}
	}

	vector<pair<double, int>> info;
	for (int i = 1; i <= N; i++) {
		if (stagePlayer[i] == 0)
			info.push_back(make_pair(0.0, i));
		else
			info.push_back(make_pair(double(stageFailPlayer[i]) / double(stagePlayer[i]), i));
	}
	sort(info.begin(), info.end(), desc);
	for (int i = 0; i < N; i++) {
		answer.push_back(info.at(i).second);
	}
	return answer;
}