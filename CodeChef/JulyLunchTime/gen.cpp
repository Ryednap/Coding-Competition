// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

long long rand(long long a, long long b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int T = rand(1, 50);
    printf("%d\n", T);
    for (int tt = 0 ; tt < T; ++tt) {
        int n = rand(100, 300);
        printf("%d\n",n);
        for (int i = 0; i < n; ++i) {
            printf("%lld ", rand(1, 1e16));
        }
        puts("");
    }

    return 0;
}