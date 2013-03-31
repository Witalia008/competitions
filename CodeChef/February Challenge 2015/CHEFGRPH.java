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
    class Edge {
        long x;
        int y;
        int idx;
        boolean isLeft;

        public Edge(long x, int y, int idx, boolean isLeft) {
            this.x = x;
            this.y = y;
            this.idx = idx;
            this.isLeft = isLeft;
        }
    }

    private long addMod(long a, long b, long m) {
        return (a + b) % m;
    }

    private long mulMod(long a, long b, long m) {
        return ((a % m) * (b % m)) % m;
    }

    private long pow(long a, long b, long m) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = mulMod(res, a, m);
            }
            a = mulMod(a, a, m);
            b >>= 1;
        }
        return res;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
//        System.err.print("Test #" + testNumber + " - ");
        long n = in.nextLong();
        int m = in.nextInt();
        int k = in.nextInt();
        Edge[] arr = new Edge[k * 2];
        for (int i = 0; i < k; i++) {
            long a = in.nextLong();
            int ay = in.nextInt();
            long b = in.nextLong();
            int by = in.nextInt();
            arr[i * 2] = new Edge(a, ay, i, true);
            arr[i * 2 + 1] = new Edge(b, by, i, false);
        }
        Arrays.sort(arr, (a, b) -> a.x < b.x ? -1 : 1);

        long res = 1;
        long prev = 0;
        long[] values = new long[k];
        long[] valY = new long[m];
        Arrays.fill(valY, 0);
        for (int i = 0; i < 2 * k; ) {
            int j = i;
            while (j + 1 < 2 * k && arr[j + 1].x == arr[i].x) {
                ++j;
            }
            //#region processing
            // for all ys of right end remember their count
            for (int l = i; l <= j; l++) {
                if (!arr[l].isLeft) {
                    valY[arr[l].y] += values[arr[l].idx];
                }
            }
            res = mulMod(res, pow(m, arr[i].x - prev - 1, MOD), MOD);
            for (int l = i; l <= j; l++) {
                if (arr[l].isLeft) {
                    values[arr[l].idx] = valY[arr[l].y] + res;
                }
            }
            if (arr[i].x != 0 && arr[i].x != n + 1) {
                res = mulMod(res, m, MOD);
            }
            // revert values for ys
            for (int l = i; l <= j; l++) {
                if (!arr[l].isLeft) {
                    res += valY[arr[l].y];
                    valY[arr[l].y] = 0;
                }
            }
            //#endregion
            prev = arr[i].x;
            i = j + 1;
        }

        res = mulMod(res, pow(m, n - prev, MOD), MOD);
        out.println(res);
//        System.err.println("ok");
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
