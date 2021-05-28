#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > g;

int main()
{
	int t;
    ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		g.resize(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 0;
		vector<int> answer;
		for (int mask = 0; mask < (1 << n); mask++) {
			set<int> S;
			vector<int> tmp;
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					tmp.push_back(i);
					S.insert(i);
					for (auto to : g[i]) {
						S.insert(to);
					}
				}
			}
			if (S.size() > ans && tmp.size() <= k) {
				ans = S.size();
				answer = tmp;
			}
		}
		cout << answer.size() << "\n";
		for (auto to : answer) {
			cout << to + 1 << " ";
		}
		cout << "\n";
		g.clear();
	}
	return 0;
}