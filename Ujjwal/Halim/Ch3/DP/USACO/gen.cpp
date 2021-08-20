#include "bits/stdc++.h"

int rand(int a, int b) {
    return rand() % (b - a + 1);
}

int main(int argc, char ** argv) {
    srand(atoi(argv[1]));

    int n = 10, m = rand(1, 500);
    printf("%d %d\n", n, m);
    for(int i = 0; i < n; ++i) {
        printf("%d\n", rand(1, 1000));
    }
    return 0;
}
