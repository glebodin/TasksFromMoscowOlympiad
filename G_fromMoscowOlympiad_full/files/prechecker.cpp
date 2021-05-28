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
	while (t--) {
    	int n = inf.readInt();
    	int m = inf.readInt();
    	int k = inf.readInt();
    	for (int i = 0; i < m; i++) {
    		int u = inf.readInt();
    		int v = inf.readInt();
    	}
    	int tmp = ouf.readInt();
		if (tmp > k) {
			quitf(_pe, "something wrong with amount of answer");
		}
		int num = 0;
    	for (int i = 0; i < tmp; i++) {
    		num++;
    		int x = ouf.readInt();
    		if (x <= 0 || x > n) {
				quitf(_pe, "something wrong with vertex");
			}
    	}
    	if (num != tmp) {
    	    quitf(_pe, "too small output");
        }
	}
	if (!ouf.seekEof()) {
	    quitf(_pe, "too big output");
    }
	quitf(_ok, "no pe");
	return 0;
}
