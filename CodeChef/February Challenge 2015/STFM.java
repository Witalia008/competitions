import java.io.*;
import java.util.*;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
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
    private static final int MOD = 1_000_000_007;
    private static final int MAX_M = 10_000_000;
    private long[] fact;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        fact = new long[m];
        fact[0] = 1;
        for (int i = 1; i < m; i++) {
            fact[i] = mulMod(fact[i - 1], i, m);
        }
//        System.out.println(Arrays.toString(fact));

        long ans = 0;
        for (int i = 0; i < n; i++) {
            long p = in.nextLong();
            long cur = m - 1;
            if (p + 1 < m) {
                cur = (fact[(int)p + 1] + m - 1) % m;
            }
            if (p % 2 == 0) {
                cur = addMod(cur, mulMod(mulMod(p / 2, p + 1, m), p, m), m);
            } else {
                cur = addMod(cur, mulMod(mulMod(p, (p + 1) / 2, m), p, m), m);
            }
            ans = addMod(ans, cur, m);
        }
        out.println(ans);
    }

    private long addMod(long a, long b, long m) {
        return (a + b) % m;
    }
    private long mulMod(long a, long b, long m) {
        return ((a % m) * (b % m)) % m;
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
