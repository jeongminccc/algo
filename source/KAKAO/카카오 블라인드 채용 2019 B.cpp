#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int stage_fail[510] = { 0 };
int stage_try[510] = { 0 };

bool compare(pair<double, int> &a, pair<double, int> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<double, int>> fail_percent;

	for (int i = 0; i < stages.size(); i++) {
		for (int j = 1; j <= stages[i]; j++) {
			stage_try[j]++;
		}
		stage_fail[stages[i]]++;
	}
	for (int i = 1; i <= N; i++) {
		if (stage_try[i] == 0) {
			fail_percent.push_back({ 0,i });
		}
		else {
			fail_percent.push_back({ (double)stage_fail[i] / stage_try[i], i });
		}
	}
	sort(fail_percent.begin(), fail_percent.end(), compare);

	for (int i = 0; i < N; i++) {
		answer.push_back(fail_percent[i].second);
	}

	return answer;
}
