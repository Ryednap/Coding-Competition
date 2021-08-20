#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;

int dx [] = {-1, 1, 0, 0};
int dy [] = {-1, 1, -1, 1};

void Solve() {
    int N, M;
    scanf("%d %d", &N, &M);

    int mat[N][M];
    for(int i = 0 ; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    bool ok = true;
    long long answer = 0;
    while (ok) {
        ok = false;

        vector<pii> eliminate;
        long long roundSum = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(mat[i][j] == -1) continue;
                int sum = 0, total = 0;
                for(int k = 0; k < 4; ++k) {
                    int RR = i + dx[k];
                    int CC = j + dy[k];
                    if(RR >= 0 && RR < N && CC >= 0 && CC < M && mat[RR][CC] != -1) {
                        sum += mat[RR][CC];
                        ++total;
                    }   
                }
                roundSum += mat[i][j];
                if(total && mat[i][j] * total < sum) {
                    eliminate.emplace_back(i, j);
                }
            }
        }

        answer += roundSum;
        if(!eliminate.empty()) {
            ok = true;
            for(auto p : eliminate) {
                mat[p.first][p.second] = -1;
            }
        }
    }

    printf("%lld\n", answer);
}

int main() {
    int qq;
    scanf("%d", &qq);
    for(int tt = 0; tt < qq; ++tt) {
        printf("Case #%d: ", tt + 1);
        Solve();
    }
    return 0;
}