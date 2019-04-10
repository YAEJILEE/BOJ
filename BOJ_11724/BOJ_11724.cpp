#include<cstdio>
#include<vector>
using namespace std;

int check[1001] = { 0, };
vector<int> a[1001];

void dfs(int v) {
	check[v] = true;
	for (int i = 0; i < a[v].size(); i++) {
		if (check[a[v][i]] == false) {
			dfs(a[v][i]);
		}
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}