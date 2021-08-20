#include <bits/stdc++.h>

/*
	VERIFIED through
	https://codeforces.com/problemset/problem/52/C
*/

template <class T>
class SegmentTree {
	using vt = std :: vector<T>;
	using vi = std :: vector<int>;

public:
	SegmentTree(int N) {
		n = N;
		lo.resize(2 * n + 1);
		hi.resize(2 * n + 1);
		mini.resize(2 * n + 1);
		delta.resize(2 * n + 1);
		init(1, 0, n - 1);
	}

	void increment(int a, int b, T val) {
		increment(1, a, b, val);
	}

	T minimum(int a, int b) {
		return minimum(1, a, b);
	}

private:
	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) 
			return;
		int m = (a + b) >> 1;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
	}
	
	void prop(int i) {
		delta[2 * i] += delta[i];
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}
	void update(int i) {
		mini[i] = std :: min(mini[2 * i] + delta[2 * i], mini[2 * i + 1] + delta[2 * i + 1]);
	}

	void increment(int i, int a, int b, T val) {
		if(lo[i] > b || hi[i] < b)
			return;
		if(lo[i] >= a && hi[i] <= b) 
			delta[i] += val;

		prop(i); // propogate to child
		increment(2 * i, a, b, val);
		increment(2 * i + 1, a, b, val);
		update(i); // update the current
	}
	T minimum(int i, int a, int b) {
		if(lo[i] > b || hi[i] < b) 
			return 	std :: numeric_limits<T>::max();
		if(lo[i] >= a && hi[i] <= b)
			return delta[i] + mini[i];

		prop(i);
		T minLeft = minimum(2 * i, a, b);
		T minRight = minimum(2 * i + 1, a, b);
		update(i);
		return std :: min(minLeft, minRight);
	}

private:
	vi lo, hi;
	vt mini, delta;
	int n;
};
