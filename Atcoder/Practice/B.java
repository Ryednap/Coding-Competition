import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;

public class B {
	static FastScanner fs = new FastScanner();

	public static void main(String[] args) throws IOException {
		int a = fs.nextInt();
		int b = fs.nextInt();
		if(a + b == a)
			System.out.println("Gold");
		else if(a + b == b)
			System.out.println("Silver");
		else 
			System.out.println("Alloy");
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

		int nextInt() {
			return Integer.parseInt(next());
		}
		int [] readArray(int n) {
			int [] a = new int [n + 1];
			for (int i = 0; i < n; ++i) {
				a[i] = fs.nextInt();
			}
			return a;
		}
	}
}