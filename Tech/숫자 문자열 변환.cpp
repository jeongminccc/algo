#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int inum;
	const char * ptrChar = "first";
	string cString;
	
	cString = ptrChar;
	cout << "[test1] : char * --> string" << endl;
	cout << ptrChar << " --> " << cString << endl;
	
	cString = "test2_string";
	ptrChar = cString.c_str();
	cout << "[test2] : string --> const char *" << endl;
	cout << cString << " --> " << ptrChar << endl;
	
	cString = "20190710";
	inum = atoi(cString.c_str());
	cout << "[test3] : string --> int" << endl;
	cout << cString << " --> " << inum << endl;
	
	inum = 20190710;
	cString = to_string(inum);
	cout << "[test4] : int --> string" << endl;
	cout << inum << " --> " << cString << endl;
	
	inum = 9;
	char Char = '0' + inum;
	cout << "[test5] : int --> char" << endl;
	cout << inum << " --> " << Char << endl;
	return 0;
}
