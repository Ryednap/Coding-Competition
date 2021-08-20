    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.math.BigInteger;
    import java.util.ArrayList;
    import java.util.Collections;
    import java.util.StringTokenizer;


    public class E {
        static FastScanner fs = new FastScanner();

        public static void main(String[] args) {
                int T = fs.nextInt();
                for(int i = 0; i < T ; ++i){
                    int N = fs.nextInt(), S = fs.nextInt(), K =fs.nextInt();
                    int d = Gcd(N,Gcd(K,S));
                    if(N%d != 0){
                        System.out.println(-1);
                    } else{
                        N /= d;
                        S /= d;
                        K /= d;
                        long inv = modInverse(K, N);
                        if(inv == -1){
                            System.out.println(-1);
                            continue;
                        }
                        long answer = Mul(inv, -S, N);
                        System.out.println(answer);
                    }

                }
        }
        static int Mul(long a, int b, int Mod){
            return (int)( (a * b)%Mod + Mod)%Mod;
        }
        static int Gcd(int a, int b){
            return b > 0 ? Gcd(b, a%b) : a;
        }

        static long  modInverse(int a, int b){
            int d = Gcd(a, b);
            if(d != 1) {
                return -1;
            }
            BigInteger n1 = new BigInteger(String.valueOf(a));
            BigInteger n2 = new BigInteger(String.valueOf(b));
            BigInteger res = n1.modInverse(n2);
            return Long.parseLong(res.toString());
        }
        static void sort(int[] a) {
            ArrayList<Integer> list = new ArrayList<>();
            for (int i : a) list.add(i);
            Collections.sort(list);
            for (int i = 0; i < a.length; ++i) a[i] = list.get(i);
        }

        static class FastScanner {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer token = new StringTokenizer("");

            String next() {
                while (!token.hasMoreTokens()) {
                    try {
                        token = new StringTokenizer(br.readLine());
                    } catch (IOException ie) {
                        ie.printStackTrace();
                    }
                }
                return token.nextToken();
            }

            public int nextInt() {
                return Integer.parseInt(next());
            }

            public int[] readArray(int n) {
                int[] a = new int[n];
                for (int i = 0; i < n; ++i)
                    a[i] = nextInt();
                return a;
            }

            public long nextLong() {
                return Long.parseLong(next());
            }

            public long[] readLongArray(int n) {
                long[] a = new long[n];
                for (int i = 0; i < n; ++i) a[i] = nextLong();
                return a;
            }

            public double nextDouble() {
                return Double.parseDouble(next());
            }

            public double[] readDoubleArray(int n) {
                double[] a = new double[n];
                for (int i = 0; i < n; ++i) a[i] = nextDouble();
                return a;
            }
        }
    }