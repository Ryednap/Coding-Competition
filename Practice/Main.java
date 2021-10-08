import java.io.IOException;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

class HairSalon implements Comparable <HairSalon> {

	HairSalon () {}
	HairSalon (String service, double price, int time) {
		this.service = service;
		this.price = price;
		this.time = time;
	}

	@Override
	public int compareTo (HairSalon rhs) {
		Double here = this.price;
		Double other = rhs.price;
		return here.compareTo(other);
	}

	public void Display() {
		System.out.println ("Service : " + this.service +  " Price : " + this.price + " time : " + this.time);
	}

	private String service;
	private double price;
	private int time;
}

public class Main {
	public static void main (String [] args) {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		HairSalon [] a = new HairSalon[n];
		for (int i = 0; i < n; ++i) {
			String service = fs.next();
			double price = fs.nextDouble();
			int time = fs.nextInt();
			a[i] = new HairSalon(service, price, time);
		}
		Arrays.sort (a);
		for (HairSalon ob : a) {
			ob.Display();
		}
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
	public Double nextDouble () {
		return Double.parseDouble(next());
	}
	public int [] readArray(int n) {
		int [] arr = new int[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = nextInt();
		}
		return arr;
	}
}











