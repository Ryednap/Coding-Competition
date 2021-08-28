import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main {
    static FastScanner fs = new FastScanner();
    public static void main(String[] args) throws IOException {
       int qq = fs.nextInt();
        while (qq-- > 0 ) {
            int n = fs.nextInt();
            long m = fs.nextLong();
            long [] a = fs.readLongArray(n);
            long [] pref = new long[n];
            pref[0] = a[0] % m;
            for (int i = 1; i < n; ++i) {
                pref[i] = (pref[i - 1] % m + a[i] % m)%m;
            }

            long ans = 0;
            TreeMap<Long, Integer> s1 = new TreeMap<Long, Integer> ();
            TreeMap<Long, Integer> s2 = new TreeMap<Long, Integer> ();

            for (int i = 0; i < n; ++i) {
            // safe value add in java
               Integer value = s2.get(pref[i]);
               if (value == null) {
                   value = 0;
               }
               s2.put(pref[i], value + 1);
            }

            for (int i = 0; i < n; ++i) {
                Long next = s2.floorKey(pref[i] - 1);
                Long prev = s1.ceilingKey(pref[i] + 1);

                if (next != null) ans = Math.max(ans, ((next - pref[i])%m + m)%m);
                if (prev != null) ans = Math.max(ans, ((pref[i] - prev)%m + m)%m);
                ans = Math.max(ans, pref[i]);

                
                // safe value add in java
                Integer value = s1.get(pref[i]);
                if (value == null) {
                    value = 0;
                }
                s1.put(pref[i], value + 1);

                // decrement value
                Integer decValue = s2.get(pref[i]);
                assert (decValue != null);
                decValue--;
                if (decValue == 0)
                    s2.remove(pref[i]);
                else s2.put(pref[i], decValue);
               
            }
            System.out.println(ans);
        }
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer("");

        String next () {
            while (!token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer(br.readLine());
                } catch (IOException ie) {
                    ie.printStackTrace();
                }
            }
            return token.nextToken();
        }

        int nextInt () {
            return Integer.parseInt(next());
        }

        long nextLong () {
            return Long.parseLong(next());
        }

        int [] readIntArray (int n) {
            int [] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextInt();
            }
            return a;
        }
        long [] readLongArray (int n) {
            long [] a = new long [n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextLong();
            }
            return a;
        }
    }
}