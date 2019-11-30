#include <string>
#include <vector>
#include<sstream>
#include<map>

using namespace std;

string getId(string str) {
	char delimiter = ' ';
	stringstream ss(str);
	string temp;

	int i = 0;
	while (getline(ss, temp, delimiter))
	{
		if (i == 1)
			return temp;
		i++;
	}
}

string getNickname(string str) {
	char delimiter = ' ';
	stringstream ss(str);
	string temp;

	int i = 0;
	while (getline(ss, temp, delimiter))
	{
		if (i == 2)
			return temp;
		i++;
	}
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> nicknameInfo;

	// 이름 찾기
	for (int i = 0; i < record.size(); i++) {
		if (record.at(i).find("Leave") == 0) {
			continue;
		}
		nicknameInfo[getId(record.at(i))] = getNickname(getNickname(record.at(i)));
	}

	for (int i = 0; i < record.size(); i++) {
		if (record.at(i).find("Change") == 0) {
			continue;
		}
		string nickname = nicknameInfo[getId(record.at(i))];
		if (record.at(i).find("Enter") == 0) {
			answer.push_back(nickname.append("님이 들어왔습니다."));
		}
		if (record.at(i).find("Leave") == 0) {
			answer.push_back(nickname.append("님이 나갔습니다."));
		}

	}

	return answer;
}