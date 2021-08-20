// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int T = 1;
    printf("%d\n", T);
    for(int i = 0; i < T; ++i) {
        int l = rand(1, 3000);
        int r = rand(l, 3000);
        assert(r >= l );
        printf("%d %d\n", l, r);
    }
    return 0;
}