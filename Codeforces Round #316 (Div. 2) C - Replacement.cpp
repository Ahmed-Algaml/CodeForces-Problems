#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, x, res = 0;
	set<int> letter;
	scanf("%d %d", &n, &m);
	letter.insert(0);
	letter.insert(n + 1);
	char c;
	int s = -1;
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &c);
		if (c != '.') {
			letter.insert(i + 1);
			if (s != -1) {
				res += (i - s - 1);
				s = -1;
			}
		} else {
			if (s == -1)
				s = i;
		}
	}

	if (s != -1)
		res += (n - s - 1);

	while (m--) {
		scanf("%d %c", &x, &c);
		if (c == '.' && letter.find(x) == letter.end()) {
			printf("%d\n", res);
			continue;
		}
		if (c != '.' && letter.find(x) != letter.end()) {
			printf("%d\n", res);
			continue;
		}
		if (c != '.') {
			auto upp = letter.upper_bound(x);
			auto lw = --letter.upper_bound(x);
			int tmp = (*upp - *lw - 1);

			res -= (tmp - 1);
			res += max(0, x - *lw - 2);
			res += max(0, *upp - x - 2);
			printf("%d\n", res);
			letter.insert(x);
		} else {
			letter.erase(x);
			auto upp = letter.upper_bound(x);
			auto lw = --letter.upper_bound(x);
			int tmp = (*upp - *lw - 1);

			res += (tmp - 1);
			res -= max(0, x - *lw - 2);
			res -= max(0, *upp - x - 2);
			printf("%d\n", res);

		}

	}

	return 0;
}
