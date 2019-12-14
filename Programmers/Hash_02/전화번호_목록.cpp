#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = 0; j < phone_book.size(); j++) {
			if (i == j)
				continue;
			if (phone_book.at(i).size() > phone_book.at(j).size())
				continue;
			if (phone_book.at(j).find(phone_book.at(i)) == 0) {
				answer = false;
				return answer;
			}
		}
	}
	return answer;
}