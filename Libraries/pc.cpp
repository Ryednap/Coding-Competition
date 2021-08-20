#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second
#include "uj.h"

static bool comp(pair<int, int> & a, pair<int, int>  & b) {
	if((long long)a.f + a.s == (long long)b.f + b.s) {
		return a.f >= b.f;
		
	} else {
		return (long long)a.f + a.s > (long long)b.f + b.s;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	pii arr[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &arr[i].f, &arr[i].s);
	}
	sort(arr, arr + n, comp);
	long long total = 0;
	for(int i = 0; i < n; ++i){
		total += arr[i].f;
	}
		
	
	long long a = 0, b = 0;
	for(int i = 0; i < n; ++i){
		a += arr[i].f + arr[i].s;
		b -= arr[i].f;
		if(a > b) {
			printf("%d\n", i + 1);
			break;
		}
	}
	return 0;
}
