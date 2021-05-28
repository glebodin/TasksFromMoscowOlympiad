#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int n, m, c;
	cin >> n >> m >> c;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = rand() % c;
			if (tmp) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;
			}
			//cout << a[i][j] << " ";
		}
		//cout << "\n";
	}
	cout << n << " " << m << "\n";
	for (int i = 0; i < n; i++) { 
		vector<int> ans;
		int now = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 0) {
				now++;
			}
			else {
				if (now != 0) {
					ans.push_back(now);
				}
				now = 0;
			}
		}
		if (now != 0) {
			ans.push_back(now);
		}
		cout << ans.size() << " ";
		for (auto to : ans) {
			cout << to << " ";
		}
		cout << "\n";
	}
	for (int j = 0; j < m; j++) { 
		vector<int> ans;
		int now = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j] != 0) {
				now++;
			}
			else {
				if (now != 0) {
					ans.push_back(now);
				}
				now = 0;
			}
		}
		if (now != 0) {
			ans.push_back(now);
		}
		cout << ans.size() << " ";
		for (auto to : ans) {
			cout << to << " ";
		}
		cout << "\n";
	}
	return 0;
}