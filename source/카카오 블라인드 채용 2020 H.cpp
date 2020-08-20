#include <string>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 1;
	sort(dist.begin(), dist.end(), greater<int>());
	int dist_index = 0;
	int weak_temp = 0;
	int weak_index = 0;

	while (weak_index < weak.size()) {
		while (dist[dist_index] >= weak_temp) {
			weak_temp += weak[weak_index + 1] - weak[weak_index];
			weak_index++;
		}
		weak_temp = 0;
		dist_index++;
		if (weak.size() - 1 == weak_index)
			break;
		answer += 1;
	}

	cout << answer << endl;
	return answer;
}

int main() {
	vector<int> a = { 1, 5, 6, 10 };
	vector<int> b = { 1, 2, 3, 4 };
	int n = 12;

	int ans = solution(12, a,b);
	
	return 0;
}