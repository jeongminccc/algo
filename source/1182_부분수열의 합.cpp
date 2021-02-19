#include <iostream>

//1. 문제를 읽고 이해
//2. 문제를 익숙한 용어로 재정의
// -> 모든 부분집합을 구해라. 
//3. 어떻게 해결할지 계획
// -> 20개의 정수가 주어지므로 모든 부분집합의 개수는 2^20 = 약 백만이다.
// -> 보통 1억개의 연산에 1초가 걸린다고 생각할 수 있으므로, 충분히 시간복잡도안에 연산이 가능할 것으로 보임 
// -> 모든 부분집합을 구하고, 그 중 합이 N인것의 수를 구하면 된다. 재귀함수로 충분히 구현할 수 있을듯. 
//4. 계획을 검증
// -> 위에서 계산함 
//5. 구현
// -> 조합을 구현하는 방식은 다양하다.
// -> 1. DFS - 이번 차례의 원소를 넣을건지 안넣을건지 2가지 경우로 나눔 
// -> 2. 재귀 함수를 이용 
//6. 어떻게 풀었는지, 개선할 여지가 있는지 기록 + 다른사람의 코드

using namespace std;

int num[21], ans=0, N, S;

void recur(int cur, int sum)
{
	if(cur == N) return;
	if(sum+num[cur] == S) ans++;
	
	recur(cur+1, sum);
	recur(cur+1, sum + num[cur]); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> N >> S;
	for (int i=0; i<N; ++i)
		cin >> num[i];
	
	recur(0,0);
	
	cout << ans << endl;
    return 0;
}