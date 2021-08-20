#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	 int a, b;
	 scanf("%d %d", &a, &b);
	 puts(a * 6 >= b && b >= a? "Yes" : "No");
	return 0;
}