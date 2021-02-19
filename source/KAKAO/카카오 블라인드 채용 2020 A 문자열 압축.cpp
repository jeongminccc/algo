#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	vector<int> ans;
	string before_string, temp_string;
	bool check = false;
	int temp_answer = 0;
	int count_digit = 0;

	if (s.size() == 1)
		return 1;

	for (int i = 1; i <= 500; i++) {
		if (s.size() >= i * 2){
			cout << endl << i ;
			check = false;
			temp_answer = 0;
			count_digit = 1;
			for (int j = 0; j < s.size(); j += i) {
				if (j + i > s.size()) {
					temp_answer += s.size() - j;
					break;
				}
				if (j == 0) {
					before_string = string(s.begin(), s.begin() + (i));
					temp_answer = i;
				}
				else {
					if (before_string == string(s.begin() + j, s.begin() + (j + i))) {
						if (check == false) {
							temp_answer += 1;
							check = true;
						}
						else {
							if (count_digit == 9 || count_digit == 99 || count_digit == 999)
								temp_answer += 1;
						}
						count_digit += 1;
					}
					else {
						temp_answer += i;
						check = false;
						count_digit = 1;
					}
					before_string = string(s.begin() + j, s.begin() + (j + i));
				}
				cout << " " << before_string ;
			}
			cout << temp_answer << " " << count_digit; 
			ans.push_back(temp_answer);
		}
		else if (s.size() < i * 2) 
			break;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	sort(ans.begin(), ans.end());
	answer = ans[0];

	return answer;
}

int main() {
	string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	
	int ans = solution(a);
	
	cout << ans << endl;
	return 0;
}