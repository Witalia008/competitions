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

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            String s = in.next();
            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < 2; i++) {
                int cur = 0;
                for (int j = 0; j < s.length(); j++) {
                    char x = ((i + j) % 2 == 0 ? '-' : '+');
                    cur += s.charAt(j) == x ? 0 : 1;
                }
                ans = Math.min(ans, cur);
            }
            System.out.println(ans);
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
