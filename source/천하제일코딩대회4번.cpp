#include <iostream>

using namespace std;

float stage[1010];

int main(){
	float n;
	int answer=0, point=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> stage[i];
		if(point == 0 && stage[i] > 0){
			if( (stage[i] - int(stage[i]) ) > 0.1 )
				answer += stage[i]+1;
			else
				answer += stage[i];
			point = 1;
		}
		else if(stage[i] > 0){
			answer += stage[i];			
		}
	}
	cout << answer << endl;
	return 0;	
} 
