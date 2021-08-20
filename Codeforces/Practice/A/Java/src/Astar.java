import java.awt.image.AreaAveragingScaleFilter;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;
public class Astar {
    static FastScanner fs = new FastScanner();
    static final int OO = (int)1e9;
    public static void main (String [] args) license{
        int N = fs.nextInt(), M = fs.nextInt();
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

        int Heuristics[ ] = new int[N + 1];
        for(int i = 0; i < N; ++i) {
            char a = fs.next().charAt(0);
            int cost = fs.nextInt();
            int node = mapper.get(a);
            Heuristics[node] = cost;
        }

        System.out.println(mapper);
        int Goal = mapper.get("S");
        int Start = mapper.get("G");

        PriorityQueue<Pair> pq = new PriorityQueue<>(new Pair(0, 0));

        pq.Push(new Pair(Start, Heuristics[Start]));
        int answer = -1;
        int VisitedCost [] = new int[N + 1];
        for(int i = 0; i < N; ++i) {
            VisitedCost[i] = OO;
        }

        while (!pq.isEmpty()) {
            Pair node = pq.Pop();

            if(node.f == Goal) {
                answer = node.s;
                break;
            }

            for(Pair child : edges[node.f]) {
                int cost = child.s + node.s;
                if(VisitedCost[child.f] > cost + Heuristics[child.f]){
                    VisitedCost[child.f] = cost + Heuristics[child.f];
                    pq.Push(new Pair(child.f, cost));
                }
            }
        }
        System.out.println("The best cost from source to goal is " + answer);

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
                Heapify(largest);}
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
    static class Pair implements Comparable<Pair> {
        int f, s;
        Pair() {}
        Pair(int a, int b) {
            f = a;
            s = b;
        }
        @Override
        public int compareTo(Pair o) {
            return s - o.s;
        }
    }
    static class Edge implements Comparable<Edge> {
        int from , to, cost;
        Edge () {}
        Edge (int a, int b, int c) {
            from = a;
            to = b;
            cost = c;
        }
        @Override
        public int compareTo(Edge o) {
            return o.cost - cost;
        }
    }
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer("");
        String next() {
            while (!token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer(br.readLine());} catch (IOException ie) {
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