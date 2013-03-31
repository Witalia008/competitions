import java.io.*;
import java.util.*;

/**
 * Created by witalia on 12.12.14.
 */
public class Solution {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

//        InputReader in = new InputReader(new FileInputStream(new File("input.txt")));
//        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    private static final int MAXX = 2005;
    private static final int MAXL = MAXX * 2;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] count = new int[MAXL];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            ++count[a[i] + MAXX];
        }
        long[] func = new long[MAXL];
        for (int i = 0; i < MAXL; i++) {
            for (int j = 0; j < MAXL; j++) {
                func[i] += count[j] * Math.abs(j - i);
            }
        }

        int q = in.nextInt();
        int zero = MAXX;
        for (int i = 0; i < q; i++) {
            int x = in.nextInt();
            zero -= x;
            if (zero >= 0 && zero < MAXL) {
                out.println(func[zero]);
            } else if (zero < 0) {
                out.println(func[0] + (long) n * Math.abs(zero));
            } else {
                out.println(func[MAXL - 1] + (long) n * (zero - MAXL + 1));
            }
        }
    }

    private static double round(double value, int places) {
        long factor = (long) Math.pow(10, places);
        value *= factor;
        long temp = Math.round(value);
        return (double) temp / factor;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public float nextFloat() { return Float.parseFloat(next()); }

    public double nextDouble() { return Double.parseDouble(next()); }
}

class Pair<K, V> {
    private K key;
    private V value;

    public K getKey() {
        return key;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public V getValue() {
        return value;
    }

    public void setValue(V value) {
        this.value = value;
    }

    public Pair(K key, V value) {

        this.key = key;
        this.value = value;
    }
}
