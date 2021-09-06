#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


constexpr int Mod  = 998244353;
long long check = 0;    
template<class T>
class Modular {
 public:
    Modular (T x = 0) {
        v = ((x%Mod) + Mod)%Mod;
    }
    Modular (const Modular & m) {
        this-> v = m.v;
    }
    ~Modular() {}

    template <typename U>
    static U inverse (U a, U m = Mod) {
        U u = 0, v = 1;
        try {
            while (a > 0) {
                T t =  m / a;
                m -= t * a;
                u -= t * v;
                swap(a, m); swap(u, v);
            }
            if (m != 1) throw std :: logic_error ("Modular Inverse doesn't exist!!");
        } catch (std :: exception & e) {
            throw e;
        }
    }         
    
    template<typename U>
    Modular & operator = (const U  x) {v = x; return *this;}
    Modular operator + (const Modular & rhs) const { Modular res = *this; return res += rhs;}
    Modular operator - (const Modular & rhs) const { Modular res = *this; return res -= rhs;}
    Modular operator * (const Modular & rhs) const { Modular res = *this; return res *= rhs;}
    Modular operator / (const Modular & rhs) const { try {Modular res = *this; return res /= rhs;
                                                         } catch (std :: exception & e) {throw e;}}
    Modular operator - () const { return Modular (-v);}
    Modular & operator ++ () {return *this += 1;}
    Modular & operator -- () {return *this -= 1;}
    Modular operator ++ (int) {Modular res = *this; *this += 1; return res;}
    Modular operator -- (int) {Modular res = *this; *this -= 1; return res;}
 


    Modular & operator += (const Modular & rhs) { v = ((v + rhs.v)%Mod + Mod)%Mod; return *this;}
    Modular & operator -= (const Modular & rhs) { v = ((v - rhs.v)%Mod + Mod)%Mod; return *this;}
    Modular & operator *= (const Modular & rhs) { v = ((1ll * v * rhs.v)%Mod + Mod)%Mod; return *this;}
    Modular & operator /= (const Modular & rhs) { try { v = *this * (Modular(inverse(rhs.v))); return *this;
                                                      } catch (std :: exception & e) {throw e;} }


    bool operator == (const Modular & rhs) const { return (v == rhs.v);}
    bool operator != (const Modular & rhs) const { return (v != rhs.v);}
    
    template <typename U>
    Modular operator + (const U & val) const {return *this + Modular(val);}
    template <typename U>
    Modular &operator += (const U & val) {return *this += Modular(val);}
    template <typename U>
    Modular operator - (const U & val) const {return *this - Modular(val);}
    template <typename U>
    Modular &operator -= (const U & val) {return *this -= Modular(val);}
    template <typename U>
    Modular operator * (const U & val) {return *this * Modular(val);}
    template <typename U>
    Modular &operator *= (const U & val) {return *this *= Modular(val);}
    template <typename U>
    friend bool operator < (const Modular<U>&, const Modular<U>&);
    template<typename U, typename Z>
    friend Modular<U>  modPow (const Modular<U> &, const Z & val);
    template<typename U>
    friend ostream & operator << (ostream & , const Modular<U> &);
 private:
    T v;
};

template<typename U>
bool operator < (const Modular<U> & lhs, const Modular<U> &rhs) {
    return lhs.v < rhs.v;
}
template<typename T, typename U>
Modular<T> modPow(const Modular<T> & a, const U & b) {
    Modular<T> res (0);
    for (; b; b >>= 1) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
    }
    return res;
}
template<typename T>
ostream & operator << (ostream & out, const Modular<T>&m) {
    return out << m.v;
}

using Mint = Modular<int>;
using Mint64_t = Modular<int64_t>;
using i64 = int64_t;

int main () {
    ios::sync_with_stdio(false);
    int qq; scanf("%d", &qq);
    for (int tt = 1; tt <= qq; ++tt) {
        cout << "Case #" << tt << ": ";
    }
    return 0;
}
