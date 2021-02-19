#include <iostream>
#include <string>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	const char * lenchar;
	lenchar = dartResult.c_str();
	int length = strlen(lenchar);
	char tempChar;
	int tempInt, tempAns=0, temp_before=0;
	for (int i = 0; i < length; i++) {
		tempChar = dartResult[i];
		tempInt = tempChar;
		if (tempInt >= 48 && tempInt <= 58) {
			if (tempInt == 49) {
				tempChar = dartResult[i + 1];
				tempInt = tempChar;
				if (tempInt == 48) {
					tempInt = 58;
					i++;
				}
				else
					tempInt = 49;
			}
			temp_before = tempAns;
			cout << tempAns << endl;
			answer += tempAns;
			tempAns = (tempInt - 48);
		}
		else if (tempChar == 'S' || tempChar == 'T' || tempChar == 'D') {
			if (tempChar == 'D') {
				tempAns = tempAns * tempAns;
			}
			else if (tempChar == 'T')
				tempAns = tempAns * tempAns * tempAns;
		}
		else if (tempChar == '*') {
			answer += temp_before;
			tempAns = tempAns * 2;
		}
		else if (tempChar == '#') {
			tempAns = tempAns * (-1);
		}
	}
	answer += tempAns;
	return answer;
}

int main() {
	string abc;
	int ans;
	cin >> abc;
	
	ans = solution(abc);
	cout << ans;
}