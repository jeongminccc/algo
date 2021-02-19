#include <iostream>
#include <cstring>

using namespace std;

int fibo[50] = {5, 13};
string Messi = " Messi Gimossi";
int main(){
	int messi;
	
	cin >> messi;
	
	for(int i=2; i<40; i++){
		fibo[i] = fibo[i-1] + fibo[i-2] + 1;
	}
	
	for(int i=39; i>=1; i--){
		if(messi > fibo[i])
			messi -= (fibo[i]+1);
	}
	
	if(messi == 0 || messi == 6)
		cout << "Messi Messi Gimossi" << endl;
	else
		cout << Messi[messi] << endl;
	
	return 0;
}
