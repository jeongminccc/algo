#include <string.h>
#include <string>
#include <iostream>

using namespace std;

string str1arr[1010], str2arr[1010];
int solution(string str1, string str2) {
	const char * ptrstr1 = str1.c_str();
	const char * ptrstr2 = str2.c_str();

	int str1len = strlen(ptrstr1), str2len = strlen(ptrstr2);
	int temp_str1 = 0, temp_str2 = 0, temp_str1_b = 0, temp_str2_b = 0;
	int stp1 = 0, stp2 = 0;
	double count_intersection = 0, count_uni = 0;

	for (int i = 0; i < str1len; i++) {
		temp_str1 = ptrstr1[i];
		int plus = 0;
		if (temp_str1 >= 97 && temp_str1 <= 122)
			temp_str1 -= 32;
		if (temp_str1 >= 65 && temp_str1 <= 90) {
			temp_str1_b = ptrstr1[i + 1];
			if (temp_str1_b >= 97 && temp_str1_b <= 122) {
				temp_str1_b -= 32;
			}
			if (temp_str1_b >= 65 && temp_str1_b <= 90) {
				str1arr[stp1] = '0' + (temp_str1 - 48);
				str1arr[stp1++] += '0' + (temp_str1_b - 48);
			}
		}
	}
	for (int i = 0; i < str2len; i++) {
		temp_str2 = ptrstr2[i];
		int plus = 0;
		if (temp_str2 >= 97 && temp_str2 <= 122)
			temp_str2 -= 32;
		if (temp_str2 >= 65 && temp_str2 <= 90) {
			temp_str2_b = ptrstr2[i + 1];
			if (temp_str2_b >= 97 && temp_str2_b <= 122) {
				temp_str2_b -= 32;
			}
			if (temp_str2_b >= 65 && temp_str2_b <= 90) {
				str2arr[stp2] = '0' + (temp_str2 - 48);
				str2arr[stp2++] += '0' + (temp_str2_b - 48);
				for (int j = 0; j < stp1; j++) {
					if (str1arr[j] == str2arr[stp2 - 1]) {
						count_intersection++;
						str1arr[j] = '0';
					}
				}
			}
		}
	}
	/*for (int i = 0; i < str1len; i++) {
		cout << str1arr[i] << endl;
	}
	for (int i = 0; i < str1len; i++) {
		cout << str2arr[i] << endl;
	}*/

	count_uni = stp1 + stp2 - count_intersection;
	//cout << count_uni << " " << count_intersection << endl;
	double answer = 0;
	if (count_uni == 0)
		answer = 65536;
	else
		answer = (count_intersection / count_uni) * 65536;

	int ans_temp = answer;
	return ans_temp;
}