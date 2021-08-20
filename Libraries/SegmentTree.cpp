#include<bits/stdc++.h>

const int nax = (int)2e5 + 10; 
int t[nax]; // set the size 4 times the input.
int arr[nax];

void Build(int i, int lo, int hi) {
	if(lo == hi) {
		t[i] = a[lo];
	} else {
		int mid = (lo + hi)/2;
		Build(2 * i, lo, mid);
		Build(2 * i + 1, mid + 1, hi);
		t[i] = t[2 *i] + t[2 * i + 1];
	}
}

void Update(int i, int lo, int hi, int val ,int pos) {
	if(lo == hi) {
		t[lo] = val;

	} else {
		int mid = (lo + hi)/2;
		if(mid <= pos) {
1			Update(2 * i + 1, mid + 1, hi, val, pos);

		} else {
			Update(2 * i, lo , mid, val, pos);
			
		}
		t[i] = t[2 *i] + t[2 *i + 1];
	}
}

int Sum(int i, int lo, int hi

int main(){
	return 0;
}
