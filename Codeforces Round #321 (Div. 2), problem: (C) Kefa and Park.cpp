#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin() , v.end()
using ll = long long;
int cons;
vector<vector<int>> v;
int cat[(int) 1e5 + 5];

ll DFS(int par, int i, int c) {
	if (c > cons)
		return 0;

	ll res = 0;
	int t = 1;

	for (int j = 0; j < (int) v[i].size(); ++j) {
		int child = v[i][j];
		if (child == par)
			continue;
		t = 0;
		if (cat[child])
			res += DFS(i, child, c + 1);
		else
			res += DFS(i, child, 0);
	}
	return res + t;
}
int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	scanf("%d %d", &n, &cons);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &cat[i]);

	v = vector<vector<int>>(n + 2);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cout << DFS(-1, 1, cat[1]);

	return 0;

}
