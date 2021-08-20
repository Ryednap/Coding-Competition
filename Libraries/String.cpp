#include <bits/stdc++.h>

static inline void ltrim(std :: string & s) {
	s.erase(s.begin(), std :: find_if(s.begin(), s.end(), [] (unsigned char ch)  {
		return !std :: isspace(ch);
	}));
}

static inline void rtrim(std :: string & s) {
	s.erase(std :: find_if(s.rbegin(), s.rend(), [] (unsigned char ch ) {
		return !std :: isspace(ch);
	}).base(), s.end());
}

static inline void trim(std :: string & s) {
	ltrim(s);
	rtrim(s);
}

static inline std :: string toString (char sc [] , int n ) {
	std :: string s = "";
	for(int i = 0; i < n; ++i) {
		s += sc[i];
	}
	return s;
}

int main() {
	return 0;
}
