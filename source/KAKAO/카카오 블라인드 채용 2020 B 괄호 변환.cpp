#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool check_true(string ans) {
	int char_check = 0;
	bool check = true;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == '(')
			char_check++;
		else
			char_check--;

		if (char_check < 0) {
			check = false;
			break;
		}
	}
	if (check == true)
		return true;
	else
		return false;
}

string recur_str(string p) {
	int check_zero = 0;
	string temp_u = "", temp_v = "";
	string temp_p = p;

	if (p == "")
		return string("");

	temp_u = "", temp_v = "";
	for (int i = 0; i < temp_p.size(); i++) {
		if (temp_p[i] == '(') {
			check_zero++;
			temp_u += temp_p[i];
		}
		else {
			check_zero--;
			temp_u += temp_p[i];
		}
		if (check_zero == 0) {
			temp_v = string(temp_p.begin() + (i+1), temp_p.end());
			break;
		}
	}

	if (check_true(temp_u)) {
		cout << "no" << " " << temp_v << endl;

		return string(temp_u + recur_str(temp_v) );
	}

	else {
		cout << "yes" << " " << temp_u << endl;
		string new_temp_u = "";
		for (int i = 1; i < temp_u.size() -1; i++) {
			if (temp_u[i] == '(')
				new_temp_u += ')';
			else
				new_temp_u += '(';
		}
		return string('(' + recur_str(temp_v) + ')' + new_temp_u);
	}
}
string solution(string p) {
	string answer = "";
	int check_zero = 0;
	string temp_u = "", temp_v = "";
	string temp_p = p;

	if (check_true(p))
		return p;

	answer = recur_str(p);

	return answer;
}

int main() {
	string a = "()))((()))(()(()";

	string ans = solution(a);
	
	cout << ans << endl;
	return 0;
}