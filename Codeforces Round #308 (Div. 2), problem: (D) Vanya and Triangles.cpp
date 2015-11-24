#include<bits/stdc++.h>

using namespace std;

int main() {
	//ios::sync_with_stdio(0);

	int n, rett = 0;
	scanf("%d", &n);
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);

	for (int i = 0; i < n - 1; ++i) {
		int sm = 0, tmp = 0;
		map<pair<int, int>, int> mp;
		for (int j = i + 1; j < n; ++j) {
			pair<int, int> par;
			par.first = p[j].first - p[i].first;
			par.second = p[j].second - p[i].second;

			if (par.first == 0) {
				mp[ { 500, 500 }]++;
				++sm;
			} else if (par.second == 0) {
				mp[ { 500, 5001 }]++;
				++sm;

			} else {

				int gc = __gcd(par.first, par.second);
				par.first /= gc;
				par.second /= gc;
				mp[par]++;
				++sm;

			}
		}
		for (auto &it : mp) {
			tmp += (sm - it.second) * it.second;
			sm -= it.second;
		}
		rett += tmp;
	}
	printf("%d", rett);

	return 0;
}
