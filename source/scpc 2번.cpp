#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

#define pi 3.14159265
#define half 0.5

double Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	double Ball_rad, Ball_x, Ball_goal, obs_count, obs_left, obs_right, obs_height;
	double temp_radian, temp_degree, offset;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		temp_radian = 0, temp_degree= 0;
		Answer = 0;
		scanf_s("%lf %lf %lf", &Ball_rad, &Ball_x, &Ball_goal);
		scanf_s("%lf", &obs_count);
		for (int i = 0; i < obs_count; i++) {
			scanf_s("%lf %lf %lf", &obs_left, &obs_right, &obs_height);
			if (obs_height >= Ball_rad) {
				Answer += (obs_left - Ball_x - Ball_rad);
				Answer += (obs_right - obs_left);
				Answer += (Ball_rad * 2.0 * pi*half);
				Answer += (obs_height - Ball_rad) * 2.0;
				Ball_x = obs_right + Ball_rad;
			}
			else {
				temp_radian = acos((Ball_rad - obs_height) / Ball_rad);
				offset = Ball_rad * sin(temp_radian);
				Answer += (obs_left - Ball_x - offset);
				Answer += (obs_right - obs_left);
				temp_degree = acos((Ball_rad - obs_height) / Ball_rad) * (180.0 / pi);
				Answer += (Ball_rad * 2.0 * pi * ((temp_degree*2.0) / 360.0) );
				Ball_x = obs_right + offset;
			}
		}
		Answer += (Ball_goal - Ball_x);

		cout << "Case #" << test_case + 1 << endl;
		cout << fixed;
		cout.precision(7);
		cout << Answer << endl;
	}

	return 0;
}