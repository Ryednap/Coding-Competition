#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;
using pii = pair< int, int> ;
#define f first
#define s second

vector<int> parent(nax);
vector<int> apea(nax);
int Get(int a) {
	if(parent[a] == a) return a;
	else return parent[a] = Get(parent[a]);
}
long long nC2(int n) {
	return ( (long long) n * (n - 1)) /2;
}
void Union(int a, int b, long long & val){
	a = Get(a);
	b = Get(b);
	if(a != b) {
		if(apea[a] < apea[b]) swap(a, b);
		int x = apea[a], y = apea[b];
		val += (long long)x * y;

		apea[a] += apea[b];
		parent[b] = a;
	}
}


struct Node{
	int a, b, w;
	Node() {}
	bool operator < (const Node & n) {
		return w < n.w;
	}
};

//debug & operator << (debug & d, const Node & n) {
	//d << "( " << n.a << " " << n.b << " " << n.w << " )";
	//return d;
//}



long long ans[nax];
int main() {
	for(int i = 0; i < nax; ++i){
		parent[i] = i;
		apea[i] = 1;
	}
	
	int n , qq;
	scanf("%d %d", &n, &qq);
	vector<Node> edges(n - 1);
	for(int i = 0; i < n - 1; ++i) {
		scanf("%d%d%d", &edges[i].a, &edges[i].b , &edges[i].w);
	}
	sort(edges.begin(), edges.end());

	pii q[qq];
	for(int i = 0; i < qq; ++i) {
			scanf("%d", &q[i].f);
			q[i].s = i;
	}
	
	sort(q, q +qq);
	long long prev = 0;
	
	for(int i = 0, j = 0; i < qq; ++i) {
		//debug() << owo(q[i]);
		while(j < n - 1 && edges[j].w <= q[i].f) {
			Union(edges[j].a, edges[j].b, prev);
			++j;
		}
		ans[q[i].s] = prev;
		//debug() << owo(m);
	}
	
	for(int i = 0; i < qq; ++i){
			printf("%lld ", ans[i]);
	}
	return 0;
}
