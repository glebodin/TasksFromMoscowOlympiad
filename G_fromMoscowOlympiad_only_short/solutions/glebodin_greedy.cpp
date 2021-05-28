#include <bits/stdc++.h>

using namespace std;
vector<set<int> > g;

int main()
{
    ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		g.resize(n);
		set<pair<int, int> > sizes;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			g[u].insert(v);
			g[v].insert(u);
		}
		for (int i = 0; i < n; i++) {
			sizes.insert(make_pair(-g[i].size(), i));
		}
		vector<int> answer;
		while (k--) {
			auto p = (*sizes.begin());
			for (auto v : g[p.second]) {
				sizes.erase(make_pair(-g[v].size(), v));
				g[v].erase(p.second);
				sizes.insert(make_pair(-g[v].size(), v));
			}
			answer.push_back(p.second);
			sizes.erase(p);
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