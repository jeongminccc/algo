#include <iostream>
#include <cstring> 

using namespace std;
char ucpc[4] = {'U', 'C', 'P', 'C'};

int main(){
	char list[1010];
	scanf("%[^\n]", list);
	cout << list[0] << endl;
	int len = strlen(list);	
	int k=0;
	char point= ucpc[0];
	
	for(int i=0; i<len; i++){
		if(list[i] == point){
			k++;
			point = ucpc[k];
			if(k == 4)
				break;
		}
	}
	if(k == 4){
		cout << "I love UCPC" << endl;
	}
	else
		cout << "I hate UCPC" << endl;
		
	return 0;
}
