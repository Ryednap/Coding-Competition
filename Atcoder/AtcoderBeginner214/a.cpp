#include <bits/stdc++.h>
using namespace std;

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using vpi = std::vector<pii>;
using vvpi = std::vector<vpi>;


#define f first
#define s second
#define len length()

int main () {
	int n;
	scanf ("%d", &n);
	if (n <= 125) 
		puts ("4");
	else if(n <= 211)
		puts ("6");
	else puts("8");
	return 0;
}