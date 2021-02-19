#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> ans(n);

	for (int i = 0; i < n; i++)
	{
		arr1[i] |= arr2[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans[i] = (arr1[i] % 2 == 1 ? "#" : " ") + ans[i];
			arr1[i] >>= 1;
		}
	}
	return ans;
}