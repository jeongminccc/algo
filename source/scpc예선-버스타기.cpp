#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int person[200001];

int main(int argc, char** argv)
{
	int T, test_case;
	int people, max_ability, temp;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		int max = 0;
		cin >> people >> max_ability;
		for (int i = 0; i < people; i++) {
			cin >> person[i];
		}
		sort(person, person +people);

		int result = 1;
		for (int i = 1; i < people; i++) {
			if (person[i] - person[i - result] <= max_ability) result++;
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << result << endl;
	}

	return 0;
}