#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int qq;
	scanf("%d", &qq);
	cin >> ws;
	while (qq--) {
		string s, take;
		getline(cin, s);
		vector<long long> maxi, mini;
		stringstream ss1(s);
		while (getline(ss1, take, '*')) {
			stringstream ss(take);
			long long sum = 0;
			string num;
			while (getline(ss, num, '+')) {
				sum += stoll(num);
			}
			maxi.push_back(sum);
		}
		
		stringstream ss2(s);
		while (getline(ss2, take, '+')) {
			stringstream ss(take);
			long long mul = 1;
			string num;
			while (getline(ss, num, '*')) {
				mul *= stoll(num);
			}
			mini.push_back(mul);
		}
		
		long long a = accumulate(maxi.begin(), maxi.end(), 1LL, std :: multiplies<long long>());
		long long b = accumulate(mini.begin(), mini.end(), 0LL);
		
		printf("The maximum and minimum are %lld and %lld.\n", a, b);
	}
		
	return 0;
}
