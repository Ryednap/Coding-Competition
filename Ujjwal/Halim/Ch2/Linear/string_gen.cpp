#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
	return rand()%(b - a + 1);
}
string rand_str(int a, int b) {
	int n = rand(a, b);
	string s = "";
	for(int i =  0; i < n; ++i) {
		s += rand(0, 25) + 'a';
	}
	return s;
}

int main(int argv, char **argc) {
	srand(atoi(argc[0]));
	for( int i = 0; i < 1e4; ++i) {
		printf("%d\n", rand(1, 1e9));
	}
	return 0;
}
