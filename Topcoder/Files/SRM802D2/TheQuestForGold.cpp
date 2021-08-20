#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
#include "uj.h"
#endif

array<int, 4> dx = {-1, 1, 0, 0};
array<int, 4> dy = {0, 0, -1, 1};

using vi = vector<int>;

class TheQuestForGold {
    public:
        string explore (vector<string> cave) {
            const int n = (int)cave.size();
            const int m = (int)cave[0].length();
          /*   debug() << owo(cave); */
            vector<vi> slime(n, vi(m, 0));
            vector<vi> visited(n, vi(m , 0));

            int a = -1, b = -1;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(cave[i][j] == 'S') a = i, b = j;
                    if(cave[i][j] == 'P') {
                        for(int k = 0; k < 4; ++k) {
                            int RR = dx[k] + i;
                            int CC = dy[k] + j;
                            if(RR >= 0 && RR < n && CC >= 0 && CC < m) {
                                slime[RR][CC] = true;
                            }
                        }
                    }
                }
            }
        /*     debug() << owo(slime); */
            bool ok = false;

            auto Valid = [&](int x, int y) {
                if(x < 0 || y < 0 || x >= n || y >= m) return false;
                if(visited[x][y]) return false;
                if(cave[x][y] == 'P') return false;
                return true;
            };

            function <void (int, int) > Dfs = [&] (int x, int y) {
                visited[x][y] = true;
                if(cave[x][y] == 'T') ok = true;
                if(slime[x][y]) return;
                for(int i = 0; i < 4; ++i) {
                    int RR = dx[i] + x;
                    int CC = dy[i] + y;
                    if(Valid(RR, CC)) Dfs(RR,CC);
                }
            };
            
            Dfs(a, b);
            return ok ? "gold" : "no gold";
        }
};
