#include <iostream>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int t = inf.readInt(1, 10, "t");
    inf.readEoln();
    while (t--) {
    	int n = inf.readInt(1, 100, "n");
    	inf.readSpace();
    	int m = inf.readInt(1, 100, "m");
    	inf.readEoln();
    	for (int i = 0; i < n; i++) {
    	    int x = inf.readInt(0, m, "x");
    	    int sum = 0;
    		while (x--) {
    		    inf.readSpace();
    			int tmp = inf.readInt(1, m, "error in amount of black");
    			sum += tmp;
    			if (x) {
    			    sum++;
    			}
    		}
    		ensuref(sum <= m, "Too much black elements");
    		inf.readEoln();
    	}
    	for (int i = 0; i < m; i++) {
    	    int x = inf.readInt(0, n, "x");
    	    int sum = 0;
    		while (x--) {
    		    inf.readSpace();
    			int tmp = inf.readInt(1, n, "error in amount of black");
    			sum += tmp;
    			if (x) {
    			    sum++;
    			}
    		}
    		ensuref(sum <= n, "Too much black elements");
    		inf.readEoln();
    	}
    }
    inf.readEof();
}
