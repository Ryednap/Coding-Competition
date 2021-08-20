#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

double Area(double a,double b, double c){
	double s = (a + b + c)/2.0;
	if(s < a || s < b || s < c) return -1;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
const double EPS = 1e-6;
void solve(){
	int n;
	scanf("%d", &n);
	
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}
	sort(arr, arr + n);
	vector<double> ans;
	for(int i = 0; i < n ; ++i){
		for(int j = i + 1; j < n; ++j){
			double a = sqrt(1 + arr[i] * arr[i]);
			double b = sqrt(1 + arr[j] * arr[j]);
			double c = abs(arr[i] - arr[j]);
			double x = Area(a, b, c);
			if(x > 0) ans.push_back(x);
		}
	}
	
	sort(ans.begin() ,ans.end());
	int tot = 0;
	double prev = -1;

	for(int i = 0; i < (int)ans.size(); ++i){
		if(ans[i] - prev > EPS) ++tot;

		prev = ans[i];
	}
	printf("%d\n",tot);
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;
}
