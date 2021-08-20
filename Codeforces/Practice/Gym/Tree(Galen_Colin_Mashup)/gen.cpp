#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
   	printf("200000\n");
   	for(int i = 0; i < 200000; ++i) {
		printf("%d %d\n", rand(10000000,100000000), rand(100000000,1000000000));
	}
	return 0;
}
