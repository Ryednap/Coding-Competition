import java.io.IOException;
import java.util.*;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

public class Main{
	static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
		Problems ob = new Problems();
		int n = fs.nextInt();
		String [] s = new String[n];
		for (int i = 0; i < n; ++i) {
			s[i] = fs.next();
		}
		int [][] medal = new int[n][3];
		for (int i = 0; i < n; ++i) {
			medal[i] = fs.readArray(3);
		}
		int [] res = ob.countryTotal(s, medal);
		for (int i = 0; i < n; ++i) {
			System.out.println("Country Total for " + s[i] + " = " + res[i]);
		}
	}
}

class FastScanner {
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

	Integer nextInt() {
		return Integer.parseInt(next());
	}
	Long nextLong() {
		return Long.parseLong(next());
	}
	int [] readArray(int n) {
		int [] arr = new int[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = nextInt();
		}
		return arr;
	}
}

class Pair implements Comparable<Pair>{
	String f;
	int [] s;
	Pair () {}
	Pair (String a, int [] b) {
		this.f = a;
		this.s = b;
	}

	@Override
	public int compareTo(Pair p) {
		if (p.s[0] - this.s[0] == 0) {
			if (p.s[1] - this.s[1] == 0) {
				return p.s[2] - this.s[2];
			} else return p.s[1] - this.s[1];
		}
		return p.s[0] - this.s[0];
	}

	@Override
	public String toString() {
		String res = "( " +  this.f + " " + this.s + " )";
		return res;
	}
}


class Problems {
	int [] countryTotal (String [] countryName, int [][] meadalTally) {
		final int n = countryName.length;
		final int m = meadalTally[0].length;
		int [] ans = new int [n];
		for (int i = 0; i < n; ++i) {
			ans[i] = IntStream.of(meadalTally[i]).sum();
		}
		return ans;
	}

	int [] medalTally (String medalType, int [][] medalTally) {
		final int n = medalTally.length;
		int [] ans = new int[n];
		int pos = 0;
		if (medalType.compareTo("Silver") == 0)
			pos = 1;
		else if (medalType.compareTo("Bronze") == 0)
			pos = 2;
		for (int i = 0; i < n; ++i) {
			ans[i] = medalTally[i][pos];
		}
		return ans;
	}
	int position (String [] countryName, int [][] medalTally) {
		final int n = countryName.length;
		Pair [] a = new Pair[n];
		for (int i = 0; i < n; ++i) {
			a[i] = new Pair (countryName[i], medalTally[i]);
		}
		Arrays.sort(a);
		for (int i = 0; i < n; ++i) {
			if (a[i].f.compareTo("India") == 0)
				return i + 1;
		}
		return -1;
	}

	void temperatureInterface (int [][] temp) {
		final int n = temp.length;
		final int m = temp[0].length;

		int currMin = (int)1e9, currMax = -(int)1e9;
		int minDay = -1, maxDay = -1;
		int minCity = -1, maxCity = -1;
		for (int i = 0; i < n; ++i) {
			int maxHere = -(int)1e9, minHere = (int)1e9;
			int maxWhere = -1, minWhere = - 1;
			for (int j = 0 ; j < m; ++j) {
				if (temp[i][j] > maxHere) {
					maxHere = temp[i][j];
					maxWhere = j;
				} 
				if (temp[i][j] < minHere) {
					minHere = temp[i][j];;
					minWhere = j;
				}
			}
			if (currMin > minHere) {
				minCity = i;
				currMin = minHere;
				minDay = minWhere;
			}
			if (currMax < maxHere) {
				maxCity = i;
				currMax = maxHere;
				maxDay = maxWhere;
			}
		}
		System.out.println("Minimum temperature noted on " + minDay + " at "
							+ minCity + " with the temperature " + currMin);
		System.out.println("Minimum temperature noted on " + maxDay + " at "
							+ maxCity + " with the temperature " + currMax);
	}

	int [] ballotReader (int [] votes) {
		int [] ans = new int[6];
		int spoil = 0;
		for (int i = 0; i < votes.length; ++i) {
			if (votes[i] > 5 || votes[i] < 1) {
				spoil++;
				continue;
			}
			ans[votes[i] - 1]++;
		}
		ans[5] = spoil;
		return ans;
	}
}
