#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> check;
	// int: �ش� �̸����� ������ ����� ��

	for (int i = 0; i < completion.size(); i++) {
		check[completion.at(i)]++;
	}

	string answer = "";
	for (int i = 0; i < participant.size(); i++) {
		if (check[participant.at(i)] == 0) {
			answer = participant.at(i);
			break;
		}
		check[participant.at(i)]--;
	}
	return answer;
}