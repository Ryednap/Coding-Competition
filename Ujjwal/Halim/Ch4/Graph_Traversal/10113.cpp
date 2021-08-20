#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*

T 000:34:02.354
T 000:13:14.375

*/


using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using piii = std::pair<int, pii>;

#define f first
#define s second

struct Frac {
	int n, d;
	Frac () {}
	Frac (int a, int b) : n(a / __gcd(a, b)), d(b / __gcd(a, b)) {}
	Frac operator * (const Frac & f) {
		return Frac (f.n * n, f.d * d);
	}
};

vector<vector<pair<int, Frac>>> edges(256);
vi used(256);
Frac queryAns;

void dfs (int from, int dest, Frac cost) {
	used[from] = true;	
	if (from == dest) {
		queryAns = cost;
		return;
	}
	for (auto to : edges[from]) {
		if (!used[to.f])
			dfs (to.f, dest, cost * to.s);
	}
}

int main () {
	std:: string command;
	std:: map<string, int> mapper;
	int cnt = 0;

	while (getline(std::cin, command)) {
		if (command == ".")
			break;
		stringstream ss(command);
		std::string s;
		vector<string> v;
		while (ss >> s) {
			v.push_back(s);
		}
		if(v[0] == "!") {
			int a = stoi(v[1]);
			int b = stoi(v[4]);
			string item1 = v[2];
			string item2 = v[5];

			if (mapper.find(item1) == mapper.end()) {
				mapper[item1] = cnt++;
			}
			if (mapper.find(item2) == mapper.end()) {
				mapper[item2] = cnt++;
			}

			int uu = mapper[item1];
			int vv = mapper[item2];
			edges[uu].emplace_back(vv, Frac (a, b));
			edges[vv].emplace_back(uu, Frac (b, a));

		} else {
			queryAns = Frac(0, 1);
			used = vi(256);
			dfs (mapper[v[1]], mapper[v[3]], Frac(1, 1));
			if (queryAns.n == 0) {
				printf("? %s = ? %s\n", v[1].c_str(), v[3].c_str());
			} else {
				printf ("%d %s = %d %s\n", queryAns.n, v[1].c_str(), queryAns.d, v[3].c_str());
			}
		}
	}
}
