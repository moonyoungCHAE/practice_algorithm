#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	int truckIndex = 0;
	int nowWeight = 0;
	queue<pair<int, int>> q; // 트럭 index와 시작 시간을 저장

	while (true) {
		if (q.size() != 0 && q.front().second + bridge_length <= answer) {
			nowWeight -= truck_weights.at(q.front().first);
			q.pop();
		}
		if (truckIndex < truck_weights.size()
			&& nowWeight + truck_weights.at(truckIndex) <= weight) {
			q.push(make_pair(truckIndex, answer));
			nowWeight += truck_weights.at(truckIndex);
			truckIndex++;
		}
		if (q.size() == 0)
			break;
		answer++;
	}
	return answer;
}