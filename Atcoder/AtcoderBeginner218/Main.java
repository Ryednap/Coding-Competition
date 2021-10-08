import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main {
    static FastScanner fs = new FastScanner();
    static int n;
    static ArrayList<Integer> [] tree;
    static int [] value;
    static int [] mini, maxi;

    public static void main (String [] args) {
        n = fs.nextInt();
        tree = new ArrayList[n + 1];
        for (int i = 0; i <= n; ++i) {
            tree[i] = new ArrayList<Integer>();
        }
        value = fs.readIntArray(n);
        mini = new int[n + 1];
        maxi = new int[n + 1];

        for (int i = 0; i < n - 1; ++i) {
            int a = fs.nextInt(), b = fs.nextInt();
            --a; --b;
            tree[a].add(b);
            tree[b].add(a);
        }
    }


}

class FastScanner {
    public FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        token = new StringTokenizer("");
    }

    public String next () {
        while (!token.hasMoreTokens()) {
            try {
                token = new StringTokenizer(br.readLine());
            } catch (IOException ie) {
                ie.printStackTrace();
            }
        }
        return token.nextToken();
    }

    public int nextInt () {
        return Integer.parseInt(next());
    }

    public long nextLong () {
        return Long.parseLong(next());
    }

    public float nextFloat() {
        return Float.parseFloat(next());
    }

    public double nextDouble() {
        return  Double.parseDouble(next());
    }

    public int [] readIntArray(int n) {
        int [] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = nextInt();
        return a;
    }

    public long [] readLongArray(int n) {
        long [] a = new long[n];
        for (int i = 0; i < n; ++i) a[i] = nextLong();
        return a;
    }
    
    public float [] readFloatArray(int n) {
        float [] a = new float[n];
        for (int i = 0; i < n; ++i) a[i] = nextFloat();
        return a;
    }
    
    public double [] readDoubleArray(int n) {
        double [] a = new double[n];
        for (int i = 0; i < n; ++i) a[i] = nextDouble();
        return a;
    }
    

    private BufferedReader br;
    private StringTokenizer token;
}