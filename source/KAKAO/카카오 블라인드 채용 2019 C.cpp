#include <bits/stdc++.h>

using namespace std;

bool another(vector<int> &a, int temp){
	for(int i=0; i<a.size(); i++){
		if( (a[i]&temp) == a[i])
		return false;
	}
	return true;
}
int solution(vector<vector<string>> relation){
	int n = relation.size();
	int m = relation[0].size();
	vector<int> answer;
	
	for(int i=1; i<(1<<m); i++){
		set<string> set_temp;
		for(int j=0; j<n; j++){
			string temp = "";
			for(int k=0; k<m; k++){
				if(i&(1<<k))
					temp += relation[j][k];
			}
			set_temp.insert(temp);
		}
		if(set_temp.size() == n && another(answer,i))
			answer.push_back(i);
	}
	return answer.size();
}
