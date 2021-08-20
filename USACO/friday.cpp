/*
ID: ujjwal.9
TASK: friday
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
// C++14

#ifdef LOCAL
#include "uj.h"
#endif

int months[] = {31,28, 31,30,31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int year) {
	if(year % 100 != 0) {
		return year % 4 == 0;
	} else return year % 400 == 0;
}


int main(){
	
	freopen("friday.in", "rt", stdin);
	freopen("friday.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	array<int, 7> ans = {0};
	
	int year = 1900, month = 0, din = 1, day = 1;
	
	while(year < 1900 + n) {
		if(leap(year)) months[1] = 29;
		else months[1] = 28;
		
		if(day == 13) {
			ans[din%7] ++;
		}
		
		++day;
		din = (din + 1)%7;
		if(day > months[month]) {
		
			++month;
			day = 1;
		}
		if(month == 12) {
			month = 0;
			++year;
		}
	}
	printf("%d", ans[6]);
	for(int i = 0; i < 6; ++i) {
		printf(" %d", ans[i]);
	}

	puts("");
	return 0;
}
