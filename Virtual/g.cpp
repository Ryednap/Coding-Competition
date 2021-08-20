#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


int main() {
    int qq;
    scanf("%d", &qq);
    while (qq--) {
        string s;
        cin >> s;
        const int n = (int)s.length();

        string answer = "";
        map<char, int> mapper;
        map<char, bool> done;
        for(auto & ch : s) mapper[ch]++;

        for(int i = 0; i < n; ) {
            char ch = s[i];
            if(done[ch]) ++i;
            else if(mapper[ch] == 1) answer += ch, ++i, done[ch] = true;
            else {
                map<char, int> flapper = mapper;
                char maxi = ch;
                int where = i;
                for(int j = i; j < n;  ++j) {
                    char ph = s[j];
                    if(done[ph]) continue;
                    if(ph > maxi) {
                        where = j;
                        maxi = ph;
                    }

                    if(flapper[ph] == 1) {
                        break;
                    }
                    flapper[ph]--;
                    
                }

                answer += maxi;
                done[maxi] = true;
                for(int j = i; j <= where; ++j) {
                    mapper[s[j]]--;
                }
                i = where + 1;
            }
        }

        puts(answer.c_str());
    }
    return 0;
}