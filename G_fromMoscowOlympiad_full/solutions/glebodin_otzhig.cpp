#include <bits/stdc++.h>
using namespace std;
vector<set<int> > g, gg;
random_device rd;
mt19937 gen(42);

double rnd()
{
    return (double(gen()) / RAND_MAX);
}

int f(const vector<int>& answer) {
	set<int> elems;
	for (auto to : answer) {
		elems.insert(to);
		for (auto v : g[to]) {
			elems.insert(v);
		}
	}
	return elems.size();
}

int main() {
    ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		g.resize(n);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			g[a].insert(b);
			g[b].insert(a);
		}
		if (n < 15) {
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
		}
		else {
		    gg = g;
    		set<pair<int, int> > sizes;
    		for (int i = 0; i < n; i++) {
    			sizes.insert(make_pair(-g[i].size(), i));
    		}
    		vector<int> answer, bestanswer;
    		int kk = k;
    		while (kk--) {
    			auto p = (*sizes.begin());
    			for (auto v : gg[p.second]) {
    				sizes.erase(make_pair(-gg[v].size(), v));
    				gg[v].erase(p.second);
    				sizes.insert(make_pair(-gg[v].size(), v));
    			}
    			answer.push_back(p.second);
    			sizes.erase(p);
    		}
    		bestanswer = answer;
    		int fbestanswer = f(answer);
    		double t = 100;
    		auto start = clock();
    		int anscur = f(answer);
        	while((double)(clock() - start) / CLOCKS_PER_SEC < 1.5)
        	{
            	t *= 0.96;
            	int pos = rand() % answer.size();
            	int val = rand() % n;
            	int oldval = answer[pos];
            	answer[pos] = val;
            	int anstmp = f(answer);
            	if(anstmp > anscur || rnd() < exp((anscur - anstmp) / t))
            	{
            		anscur = anstmp;
            	}
            	else {
            		answer[pos] = oldval;
            	}
            	if (anstmp > fbestanswer) {
            	    bestanswer = answer;
            	    fbestanswer = anstmp;
            	}
        	}
    		cout << bestanswer.size() << "\n";
    		for (auto to : bestanswer) {
    			cout << to + 1 << " ";
    		}
    		cout << "\n";
		}
    	g.clear();
	}
	return 0;
}