#define NOFOOTER

#ifdef BURUNDUK
#  include "my_testlib.h"
#else
#  include "testlib.h"
#endif

#include <iostream>

using namespace std;
vector<vector<int> > g;

double mpower(double a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    double res = mpower(a, n / 2);
    return res * res * mpower(a, n % 2);
}

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int t = inf.readInt();
	int tt = 0;
	vector<double> marks;
    double sum = 0;
	while (tt < t) {
    	int n = inf.readInt();
    	int m = inf.readInt();
    	int k = inf.readInt();
    	g.resize(n);
    	for (int i = 0; i < m; i++) {
    		int u = inf.readInt();
    		int v = inf.readInt();
    		u--;
    		v--;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	int tmp = ouf.readInt();
		if (tmp > k) {
			quitf(_pe, "something wrong with amount of answer");
		}
		int num = 0;
		set<int> answer;
    	for (int i = 0; i < tmp; i++) {
    		num++;
    		int x = ouf.readInt();
    		if (x <= 0 || x > n) {
				quitf(_pe, "something wrong with vertex");
			}
			x--;
    		answer.insert(x);
			for (auto to : g[x]) {
			    answer.insert(to);
			}
    	}
        double mark = answer.size();
    	if (num != tmp) {
    	    quitf(_pe, "too small output");
        }
        tt++;
        /*int markjury = ans.readInt();
        if (markjury < 0 || markjury > k) {
            quitf(_fail, "something wrong with answer's length");
        }
		set<int> answerjury;
        for (int i = 0; i < markjury; i++) {
            int x = ans.readInt();
    		if (x <= 0 || x > n) {
				quitf(_fail, "something wrong with vertex in jury's answer");
			}
			x--;
    		answerjury.insert(x);
			for (auto to : g[x]) {
			    answerjury.insert(to);
			}
        }*/
        mark /= n;
        if (mark > 1) {
            quitf(_fail, "in test %d participant answer is better : %d", tt, answer.size());
        }
        sum += (mark);
        marks.push_back(mark);
        g.clear();
	}
	if (!ouf.seekEof()) {
	    quitf(_pe, "too big output");
    }
	if (!ouf.seekEof()) {
	    quitf(_pe, "too big output");
    }
	quitf(_ok, "participant's solution is ok, score is %lf", sum / t);
	return 0;
}
