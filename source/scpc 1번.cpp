#include <fstream>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int Ans_arr[1000001];

int main(int argc, char** argv)
{
	int T, test_case, Num_1, Num_2;
	Ans_arr[1] = 0, Ans_arr[0] = 0;

	for (int i = 2; i < 1000001; i++) {
		if (i % 2 == 0) {
			Ans_arr[i] = Ans_arr[i / 2] + 1;
		}
		else {
			Ans_arr[i] = Ans_arr[(i + 1) / 2] + 2;
		}
	}
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf_s("%d %d", &Num_1, &Num_2);
		Answer = 0;
		for (int i = Num_1; i <= Num_2; i++) {
			Answer += Ans_arr[i];
		}

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;
}