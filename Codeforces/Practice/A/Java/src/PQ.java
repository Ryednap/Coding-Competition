import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class PQ {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        int N = fs.nextInt(), M = fs.nextInt(); // Number of edges and vertices
        ArrayList<Pair> [] edges = new ArrayList[N + 1];
        for(int i = 0; i < N; ++i) {
            edges[i] = new ArrayList<>();
        }
        HashMap<Character, Integer> mapper = new HashMap<>();
        HashMap<Integer, Character> flapper = new HashMap<>();

        for(int i = 0, j = 0; i < M; ++i) {
            char a = fs.next().charAt(0);
            char b = fs.next().charAt(0);
            int cost = fs.nextInt();

            if(!mapper.containsKey(a)) {
                mapper.put(a, j++);
            }
            if(!mapper.containsKey(b)) {
                mapper.put(b, j++);
            }

            int u = mapper.get(a);
            int v = mapper.get(b);

            flapper.put(u, a);
            flapper.put(v, b);
            edges[u].add(new Pair(v, cost));
        }

        int [] Heuristics = new int[N];
        for(int i = 0; i < N; ++i) {
            char a = fs.next().charAt(0);
            int c = fs.nextInt();
            int node = mapper.get(a);
            Heuristics[node] = c;
        }

        int Goal = mapper.get('G');
        int Source = mapper.get('S');

        PriorityQueue<Triple> pq = new PriorityQueue<>(new Triple(0, 0, 0, ""));

        pq.Push(new Triple(Source, 0, 0, "S "));
        int answer = -1;
        String path = "";
        int [] VisitedCost = new int[N];
        for(int i = 0; i < N; ++i) {
            VisitedCost[i] = (int)1e9;
        }

        while (!pq.isEmpty()) {
            Triple node = pq.Pop();
            if(node.a == Goal) {
                answer = node.b;
                path = node.d;
                break;
            }

            for(Pair child : edges[node.a]) {
               int TotalCost = child.b + node.c + Heuristics[child.a];
               if(TotalCost < VisitedCost[child.a]) {
                   pq.Push(new Triple(child.a, TotalCost, child.b + node.c, node.d + flapper.get(child.a) + " "));
                   VisitedCost[child.a] = TotalCost;
               }
            }
        }
        System.out.println(answer == -1 ? "Not found the goal" : "The Total Cost from S to G is " + answer + "\n");
        System.out.println(path);
    }

    // Priority Queue Implementation
    static class PriorityQueue<T extends Comparable <T>>{
        ArrayList<T> arr;
        PriorityQueue (T dummy) {
            arr = new ArrayList<T>();
            arr.add(dummy);
        }

        void Swap(int a, int b) {
            T ob = arr.get(a);
            arr.set(a, arr.get(b));
            arr.set(b, ob);
        }

        void Push(T x) {
            arr.add(x);
            Swap(1, arr.size() - 1);
            Heapify(1);
        }

        void Heapify(int i) {
            int left = i << 1;
            int right = i << 1 + 1;
            int largest = i;
            if(left < arr.size() && arr.get(left).compareTo(arr.get(largest)) > 0) {
                largest = left;
            }
            if(right < arr.size() && arr.get(right).compareTo(arr.get(largest)) > 0) {
                largest = right;
            }

            if(largest != i) {
                Swap(i, largest);
                Heapify(largest);
            }
        }

        T Pop() {
            T Max = arr.get(1);
            Swap(1, arr.size() - 1);
            arr.remove(arr.size() - 1);
            Heapify(1);
            return Max;
        }
        boolean isEmpty() {
            return arr.size() == 1;
        }
    }

    static class Pair {
        int a, b;
        Pair(int x, int y) {
            a = x;
            b = y;
        }
    }

    static class Triple implements Comparable<Triple> {
        int a, b, c;
        String d;
        Triple() {};
        Triple(int x, int y, int z, String s) {
            a = x;
            b = y;
            c = z;
            d = s;
        }

        @Override
        public int compareTo(Triple o) {
            return o.c - c;
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
