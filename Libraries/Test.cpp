#include<bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define owo(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

constexpr int Mod = 998244353;
template <typename T>
T inv(T a, T m = Mod) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}


template<class type>
class Modular {
public:
    constexpr Modular () = default;
    Modular (type x) : value (norm(x)) {}
    Modular (const Modular & other) { value = other.value; }
    

    Modular operator + (const Modular & rhs)  const { return make_modular (norm (value + rhs. value)); }
    Modular operator - (const Modular & rhs) const { return make_modular (norm (value - rhs.value)); }
    Modular & operator += (const Modular & rhs) {value = norm (value + rhs.value); return *this; }
    Modular & operator -= (const Modular & rhs) {value = norm (value - rhs.value); return *this; }
    
    Modular operator * (const Modular & rhs) const { return make_modular (norm (1ll * value * rhs.value)); }    
    Modular & operator *= (const Modular & rhs) {value = norm (1ll * value * rhs.value); return *this; }
    Modular operator / (const Modular & rhs) const {return make_modular(norm(1ll * value * inv(rhs.value))); }
    Modular & operator /= (const Modular & rhs) { value = norm(1ll * value * inv(rhs.value)); return *this; }

    Modular & operator ++ () { return *this += 1; }
    Modular & operator -- () { return *this -= 1; }
    Modular  operator ++ (type) { Modular res(*this); *this += 1; return res; }
    Modular  operator -- (type) { Modular res(this); *this -= 1; return res; }
    explicit operator bool () const  { return value != 0; } // make it explicit; else interrupts with + operator
    bool operator ! () const  { return !static_cast<bool> (*this); }
    template<typename T>
    explicit operator T () const { return static_cast<T> (value); }
    

    Modular & operator = (const Modular & rhs) {value = rhs.value; return *this; }
    const type & operator() () const noexcept { return value; }
    bool operator == (const Modular & rhs) const { return value == rhs.value; }
    bool operator != (const Modular & rhs) const { return value != rhs.value; }

    template<typename T, typename U>  friend Modular<T> operator + (const U & other, const Modular<T> & m) { return make_modular(norm(other + m.value)); }
    template<typename T, typename U>  friend Modular<T> operator + (const Modular<T> & m, const U & other) { return make_modular(norm(other + m.value)); }
    template<typename T, typename U>  friend Modular<T> operator - (const U & other, const Modular<T> & m) { return make_modular(norm(other - m.value)); }
    template<typename T, typename U>  friend Modular<T> operator - (const Modular<T> & m, const U & other) { return make_modular(norm(other - m.value)); }
    template<typename T, typename U>  friend Modular<T> operator * (const Modular<T> & m, const U & other) { return make_modular(norm(1ll * other * m.value)); }
    template<typename T, typename U>  friend Modular<T> operator * (const U & other, const Modular<T> & m) { return make_modular(norm(1ll * other * m.value)); }
    template<typename T, typename U>  friend Modular<T> operator / (const Modular<T> & m, const U & other) { return make_modular(norm(1ll * other * inv(m.value))); }
    template<typename T, typename U>  friend Modular<T> operator / (const U & other, const Modular<T> & m) { return make_modular(norm(1ll * other * inv(m.value))); }
    template<typename T, typename U>  friend bool operator == (const U & other, const Modular<T> & m) { return m.value == other; }
    template<typename T, typename U>  friend bool operator == (const Modular<T> & m, const U & other) { return m.value == other; }
    template<typename T, typename U>  friend bool operator != (const U & other, const Modular<T> & m) { return m.value != other; }
    template<typename T, typename U>  friend bool operator != (const Modular<T> & m, const U & other) { return m.value != other; }

    template<typename T>
    friend istream & operator >> (istream & in, Modular<T> & m) {
        type x;  in >> x;
        m.value = norm(x);
        return in;
    }

    template<typename T>
    friend ostream & operator << (ostream & out, const Modular<T> & m) { return (out << m.value); }


private:
    type value;
    template<typename U> static const U norm (const U & x) { return (x % Mod + Mod)%Mod; }
    static const Modular make_modular (const type & x) {Modular m; m.value = x; return m; }
};

using Mint = Modular<int>;
using M64_t = Modular<int64_t>;


vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

/* Mint nCk (int n, int k) {
     if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
  */


int main () {
	return 0;
}