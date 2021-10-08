#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
T inv (T a, T m = Mod) {
    T u = 0, v = 1;
    while (a != 0) {
        T x = m / a;
        m -= x * a; swap (a, m);
        u -= x * a; swap (u, v); 
    }
    assert (m == 1);
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

    Modular operator -() const { return Modular(-value); }
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
    bool operator < (const Modular & rhs) const { return value < rhs.value; }
    bool operator <= (const Modular & rhs) const { return value < rhs.value; }
    bool operator > (const Modular & rhs) const { return value > rhs.value; }
    bool operator >= (const Modular & rhs) const { return value >= rhs.value; }

    template<typename T, typename U>  friend Modular<T> operator + (const U & other, const Modular<T> & m) { return make_modular(norm(other + m.value)); }
    template<typename T, typename U>  friend Modular<T> operator + (const Modular<T> & m, const U & other) { return make_modular(norm(other + m.value)); }
    template<typename T, typename U>  friend Modular<T> operator - (const U & other, const Modular<T> & m) { return make_modular(norm(other - m.value)); }
    template<typename T, typename U>  friend Modular<T> operator - (const Modular<T> & m, const U & other) { return make_modular(norm(m.value - other)); }
    template<typename T, typename U>  friend Modular<T> operator * (const Modular<T> & m, const U & other) { return make_modular(norm(1ll * other * m.value)); }
    template<typename T, typename U>  friend Modular<T> operator * (const U & other, const Modular<T> & m) { return make_modular(norm(1ll * other * m.value)); }
    template<typename T, typename U>  friend Modular<T> operator / (const Modular<T> & m, const U & other) { return make_modular(norm(1ll * m.value * inv(other))); }
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
    template<typename T, typename U>
    friend Modular<T> power (const Modular<T> & a, const U & b);

private:
    type value;
    template<typename U> static const U norm (const U & x) { return (x % Mod + Mod)%Mod; }
    static const Modular make_modular (const type & x) {Modular m; m.value = x; return m; }
};
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 

using Mint = Modular<int>;
using M64_t = Modular<int64_t>;

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Minimum {
  T operator () (const T & lhs, const T & rhs) const {
    return std :: min (lhs, rhs);
  }
};

template<typename T>
struct Maximum {
  T operator () (const T & lhs, const T & rhs) const {
    return std :: max(lhs, rhs);
  }
};

template<typename T, typename AssociativeOperation>
struct SegmentTree {
  SegmentTree (vector<T> arr, T _identity, AssociativeOperation op) : 
      v(arr), identity(_identity), operation(op) {
    const int n = (int)arr.size();
    lo.resize(4 * n + 1);
    hi.resize(4 * n + 1);
    st.resize(4 * n + 1, identity);
    init (1, 0, n - 1);
  }
  SegmentTree (int n, T _identity, AssociativeOperation op) : 
      identity(_identity), operation(op) {
    lo.resize(4 * n + 1);
    hi.resize(4 * n + 1);
    st.resize(4 * n + 1, identity);
    init (1, 0, n - 1);
  }

  void init (int i, int a, int b) {
    lo[i] = a; hi[i] = b;
    if (a == b) {
      if (!v.empty()) {st[i] = v[a];debug() << owo(v[a]) owo(st[i]);}
      return;
    }
    int m = (a + b) >> 1;
    init ((i << 1), a, m);
    init ((i << 1) + 1, m + 1, b); 
    st[i] = operation(st[i << 1], st[(i << 1) + 1]);
  }

  T query (int a, int b) { return query(1, a, b);} // range query
  T query (int a) {return query(1, 0, a);} // point query
  void update (int pos, T val) {update(1, pos, val);} // point update

private:
  T query (int i, int a, int b) {
    if (lo[i] > b  || hi[i] < a) return identity;
    if (lo[i] >= a && hi[i] <= b) { return st[i]; }
    return operation (query((i << 1), a, b), query((i << 1) + 1, a, b));
  }
  void update (int i, int pos, T val) {
    if (lo[i] > pos || hi[i] < pos) return;
    if (lo[i] == hi[i] && lo[i] == pos) {st[i] = val;return;}
    update((i << 1), pos, val);
    update((i << 1) + 1, pos, val);
    st[i] = operation (st[i << 1], st[(i << 1) + 1]);
  }

private:
  vector<T> st, v;
  vector<int> lo, hi;
  T identity;
  AssociativeOperation operation;
};

Maximum<int> MaxiInt;
Minimum<int> MiniInt;

using pii = pair<int, int>;

int main () {
  int n; cin >> n;
  map<pii, int> mapper;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mapper[pii(v[i], i + 1)] = 0;
  }
  

  vector<Mint> arr;
  int ii = 0;
  for (auto & p : mapper) arr.push_back(power(Mint(2), p.first.second)), p.second = ii++;

  SegmentTree<Mint, plus<Mint>> st(arr, Mint(0), plus<Mint>());
  debug() << owo(mapper) owo(arr);
  Mint ans = 0;
  for (int i = 0; i < n; ++i) {
    assert (mapper.find(pii(v[i], i + 1)) != mapper.end());
    auto p = mapper.lower_bound(pii(v[i], 0));
    debug() << owo(p);
    // ans += st.query(p, n - 1) / power(Mint(2), i + 2);
    // debug() << owo(v[i]) owo(p) owo(st.query(p, n - 1));
    // st.update(p, -power(Mint(2), i + 2));
  }
  cout << ans << endl;
  return 0;
}


