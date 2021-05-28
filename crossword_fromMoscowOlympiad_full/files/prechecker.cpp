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
    	cout << n << " " << m << "\n";
    	for (int i = 0; i < n; i++) {
    		int x = inf.readInt();
    		while(x--) {
    			int a = inf.readInt();
    		}
    	}
    	for (int i = 0; i < m; i++) {
    		int x = inf.readInt();
    		while(x--) {
    			int a = inf.readInt();
    		}
    	}
    	int num = 0;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			int tmp = ouf.readInt();
    			num++;
    			if (tmp < 0 || tmp > 1) {
			        quitf(_pe, "something wrong with matrix");
			    }
    		}
    	}
    	if (num != n * m) {
    	    quitf(_pe, "too small output + num = %d + size = %d", num, n * m);
        }
	}
	if (!ouf.seekEof()) {
	    quitf(_pe, "too big output");
    }
	quitf(_ok, "no pe");
	return 0;
}
