#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[40][100];

ll rec(int i, int h) {
	if (i <= 1) {
		if (h <= i)
			return 1;
		return 0;
	}
	ll &ret = dp[i][h + 50];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int j = 0; j < i; ++j) {
		ret += (rec(j, 0) * rec(i - j - 1, h - 1));
		ret += (rec(j, h - 1) * rec(i - j - 1, 0));
		ret -= (rec(j, h - 1) * rec(i - j - 1, h - 1));
	}

	return ret;
}
int main() {
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	int n, h;
	scanf("%d %d", &n, &h);
	cout << rec(n, h);
	return 0;
}
