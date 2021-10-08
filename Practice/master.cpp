#include <bits/stdc++.h>


template<typename T, typename U>
auto prod (T & a, U & b) -> decltype(a * b) {
	return a * b;
}

int main () {
	int a = 10, b = 12;
	auto res = prod(a, b);
	std :: cout << typeid(res).name() << "\n";
	return 0;
}