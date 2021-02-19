#include <iostream>

using namespace std;

int Answer;
int arr1[5000];
int arr2[5000];

int count_number(int a, int b) {
	int answer = 0; a++; b--;
	while (a <= b) {
		if ((arr1[a] == arr2[b]) && (a != b))
			answer++;
		if ((arr1[b] == arr2[a]) && (a != b))
			answer++;
		else if (arr1[a] == arr2[b])
			answer++;
		a++;
		b--;
	}
	return answer;
}
int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int count, temp_answer=0, plus_answer=0, temp_plus_answer=0;
		cin >> count;
		int first = 0, end = count-1, temp_end=0;
		for (int i = 0; i < count; i++) {
			scanf_s("%d", &arr1[i]);
		}
		for (int i = 0; i < count; i++) {
			scanf_s("%d" , &arr2[i]);
		}
		while (first < end) {
			if (arr2[first] != arr1[first]) {
				temp_end = end;
				temp_plus_answer = 0;
				while (first<temp_end) {
					if (arr1[temp_end] == arr2[temp_end])
						temp_plus_answer++;
					if ( (arr2[temp_end] != arr1[temp_end]) && (arr1[first] == arr2[temp_end]) && (arr1[temp_end] == arr2[first]) ) {
						temp_answer = plus_answer + temp_plus_answer + count_number(first, temp_end) + 2;
						if (Answer <= temp_answer) {
							Answer = temp_answer;
						}
					}
					else if ((arr2[temp_end] != arr1[temp_end]) && (arr1[first] == arr2[temp_end]) ) {
						temp_answer = plus_answer + temp_plus_answer + count_number(first, temp_end) + 1;
						if (Answer <= temp_answer) {
							Answer = temp_answer;
						}
					}
					else if ((arr2[temp_end] != arr1[temp_end]) && (arr1[temp_end] == arr2[first])) {
						temp_answer = plus_answer + temp_plus_answer + count_number(first, temp_end) + 1;
						if (Answer <= temp_answer) {
							Answer = temp_answer;
						}
					}
					temp_end--;
					temp_answer = plus_answer + temp_plus_answer;
					if (Answer <= temp_answer) {
						Answer = temp_answer;
					}
				}
			}
			else
				plus_answer++;
			first++;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}