
/*
    trivial floyd warshall
    you can just copy the loop.
    assuming OO is defined as infinity.     

    Note that we can solve the variant also just change the assignment condition


    For trans-closure : dp[i][j] = dp[i][k] | dp[k][j]
    For maxi-min : dp[i[j] = min (dp[i][j], max (dp[i][k], dp[k][j]))
*/


void floydWarshall (vector<vector<int>> & dp) {
    const int n = (int)dp.size();
    for (int k = 0; k < n; ++k) {       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][k] < OO && dp[k][j] < OO) dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][i]);
            }
        }
    }
}


/*
    floyd Warshall to store the path

*/

void floydWarshall (vector<vector<int>> & dp, vector<vector<int> & p) {
    const int n = p.size();
    for (int i = 0; i < n; ++i) {
        p[i][i] = i;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][k] < OO && dp[k][j] < OO && dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    dp[i][j] = k;
                }
            }
        }
    }
}
