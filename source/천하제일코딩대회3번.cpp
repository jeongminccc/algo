#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n, num;
	cin >> n;
	num = n;
	while(n>0){
		if(n == 1){
			cout << "1 bottle of beer on the wall, 1 bottle of beer." << endl;
			cout << "Take one down and pass it around, no more bottles of beer on the wall." << endl;
		}
		else if(n == 2){
			cout << n << " bottles of beer on the wall, " << n << " bottles of beer." << endl;
			cout << "Take one down and pass it around, " << n-1 << " bottle of beer on the wall." << endl;
		}
		else{
			cout << n << " bottles of beer on the wall, " << n << " bottles of beer." << endl;
			cout << "Take one down and pass it around, " << n-1 << " bottles of beer on the wall." << endl;
		}
		cout << "\n";
		n--;
	}
	if(num == 1){
		cout << "No more bottles of beer on the wall, no more bottles of beer." << endl;
		cout << "Go to the store and buy some more, " << num << " bottle of beer on the wall." << endl;
	}
	else {
		cout << "No more bottles of beer on the wall, no more bottles of beer." << endl;
		cout << "Go to the store and buy some more, " << num << " bottles of beer on the wall." << endl;
	}
	return 0;
}
