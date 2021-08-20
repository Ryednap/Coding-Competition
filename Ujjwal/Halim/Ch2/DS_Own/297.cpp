#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// confused in this problem.

struct Node {
	char ch;
	Node * child[4];
	Node ( ) {
		Init ();
	}
		
	Node (char c) {
		Init();
		ch = c;
	}
	
	void Init () {
		for (int i = 0 ; i < 4; ++i) {
			child[i] = nullptr;
		}
	}
};

int p = 0;
Node * Build (const string & s) {
	const int n = (int)s.length();
	if(p >= n) return nullptr;
	char c = s[p++];
	Node * node = new Node(c);
	if(c != 'p') return node;
	
	for(int i = 0; i < 4; ++i) {
		node->child[i] = Build(s);
	}
	return node;
}

void Print (Node * root) {
	if(root == nullptr) return;
	char c = root->ch;
	printf("%c", c);
	for(int i = 0; i < 4; ++i) {
		Print(root->child[i]);
	}
}

Node * Merge (Node * a, Node * b) {
	if(a == nullptr) swap(a, b); // Now b contains the possible nullptr
	if(a == nullptr) return nullptr;
	if(b == nullptr) {
		char c = a->ch;
		Node * node = new Node(c);
		for(int i = 0; i < 4; ++i) {
			node->child[i] = Merge(a->child[i], b);
		}
		return node;
				
	} else {
		char c1 = a->ch;
		char c2 = b->ch;
		char c;
		if(c1 == 'f' || c2 == 'f') c = 'f';
		else if(c1 == 'e' || c2 == 'e') c = 'e';
		else c = 'p';
		Node * node = new Node(c);
		for(int i = 0; i < 4; ++i) {
			node->child[i] = Merge(a->child[i], b -> child[i]);
		}
		return node;
		
	}
}
	

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		string a, b;
		cin >> a >> b;
		
		p = 0;
		Node * t1 = Build(a);
		p = 0;
		Node * t2 = Build(b);
		
		Node * ans = Merge(t1, t2);
		Print(ans);
		puts("");
	}
	return 0;
}
		
