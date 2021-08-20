#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int Query (int a, int b, int c) {
    printf("%d %d %d\n", a, b, c);
    fflush(stdout);
    int get;
    scanf("%d", &get);
    debug() << owo(a) owo(b) owo(c) owo(get);
    return get - 1;
}

int N, C;
int total = 0;
void Solve() {

    vector<int> answer;
    vector<int> next(N);
    for(int i = 1; i <= N; ++i) {
        next[i - 1] = N - i + 1;
    }

    auto Get_next = [&] () {
        int x = next.back();
        next.pop_back();
        return x;
    };

    answer.push_back(Get_next());
    answer.push_back(Get_next());


    while ((int)answer.size() < N) {
        int x = Get_next();
        int lo = 0, hi = (int)answer.size() - 1;
        while (lo <= hi) {
            if(lo + 1 == hi) {
                int a = answer[lo], b = answer[hi];
                int res = Query(a, b, x);
                if(res == a) {
                    answer.insert(answer.begin() + lo, x);
                } else if(res == x) {
                    answer.insert(answer.begin() + lo, x);
                } else {
                    answer.insert(answer.begin() + hi, x);
                }
                break;
            }
            int mid = (lo + hi) >> 1;
            int a = answer[mid], b = answer[hi];
            int res = Query(a, b , x);
            if(res == x) {
                lo = mid;
            } else if(res == a) {
                hi = mid;
            } else {
                answer.insert(answer.begin() + hi + 1, x);
                break;
            }
        }
        
        debug() << owo(answer);
    }
   
    printf("%d", answer[0]);
    for(int i = 1; i < N; ++i) {
        printf(" %d", answer[i]);
    }
    
    puts("");
    fflush(stdout);
    int verdict;
    scanf("%d", &verdict);
    if(verdict == -1) {
        exit(0);
    }
}

int main() {
	int qq;
	scanf("%d %d %d", &qq, &N, &C);
	for(int i = 1; i <= qq; ++i) {
		Solve();
	}
	
	return 0;
}
	
