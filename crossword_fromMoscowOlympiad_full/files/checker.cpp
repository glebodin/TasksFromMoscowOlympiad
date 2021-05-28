#define NOFOOTER

#ifdef BURUNDUK
#  include "my_testlib.h"
#else
#  include "testlib.h"
#endif

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int t = inf.readInt();
	int tt = t;
	vector<double> marks;
    double sum = 0;
	while (tt--) {
    	int n = inf.readInt();
    	int m = inf.readInt();
    	double mark = 0;
    	int num = 0;
    	int a[n][m];
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			a[i][j] = ouf.readInt();
    			if (a[i][j] < 0 || a[i][j] > 1) {
			        quitf(_pe, "something wrong with matrix");
			    }
    			num++;
    		}
    	}
    	for (int i = 0; i < n; i++) {
    		vector<int> ans;
    		vector<int> ans1;
    		int x = inf.readInt();
    		while(x--) {
    			int a = inf.readInt();
    			ans1.push_back(a);
    		}
    		int now = 0;
    		for (int j = 0; j < m; j++) {
    			int tmp = a[i][j];
    			if (tmp) {
    				now++;
    			}
    			else {
    				if (now) {
    					ans.push_back(now);
    					now = 0;
    				}
    			}
    		}
    		if (now) {
    			ans.push_back(now);
    			now = 0;
    		}
    		bool isgood = 1;
    		if (ans.size() == ans1.size()) {
    		    for (int i = 0; i < ans.size(); i++) {
    				if (ans[i] != ans1[i]) {
    				    isgood = 0;
    			    }
    			}
    		}
    		else {
    		    isgood = 0;
    		}
    		mark += isgood;
    	}
    	for (int j = 0; j < m; j++) {
    		vector<int> ans;
    		vector<int> ans1;
    		int x = inf.readInt();
    		while(x--) {
    			int a = inf.readInt();
    			ans1.push_back(a);
    		}
    		int now = 0;
    		for (int i = 0; i < n; i++) {
    			int tmp = a[i][j];
    			if (tmp) {
    				now++;
    			}
    			else {
    				if (now) {
    					ans.push_back(now);
    					now = 0;
    				}
    			}
    		}
    		if (now) {
    			ans.push_back(now);
    			now = 0;
    		}
    		bool isgood = 1;
    		if (ans.size() == ans1.size()) {
    		    for (int i = 0; i < ans.size(); i++) {
    				if (ans[i] != ans1[i]) {
    				    isgood = 0;
    			    }
    			}
    		}
    		else {
    		    isgood = 0;
    		}
    		mark += isgood;
    	}
    	if (num != n * m) {
    	    quitf(_pe, "too small output + num = %d + size = %d", num, n * m);
        }
        mark /= (n + m);
        cout << mark << endl;
        sum += mark;
        marks.push_back(mark);
	}
	if (!ouf.seekEof()) {
	    quitf(_pe, "too big output");
    }
	quitf(_ok, "participant's solution is ok, score is %lf", sum / t * 30);
	return 0;
}
