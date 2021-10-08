#include <bits/stdc++.h>

using std :: vector;


template<typename T>
struct Minimum {
	T operator () (const T & lhs, const T & rhs) const {
		return std :: min (lhs, rhs);
	}
};

template<typename T>
struct Maximum {
	T operator () (const T & lhs, const T & rhs) const {
		return std :: max(lhs, rhs);
	}
};


template<class T, typename AssociativeOperation>
class SparseTable {
public:
    SparseTable (vector<T> & a, AssociativeOperation op): operation (op) {
        n = a.size();
        maxK = ceil(log2(n));
        table.resize(maxK + 1);
        Log.resize(n + 1);
        for (int i = 0; i <= maxK; ++i) { table[i].resize(n + 1); }
        for (int i = 0; i < n; ++i) { table[0][i] = a[i]; }
        for (int k = 1; k <= maxK; ++k) for (int i = 0; i + (1 << k) <= n; ++i) {
            table[k][i] = operation(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
        }

        Log[1] = 0;
        for (int i = 2; i <= n; ++i) {
            Log[i] = Log[i / 2] + 1;
        }
    }

    T query (int a, int b) {
        int k = Log[b - a + 1];
        int m = b - (1 << k) + 1;
         // a ... a + 2^k - 1,   b - 2 ^ k + 1 ..... b 
         // The ranges will surely intersect.
        return operation(table[k][a], table[k][m]);
    }

private:
    int maxK, n;
    vector<vector<T>> table;
    vector<int> Log;
    AssociativeOperation operation;
};


Maximum<int> MaxiInt;
Minimum<int> MiniInt;
