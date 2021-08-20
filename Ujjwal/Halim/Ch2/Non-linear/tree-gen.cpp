// generating a tree in a simple way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    string a , b;
    for(int i = 0; i < (int)1e5; ++i) {
		a += (char) ('a' + rand(0, 24));
		b += (char) ('a' + rand(0, 24));
	}
	puts(a.c_str());
	puts(b.c_str());
	return 0;
}
