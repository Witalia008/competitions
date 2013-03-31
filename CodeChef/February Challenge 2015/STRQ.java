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
    private static final String allowed = "chef";
    class Data {
        int[] count = new int[4];
        long[][] cnt = new long[4][4];
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String p = in.next();
        int n = p.length();
        Data[] mas = new Data[n];
        for (int i = 0; i < n; i++) {
            mas[i] = new Data();
            int cur = allowed.indexOf(p.charAt(i));
            for (int j = 0; j < 4; j++) {
                mas[i].count[j] = (i == 0 ? 0 : mas[i - 1].count[j])
                        + (cur == j ? 1 : 0);
                if (i > 0) {
                    for (int k = 0; k < 4; k++) {
                        mas[i].cnt[j][k] = mas[i - 1].cnt[j][k];
                    }
                    mas[i].cnt[j][cur] += mas[i - 1].count[j];
                }
            }
        }

        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int a = allowed.indexOf(in.next().charAt(0));
            int b = allowed.indexOf(in.next().charAt(0));
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;

            long res = mas[r].cnt[a][b];
            if (l > 0) {
                res -= mas[l - 1].cnt[a][b];
                res -= (long) (mas[r].count[b] - mas[l - 1].count[b]) * mas[l - 1].count[a];
            }
            out.println(res);
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
