#include <iostream>
#include <cstring>

using namespace std;

int N, minimun = 0, maxV = 1e9;

int main() {
	cin >> N;
	
	char c;
	string st, en;
	int hour=0, minute=0;
	for (int i=0; i<N; ++i)
	{
		cin >> st >> c >> en;
		
		hour = 10 * (st[0] - '0') + st[1] - '0';
		minute = 10 * (st[3] - '0') + st[4]  - '0'; 
		if (minimun <= (hour * 60) + minute)
			minimun = (hour * 60) + minute;
		
		hour = 10 * (en[0] - '0') + en[1]  - '0';
		minute = 10 * (en[3] - '0') + en[4]  - '0';
		if (maxV >= (hour * 60) + minute)
			maxV = (hour * 60) + minute;
	}
	
	hour = minimun / 60; 
	minute = minimun - (hour * 60);
	st = to_string(hour) + ":" + to_string(minute);
	if (minute == 0) st += "0";

	hour = maxV / 60; 
	minute = maxV - (hour * 60);
	en = to_string(hour) + ":" + to_string(minute);
	if (minute == 0) en += "0";

	cout << st << " ~ " << en;
	return 0;
}