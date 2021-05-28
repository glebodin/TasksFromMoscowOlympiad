#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(42);
vector<set<int> > g;
int main() {
	int t;
	cin >> t;
	cout << t << "\n";
	while (t--) {
		int n, k, sz;
		cin >> n >> sz >> k;
		g.resize(n);
		int adj[n];
		vector<pair<int, int> > edges;
		for (int i = 0; i < n; i++) {
			adj[i] = sz;
		}
		for (int i = 0; i < n; i++) {
			while (adj[i] > 0) {
				adj[i]--;
				int a = rnd() % n;
				if (g[i].find(a) == g[i].end() && i != a) {
					g[i].insert(a);
					g[a].insert(i);
					adj[a]--;
					edges.push_back({i, a});
				}
			}
		}
		int m = edges.size();
		cout << n << " " << m << " " << k << "\n";
		for (int i = 0; i < m; i++) {
			cout << edges[i].first + 1 << " " << edges[i].second + 1 << "\n";
		}
		g.clear();
	}
	return 0;
}