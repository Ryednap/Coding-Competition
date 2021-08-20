#include <bits/stdc++.h>

/*
https://codeforces.com/contest/380/problem/C

Sereja has a bracket sequence s1, s2, ..., sn, or, in other words, a string s of length n, consisting of characters "(" and ")".

Sereja needs to answer m queries, each of them is described by two integers li, ri (1 ≤ li ≤ ri ≤ n). The answer to the i-th query is the length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri. Help Sereja answer all queries.

You can find the definitions for a subsequence and a correct bracket sequence in the notes.

Input
The first line contains a sequence of characters s1, s2, ..., sn (1 ≤ n ≤ 106) without any spaces. Each character is either a "(" or a ")". The second line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains a pair of integers. The i-th line contains integers li, ri (1 ≤ li ≤ ri ≤ n) — the description of the i-th query.

Output
Print the answer to each question on a single line. Print the answers in the order they go in the input.

*/


struct QueryForm {
	int open, closed, complete;
	QueryForm() {}
	QueryForm(int a, int b, int c) :
		open(a), closed(b), complete(c) {}
};

class SegmentTree {
	using vi = std :: vector<int>;
public:
	SegmentTree(std :: string s) {
		n = s.length();
		str = s;
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1);

		init(1, 0,n - 1);
	}

	int query(int a, int b) {
		return query(1, a, b).complete * 2;
	}

private:
	QueryForm Merge(QueryForm left, QueryForm right) {
		int complete = std :: min(left.open, right.closed);
		return QueryForm(
			left.open + right.open - complete,
			left.closed  + right.closed - complete,
			complete + left.complete + right.complete
		);
	}

	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) {
			if(str[a] == '(') st[i] = QueryForm(1, 0, 0);
			else st[i] = QueryForm(0, 1, 0);
			return;
		}
		int m = (a + b) >> 1;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
		st[i] = Merge(st[2 * i], st[2 * i + 1]);
	}

	QueryForm query(int i, int a, int b) {
		if(lo[i] > b || hi[i] < a) {
			return QueryForm(0, 0, 0);
		}
		if(lo[i] >= a && hi[i] <= b) {
			return st[i];
		}

		QueryForm left = query(2 * i, a, b);
		QueryForm right = query(2 * i + 1, a , b);
		return Merge(left, right);
	}

private:
	std :: string str;
	int n;
	vi lo, hi;
	std :: vector<QueryForm> st;
};

int main() {
	std :: string s;
	std :: cin >> s;
	SegmentTree st(s);

	int qq; scanf("%d", &qq);
	while (qq--) {
		int l, r;
		scanf("%d %d", &l, &r);
		--l, --r;
		printf("%d\n", st.query(l, r));
	}
	return 0;
}

