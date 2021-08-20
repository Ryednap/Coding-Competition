import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class C {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
        int n = fs.nextInt();
        int [] A = new int[n + 2];
        A[0] = A[n + 1] = 0;
        for(int i = 1; i <= n; ++i) {
            A[i] = fs.nextInt();
        }
        RangeMinQuery rmq = new RangeMinQuery(n + 2);
        rmq.buildTree(A, 0, n + 1, 0);

        long answer = 0;
        for(int i = 1; i <= n; ++i) {
            int lo = 0, hi = i;
            int pos = 0;
            while(lo <= hi) {
                int mid = (lo + hi)/2;
                if(rmq.query(A, mid, hi) < A[i]) {
                    lo = mid + 1;
                    pos = lo;
                } else hi = mid - 1;
            }
            long maybe =  (long)A[i] * (i - pos);
            lo = i;
            hi = n + 1;
            while(lo <= hi) {
                int mid = (lo + hi)/2;
                if(rmq.query(A, i, mid) < A[i]) {
                    hi = mid - 1;
                    pos = mid;
                } else lo = mid + 1;
            }
            maybe += (long)A[i] * (pos - i);
            answer = Math.max(maybe, answer);
        }
        System.out.println(answer);

    }

    static class RangeMinQuery
    {
        static int [] tree;
        private final static int INF=Integer.MAX_VALUE-1;
        private final static int STARTINDEX=0;
        private final int ENDINDEX;

        RangeMinQuery(int size)
        {
            ENDINDEX=size-1;
            int height=2*(int)Math.pow(2,Math.ceil(Math.log(size)/Math.log(2)));
            tree=new int[height];
            for(int i=0;i<height;i++)tree[i]=INF;
        }
        private void buildTree(int [] a,int left,int right,int root)
        {
            if(left==right)
            {
                tree[root]=a[left];return;
            }
            int mid=(left+right)/2;
            buildTree(a,left,mid,2*root+1);
            buildTree(a,mid+1,right,2*root+2);
            tree[root]=Math.min(tree[2*root+1],tree[2*root+2]);
        }
        private int query(int []a,int qs,int qe)
        {
            return queryUtil(a,STARTINDEX,ENDINDEX,qs,qe,0);
        }
        private int queryUtil(int [] a,int l,int r,int qs,int qe,int root)
        {
            int left=2*root+1,right=left+1;
            if(l>=qs && r<=qe)return tree[root];
            if(l>qe || r<qs)return INF;
            int mid=(l+r)/2;
            return Math.min(queryUtil(a,l,mid,qs,qe,left),queryUtil(a,mid+1,r,qs,qe,right));
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