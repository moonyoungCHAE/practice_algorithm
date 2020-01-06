#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<pair<int, int>> s;
	for (int i = 0; i < heights.size(); i++) {
		while (true) {
			if (s.size() == 0) {
				answer.push_back(0);
				break;
			}
			if (s.top().first > heights.at(i)) {
				answer.push_back(s.top().second);
				break;
			}
			s.pop();
		}
		s.push(make_pair(heights.at(i), i + 1));
	}
	return answer;
}