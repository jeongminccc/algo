#include <stdio.h>
#include <iostream>
#define NUM 500001

using namespace std;
long long Answer = 0;

int main(int argc, char** argv)
{
	long long *Dp = new long long[NUM];
	int T, test_case;
	long long Num_x, Num_y;
	Dp[0] = 0, Dp[1] = 1;
	for (long long i = 2; i < NUM; i++) {
		Dp[i] = Dp[i - 1] + i;
	}

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf_s("%lld %lld", &Num_x, &Num_y);
		Answer = 0;
		long long mid, low = 0, high = NUM;
		long long point, min;

		while (1) {
			mid = (low + high) / 2;
			if (Dp[mid] <= Num_y) {
				if (Dp[mid + 1] >= Num_y) {
					if (Dp[mid + 1] == Num_y)
						point = mid + 1;
					else
						point = mid;
					break;
				}
				low = mid + 1;
			}
			else {
				if (Dp[mid - 1] <= Num_y) {
					point = mid - 1;
					break;
				}
				high = mid - 1;
			}
		}



		min = Dp[point - 1] ;
		if (Num_x > min)
			min = Num_x;

		for (long long j = Num_y; j >= min; j--) {
			long long key, count = 0;
			long long i = j;
			low = 0;
			if (i >= Dp[point]) {
				i = i - Dp[point];
				count += point;
				high = point;
			}
			else {
				i = i - Dp[point - 1];
				count += point - 1;
				high = point-1;
			}

			while (1) {
				mid = (low + high) / 2;
				if (Dp[mid] <= i) {
					low = mid + 1;
					if (Dp[mid] == i) {
						count += mid;
						break;
					}
					if (Dp[mid + 1] >= i) {
						if (Dp[mid + 1] == i) {
							count += mid + 1;
							break;
						}
						i = i - Dp[mid];
						low = 0;
						high = mid;
						count += mid;
					}
				}
				else {
					high = mid - 1;
					if (Dp[mid - 1] <= i) {
						if (Dp[mid - 1] == i) {
							count += mid - 1;
							break;
						}
						i = i - Dp[mid - 1];
						low = 0;
						high = mid-1;
						count += mid - 1;
					}
				}
			}
			if (Answer <= count)
				Answer = count;
		}


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}