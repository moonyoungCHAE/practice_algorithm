#include<iostream>
using namespace std;

struct DataInfo {
	int oneCount;
	int zero1Count;
	int zero2Count;
};

int main() {
	const int MAX_SIZE = 1000000;
	int totalSize;
	cin >> totalSize;

	DataInfo * dataInfo = new DataInfo[MAX_SIZE + 1];
	dataInfo[0].oneCount = 0;
	dataInfo[0].zero1Count = 0;
	dataInfo[0].zero2Count = 0;
	
	dataInfo[1].oneCount = 1;
	dataInfo[1].zero1Count = 1;
	dataInfo[1].zero2Count = 0;
	
	for (int i = 2; i <= totalSize; i++) {
		dataInfo[i].oneCount = dataInfo[i - 1].oneCount + dataInfo[i - 1].zero2Count;
		dataInfo[i].zero1Count = dataInfo[i - 1].oneCount + dataInfo[i - 1].zero2Count;
		dataInfo[i].zero2Count = dataInfo[i - 1].zero1Count;
		if (dataInfo[i].oneCount > 15746)
			dataInfo[i].oneCount %= 15746;
		if (dataInfo[i].zero1Count > 15746)
			dataInfo[i].oneCount %= 15746;
		if (dataInfo[i].zero2Count > 15746)
			dataInfo[i].zero2Count %= 15746;
	}
	
	int totalCount = dataInfo[totalSize].oneCount + dataInfo[totalSize].zero2Count;
	cout << totalCount % 15746 << endl;

}