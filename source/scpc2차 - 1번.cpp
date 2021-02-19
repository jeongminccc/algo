#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int Answer;
bool prime;
int power[4] = { 10, 100, 1000, 10000 };
string str[5];
char sum_str[5];

void check_prime(int number) {
	prime = false;
	int check = 2;
	if (number <= 1) {
		return; // no prime
	}
	while (1) {
		if ((check*check) > number) {
			prime = true;
			break;
		}
		if (number % check == 0) {
			return;
		}
		check++;
	}
}

int count(int num, int dec) {
	int answer = 0;
	sum_str[0] = '\0';
	for (int i = 1; i <= dec; i++) {
		str[0] = '\0';
		string str = to_string(num);
		check_prime(num);
		if (prime) {
			if (answer <= 0)
				answer = 1;
			str[i - 1] = '0';
			int k = 0;
			for (int i = 0; i < 5; i++) {
				sum_str[i] = '\0';
			}
			for (int j = 0; j <= dec - 1; j++) {
				if (str[j] != '0') {
					sum_str[k] = str[j];
					k++;
				}
			}
			int num2 = atoi(sum_str);
			check_prime(num2);
			if (prime) {
				if (answer <= 1)
					answer = 2;
				for (int j = 1; j <= dec - 1; j++) {
					str[0] = '\0';
					str = to_string(num2);
					str[j - 1] = '0';
					int k = 0;
					for (int i = 0; i < 5; i++) {
						sum_str[i] = '\0';
					}
					for (int m = 0; m <= dec - 2; m++) {
						if (str[m] != '0') {
							sum_str[k] = str[m];
							k++;
						}
					}
					int num3 = atoi(sum_str);
					check_prime(num3);
					if (prime) {
						if (answer <= 2)
							answer = 3;
						for (int m = 1; m <= dec - 2; m++) {
							str[0] = '\0';
							str = to_string(num3);
							str[m - 1] = '0';
							int k = 0;
							for (int i = 0; i < 5; i++) {
								sum_str[i] = '\0';
							}
							for (int l = 0; l <= dec - 3; l++) {
								if (str[l] != '0') {
									sum_str[k] = str[l];
									k++;
								}
							}
							int num4 = atoi(sum_str);
							check_prime(num4);
							if (prime) {
								if (answer <= 3)
									answer = 4;
								for (int l = 1; l <= dec - 3; l++) {
									str[0] = '\0';
									str = to_string(num4);
									str[l - 1] = '0';
									int k = 0;
									for (int i = 0; i < 5; i++) {
										sum_str[i] = '\0';
									}
									for (int p = 0; p <= dec - 4; p++) {
										if (str[p] != '0') {
											sum_str[k] = str[p];
											k++;
										}
									}
									int num5 = atoi(sum_str);
									check_prime(num5);
									if (prime) {
										if (answer <= 4)
											answer = 5;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return answer;
}

int decimal(int n) {
	if (n / 10 == 0)
		return 1;
	else if (n / 100 == 0)
		return 2;
	else if (n / 1000 == 0)
		return 3;
	else if (n / 10000 == 0)
		return 4;
	else
		return 5;
}
int main(int argc, char** argv)
{
	int T, test_case, A, B;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> A >> B;

		A = count(A, decimal(A));
		for (int i = 0; i < 5; i++) {
			str[i] = '\0';
			sum_str[i] = '\0';
		}
		B = count(B, decimal(B));
		if (A > B)
			Answer = 1;
		else if (A == B)
			Answer = 3;
		else
			Answer = 2;
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}