#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, n, k, m, x;
	scanf("%d %d %d %d", &N, &k, &n, &m);
	set<int> st;
	st.insert(0);
	st.insert(N + 1);
	int sets = (N + 1) / (n + 1);

	for (int i = 1; i <= m; ++i) {
		scanf("%d", &x);

		auto up = st.upper_bound(x);
		auto lw = --st.upper_bound(x);

		int tmp = (*up - *lw) / (n + 1);
		sets -= tmp;
		sets += ((*up - x) / (n + 1) + (x - *lw) / (n + 1));

		if (sets < k) {
			printf("%d", i);
			return 0;
		}
		st.insert(x);
	}

	printf("-1");
	return 0;
}
