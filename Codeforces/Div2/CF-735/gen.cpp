// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int T = rand(1, 100);
    printf("%d\n", T);
    for(int _ = 0; _ < T; ++_) {
       int n = rand(700, 1000);
       int k = rand(1, 100);
       k = min(k, n);
       printf("%d %d\n", n, k);
       for(int i = 0; i < n; ++i) {
            printf("%d ", rand(1, 1000));
       }
    }
    return 0;
}