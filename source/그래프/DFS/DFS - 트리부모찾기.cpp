#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> tree[100111];
int parent[100111] = { 0 };
bool visited[100111];

void findParent(int nodeNum) {
	visited[nodeNum] = true;

	for (int i = 0; i < tree[nodeNum].size(); i++) {
		int next = tree[nodeNum][i];

		if (!visited[next]) {
			parent[next] = nodeNum;
			findParent(next);
		}
	}
}
int main()
{
	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N-1; i++) {
		int parent, node;
		scanf_s("%d %d", &parent, &node);
		tree[parent].push_back(node);
		tree[node].push_back(parent);
	}

	findParent(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}




	return 0;
}