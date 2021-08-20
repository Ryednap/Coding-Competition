import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

class SpecialBits {
	static FastScanner fs = new FastScanner();
	static long l, r;
	static int k;
	public static void main(String[] args) {
		int qq = fs.nextInt();
		while (qq-- > 0) {
			l = fs.nextLong();
			r = fs.nextLong();
			k = fs.nextInt();
			long ans = l;
			
			if(Long.bitCount(l) <= k) {
				int rem = k - Long.bitCount(l);
				for(int i = 0; i < 64; ++i) {
					if(rem == 0)
						break;
					if((l & (1L << i)) == 0) {
						--rem;
						ans |= (1L << i);
					} 
				}

			} else if(k == 1) {
				ans = 0;
				if(Long.bitCount(l) != 1) {
					ans |= (1L << (msb(l) + 1));
				} else ans = l;

			} else {
				ans = 0;
				int where = -1;
				int piz = k - 1;
				for(int i = msb(l) - 1; i >= 0; --i) {
					//System.out.println("where " + where + " " + i + " " + (l & 1L << i));
					if((l & (1L << i)) == 0) {
						where = i;
					} else {
						if(k == 0) break;
						--k;
					}
				}
				System.out.println("where " + where);
				if(where == -1) {
					ans |= (1L << (msb(l) + 1));
					for(int i = 0; i < k - 1; ++i) {
						ans |= (1L << i);
					}

				} else {
					//System.out.println(where);
					int temp = k - 2;
					ans |= (1L << (where));
					ans |= (1L << msb(l));
					//System.out.println("\nafeter : ans " + ans + " " + "k " + k );
					for(int i = 0; i < temp; ++i) {
						ans |= (1L << i);
					}
				}
			}

			//System.out.println("ans : " + ans);

			if(Long.bitCount(ans) != k) {
				System.out.println(-1);
			} else if(ans >= l && ans <= r) {
				System.out.println(ans);
			} else System.out.println(-1);

		}
	}

	static int msb(long a){
		return log2(Long.highestOneBit(a));
	}

	static int log2(long a) {
		return (int)(Math.log(a) / Math.log(2));
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

		Integer nextInt() {
			return Integer.parseInt(next());
		}
		Long nextLong() {
			return Long.parseLong(next());
		}
	}
}