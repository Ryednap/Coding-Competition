import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;

public class Main {
	static FastScanner fs = new FastScanner();

	public static void main(String[] args) throws IOException {
		String password = fs.next();
		boolean different = true;
		boolean follows = true;
		for (int i = 0; i < 3; ++i) {
			int digitHere = password.charAt(i) - '0';
			int digitFor = password.charAt(i + 1) - '0';
			if(digitHere != digitFor)
				different = false;
			if((digitHere + 1)%10 != digitFor)
				follows = false;
		}
		if(different | follows)
			System.out.println("Weak");
		else 
			System.out.println("Strong");
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