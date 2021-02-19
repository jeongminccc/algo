#include <bits/stdc++.h>

using namespace std;

int Answer;
int person[200001];

int main(int argc, char** argv)
{
	int T, test_case;
	int people, max_ability, temp;
	
	cin >> T;
	
	for(test_case = 0; test_case  < T; test_case++)
	{
		int max =0, j=0, max_ability_temp=max_ability;
		cin >> people >> max_ability; 
		for(int i=0; i<people; i++){
			cin >> person[i]; 
		}
		sort(person[0], person[people-1]);
		while(1){
			temp = upper_bound(person[j], person[people-1], max_ability_temp) - j;
			max_ability_temp = max_ability_temp + person[j+temp];  
			if(max <= temp){
				max = temp;
			}
			j = j+temp;
			if(j == people)
				break;
		}
		Answer = 0;
	
		cout << "Case #" << test_case+1 << endl;
		cout << max << endl;
	}

	return 0;
}
