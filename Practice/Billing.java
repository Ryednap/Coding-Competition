import java.io.IOException;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

public class Billing{
	public static double computeBill (double pPrice) {
        return pPrice * 108 / 100.0;
    }

    public static double computeBill (double pPrice, int quant) {
        return pPrice * quant * 108 / 100.0;

    }

    public static double computeBill (double pPrice, int quant, double cVal) {
        return (pPrice * quant - cVal) * 108 / 100.0;

    }


// start of main method
    static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
        System.out.println(computeBill(45.23));
        System.out.println(computeBill(45.23, 10));
        System.out.println(computeBill(45.23, 10, 100.00));
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











