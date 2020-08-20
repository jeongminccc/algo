#include "pch.h"
#include <iostream>

using namespace std;

#define MAX 1000000
bool primecheck[MAX] = { false };
bool prime(int num) {
	if (num < 2)
		return false;
	else {
		for (int i = 2;	 i*i <= num; i++) {
			if (num%i == 0)
				return false;
		}
		return true;
	}
}

int main()
{
	int primenum;

	for (int i = 2; i <= MAX ; i++) {
		if (prime(i) == true)
			primecheck[i] = true;
	}

	while (1) {
		cin >> primenum;
		if (primenum == 0)
			break;

		int flag = false;

		for (int i = 2; i*2 <= primenum; i++) {
				if (primecheck[i] == true) {
					if (primecheck[primenum - i] == true) {
						cout << primenum << " = " << i << " + " << primenum - i << "\n";
						flag = true;
						break;
					}
			}
			if (flag == true)
				break;
		}

		if (flag == false) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}

	return 0;
}