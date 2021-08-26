import java.io.IOException;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

public class Main{
	static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
		
	}
}

class FastScanner {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer token = new StringTokenizer("");

	public String next() {
		while (!token.hasMoreTokens()) {
			try {
				token = new StringTokenizer(br.readLine());
			} catch (IOException ie) {
				ie.printStackTrace();
			}
		}
		return token.nextToken();
	}

	public Integer nextInt() {
		return Integer.parseInt(next());
	}
	public Long nextLong() {
		return Long.parseLong(next());
	}
	public int [] readArray(int n) {
		int [] arr = new int[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = nextInt();
		}
		return arr;
	}
}











