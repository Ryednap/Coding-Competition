#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

pair<bool, string> Check (vector<string> v, int sig) {
    if(v.empty()) return {true, ""};
    sort(v.begin(), v.end(), [](const string & a, const string & b){
        if(a.size() == b.size()) {
            return a > b;
        } else return (int)a.size() > (int)b.size();
    });
    /* debug() << owo(v); */
    for(int i = 0; i < (int)v[0].size(); ++i) {
        char ch;
        if(sig) ch = v[0][i];
        else ch = v[0][(int)v[0].size() - i - 1];
        for(int j = 1; j < (int)v.size(); ++j) {
            if(sig) {
               /*  debug() << owo(ch) owo(j) owo(i); */
                if(i >= (int)v[j].size()) continue;
                if(ch != v[j][i]) return {false, ""};

            } else {
                int x = (int)v[j].size() - i - 1;
                if(x < 0) continue;
                if(ch != v[j][x]) return {false, ""};
            }

        }
    }


    return {true, v[0]};
}

void Solve() {
    int N;
    scanf("%d", &N);
    vector<vector<string>> vec;
    for(int i = 0; i < N; ++i) {
        string s, get = ""; cin >> s;
        vector<string> v;
        for(char ch : s) {
            if(ch == '*') {
                if(!get.empty()) v.push_back(get);
                v.push_back("*");
                get = "";
            } else get += ch;
        }
        if(!get.empty()) v.push_back(get);
        vec.push_back(v);
    }
    
    vector<string> fc, bc;
    for(int i = 0; i < N; ++i) {
        if(vec[i].front() != "*") fc.push_back(vec[i].front());
        if(vec[i].back() != "*") bc.push_back(vec[i].back());
    }

   /*  debug() << owo(fc) owo(bc) owo(vec); */
    auto a = Check(fc, 1);
    auto b = Check(bc, 0);
   /*  debug() << owo(a) owo(b); */
    bool ok = a.first & b.first;
    if(!ok) {
        puts("*");

    } else {
        string ans = a.second;
        for(int i = 0; i < N; ++i) {
            for(int j = 1; j < (int)vec[i].size() - 1; ++j) {
                if(vec[i][j] != "*") ans += vec[i][j];
            }
        }
        ans += b.second;
        puts(ans.c_str());
    }
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