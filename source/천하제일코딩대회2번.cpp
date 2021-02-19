#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char num[20];

	scanf(" &[^\n]", num);
	int len = strlen(num); 
    len--;
	int count = 1;
	if (len == 0 || len == 1) {
		cout << "?(?????)?..°♡ 뀌요미!!" << endl;
		return 0;
	}
	while (len--) {
		if (num[count + 1] - num[count] == num[count] - num[count - 1]) {
			cout << num[count + 1] << endl;
			cout << num[count] - num[count-1] << endl;
			count++;
		}
		else {
			cout << "흥칫뿡!! <(￣ ? ￣)>" << endl;
			return 0;
		}
	}
	cout << "?(?????)?..°♡ 뀌요미!!" << endl;
	return 0;
}