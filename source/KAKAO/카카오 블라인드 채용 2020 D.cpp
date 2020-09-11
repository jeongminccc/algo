#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<vector<string>> arr;
	vector<string> temp_arr;
	string temp_str;
	int temp_int = 0, str_int=0;
	vector<int> answer;

	sort(words.begin(), words.end());
	
	for (int i = 1; i <= 10000; i++) {
		vector<string> temp_arr;
		arr.push_back(temp_arr);
	}

	int temp_num = 0;

	for (int i = 0; i < words.size(); i++) {
		temp_int = words[i].size();
		arr[temp_int].push_back(words[i]);
	}


	for (int i = 0; i < queries.size(); i++) {
		temp_int = queries[i].size();
		if (queries[i][0] == '?') {
			int k = 0;
			while (1) {
				if (queries[i][k] != '?')
					break;
				else
					k++;
			}
			temp_str = string(queries[i].begin() + k, queries[i].end());
			int temp_ans = 0;
			for (int j = 0; j < arr[temp_int].size(); j++) {
				if (temp_str == string(arr[temp_int][j].begin() + k, arr[temp_int][j].end()))
					temp_ans++;
			}
			answer.push_back(temp_ans);
		}
		else {
			str_int = queries[i].find("?");
			temp_str = string(queries[i].begin(), queries[i].begin() + str_int);
			int temp_ans = 0;
			for (int j = 0; j < arr[temp_int].size(); j++) {
				if (temp_str == string(arr[temp_int][j].begin(), arr[temp_int][j].begin() + str_int)){

					cout << temp_str << " " << arr[temp_int][j] << endl;
					temp_ans++;
				}
			}
			answer.push_back(temp_ans);
		}
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	return answer;
}

int main() {
	vector<string> a = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> b = { "fro??", "????o", "fr???", "fro???", "pro?"};

	vector<int> ans = solution(a,b);
	
	return 0;
}