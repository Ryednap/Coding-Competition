#include <bits/stdc++.h>

using namespace std;

int main() {
	map<char, int> mapper;
	int n;
	scanf("%d", &n);
	char s[n]; scanf("%s", s);
	for(int i = 0; i < n; ++i) {
		char ch = s[i];
		mapper[ch]++;
	}
	string ans = "coderams";
	int result = n + 10;
	for(auto ch : ans) {
		result = min(result, mapper[ch]);
	}
	printf("%d\n", result);
	return 0;
}
