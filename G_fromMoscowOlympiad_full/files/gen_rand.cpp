#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <chrono>
#include <random>
#include <fstream>
#include <assert.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include "testlib.h"

using namespace std;

mt19937 rd(chrono::system_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

/*#pragma GCC optimize("Ofast")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("no-stack-protector")
 #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
 #pragma GCC optimize("fast-math")*/


void dfs(int v, vector<vector<int>> &g, vector<int> &comp, int cmp, int av) {
    comp[v] = cmp;
    for (int u : g[v]) {
        if (comp[u] == -1 && u != av)
            dfs(u, g, comp, cmp, av);
    }
}

pair<int, int> gen_pair(int n) {
    int a = rnd.next(1, n) - 1;
    int b = a;
    while (a == b)
        b = rnd.next(1, n) - 1;
    if (a > b)
        swap(a, b);
    return {a, b};
}

int main(int argc, char* argv[]) {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    auto ti = clock();
#endif
    ios::sync_with_stdio(0);
    registerGen(argc, argv, 1);

    
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = atoi(argv[3]);
    m -= n - 1;
    
    set<pair<int, int>> e;
    vector<vector<int>> g(n);
    
    for (int i = 1; i < n; i++) {
        int p = 0;
        if (i != 1)
            p = rnd.next(i - 1);
        e.insert({p, i});
        g[i].push_back(p);
        g[p].push_back(i);
    }
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 1)
            v.push_back(i);
    }
    shuffle(v.begin(), v.end());
    
    int t = v[0];
    
    vector<int> comp(n, -1);
    int cmp = 0;
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1 && i != t)
            dfs(i, g, comp, cmp++, t);
    }
    
    vector<vector<int>> list(cmp);
    for (int i = 0; i < n; i++) {
        if (i == t)
            continue;
        list[comp[i]].push_back(i);
    }
    
    int cnt = 0;
    
    for (int i = 0; i < m; i++) {
        int ind = rnd.next(1, cmp) - 1;
        while (list[ind].size() == 1)
            ind = rnd.next(1, cmp) - 1;
        
        auto pa = gen_pair(list[ind].size());
        pa.first = list[ind][pa.first];
        pa.second = list[ind][pa.second];
        if (pa.first > pa.second)
            swap(pa.first, pa.second);
        int it_cnt = 0;
        while (e.count(pa) != 0 && it_cnt < 10) {
            pa = gen_pair(list[ind].size());
            pa.first = list[ind][pa.first];
            pa.second = list[ind][pa.second];
            if (pa.first > pa.second)
                swap(pa.first, pa.second);
            it_cnt++;
        }
        
        if (it_cnt >= 10)
            continue;
        
        e.insert({pa.first, pa.second});
        cnt++;
        if (cnt == m)
            break;
    }
    
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    shuffle(p.begin(), p.end());
    
    vector<pair<int, int>> out_e;
    
    cout << "1\n" << n << ' ' << e.size() << ' ' << k << endl;
    for (auto pa : e)
        out_e.push_back({p[pa.first] + 1, p[pa.second] + 1});
    shuffle(out_e.begin(), out_e.end());
    for (auto pa : out_e)
        cout << pa.first << ' ' << pa.second << endl;
    
    return 0;
}
