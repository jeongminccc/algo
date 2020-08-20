#include <iostream>

using namespace std;

int main(){
	int n, mount=0;
	cin >> n;
	
	if( n%14 == 1 || n%14 == 13)
		cout << "baby" << endl;
	else if( n%14 == 2 || n%14 == 0)
		cout << "sukhwan" << endl;
	else if( n%14 == 5)
		cout << "very" << endl;
	else if( n%14 == 6)
		cout << "cute" << endl;
	else if( n%14 == 9)
		cout << "in" << endl;
	else if( n%14 == 10)
		cout << "bed" << endl;
	else if( n%14 == 3 || n%14 == 7 || n%14 == 11){
		mount = n/14;
		if(mount >= 3)
			cout << "tu+ru*" << mount+2 << endl;
		else if(mount == 0)
			cout << "tururu" << endl;
		else if(mount == 1)
			cout << "turururu" << endl;
		else if(mount == 2)
			cout << "tururururu" << endl;
	}
	else{
		mount = n/14;
		if(mount >= 4)
			cout << "tu+ru*" << mount+1 << endl;
		else if(mount == 0)
			cout << "turu" << endl;
		else if(mount == 1)
			cout << "tururu" << endl;
		else if(mount == 2)
			cout << "turururu" << endl;
		else if(mount == 3)
			cout << "tururururu" << endl;	
	}
	return 0;
}
