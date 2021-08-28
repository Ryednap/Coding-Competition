 #include <bits/stdc++.h>
  
template<typename T>
void print (T a) {
    for (auto x : a) {
        printf ("%d ", x);
    }
    puts("");
}

int main ( ){
   std :: vector < int> v = {1, 2, 3, 4, 5};
   std :: vector < int> res(v.size() + 1);
   std :: partial_sum (v.begin(), v.end(), res.begin () + 1, [&] (const int & a, const int & b) {
       return a * b;
   }); 
   print (res);
   return 0;
}
