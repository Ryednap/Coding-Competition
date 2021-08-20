import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Help {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        System.out.println("Input Row and Col of matrix 1\n");
        int R = fs.nextInt();
        int C = fs.nextInt();

        System.out.println("Input Matrix 1");
        Matrix mat = new Matrix(R, C);
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                int x = fs.nextInt();
                mat.Set(i, j, x);
            }
        }

        System.out.println("Input Row and Col of Matrix 2\n");
        int R2 = fs.nextInt();
        int C2 = fs.nextInt();

        System.out.println("Input Matrix 2");
        Matrix mat2 = new Matrix(R2, C2);
        for(int i = 0; i < R2; ++i) {
            for(int j = 0; j < C2; ++j) {
                int x = fs.nextInt();
                mat2.Set(i, j, x);
            }
        }

        Matrix addRes = mat.Add(mat2);
        Matrix mulRes = mat.Mul(mat2);

        System.out.println("The result of adding is");
        System.out.println(addRes.toString());
        System.out.println(mulRes.toString());
    }

    static class Matrix {
        int Row, Col;
        int [][] Mat;
        Matrix() {
            this.Row = 0;
            this.Col = 0;
        }

        Matrix(int a, int b) {
            this.Row = a;
            this.Col = b;
            Mat = new int[a][b];
        }

        void Set(int i, int j, int x) {
            if(i >= Row || j >= Col)
                return;
            Mat[i][j] = x;
        }

        int Get(int i, int j) {
            if(i >= Row || j >= Col) return -1;
            return Mat[i][j];
        }

        Matrix Add(Matrix b) {
            boolean ok = this.Row == b.Row;
            ok &= (this.Col== b.Col);
            if(!ok) return new Matrix();

            Matrix res = new Matrix(this.Row, this.Col);
            for (int i = 0; i < this.Row; i ++) {
                for(int j = 0; j < this.Col; j++) {
                    int x = Mat[i][j] + b.Get(i, j);
                    res.Set(i, j, x);
                }
            }
            return res;
        }

        Matrix Mul(Matrix b) {
            boolean ok = this.Row == b.Row;
            ok &= (this.Col== b.Col);
            if(!ok) return new Matrix();

            Matrix res = new Matrix(this.Row, this.Col);
            for (int i = 0; i < this.Row; i ++) {
                for(int j = 0; j < this.Col; j++) {
                    int x = Mat[i][j] * b.Get(i, j);
                    res.Set(i, j, x);
                }
            }
            return res;
        }
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
