#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[10] = {4,2,3,6,1,8,7,10,234,22}; 
	sort(arr, arr+10);
	
	cout << "test 1" << endl;
	for(int i=0; i<10; i++){
	cout << arr[i] << endl;}
	
	vector<int> Vec;
	for(int i=0; i<10; i++){
		Vec.push_back(rand() % 10);	
	}
	sort(Vec.begin(), Vec.end());
	sort(Vec.begin(), Vec.end(), greater<int>());
	cout << "test 2" << endl;
	for(int i=0; i<10; i++){
	cout << Vec[i] << endl;}
	
	return 0;
}
