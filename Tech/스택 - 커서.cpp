// ConsoleApplication27.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#include <string>

#include <stack>

using namespace std;



stack<char> head, tail; //커서 왼쪽, 오른쪽

int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
		head.push(s[i]);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char op;
		cin >> op;
		//커서 왼쪽

		if (op == 'L')
		{
			if (!head.empty())
			{
				tail.push(head.top());
				head.pop();
			}
		}
		//커서 오른쪽
		else if (op == 'D')
		{
			if (!tail.empty())
			{
				head.push(tail.top());
				tail.pop();
			}
		}
		//커서 왼쪽 문자 삭제

		else if (op == 'B')
		{
			if (!head.empty())
				head.pop();
		}
		//커서 왼쪽에 문자 추가

		else
		{
			char c;
			cin >> c;
			head.push(c);
		}
	}
	while (!head.empty())
	{
		tail.push(head.top());
		head.pop();
	}



	string result;

	while (!tail.empty())

	{

		result += tail.top();

		tail.pop();

	}

	cout << result << "\n";

	return 0;

}