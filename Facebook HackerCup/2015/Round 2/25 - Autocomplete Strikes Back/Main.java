import java.io.*;
import java.util.*;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
//        InputReader in = new InputReader(System.in);
//        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        InputReader in = new InputReader(new FileInputStream(new File("input.txt")));
        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    private static final int MAX_L = 26;
    private static final int INF = 1_000_000_000;
    private static int k;

    class Trie {
        Trie[] sons = new Trie[MAX_L];
        int[] F;
        boolean isEnd = false;
        int count = 0;

        Trie() {
            F = new int[k + 1];
            Arrays.fill(F, INF);
            F[0] = 0;
        }
    }

    private void add(Trie v, String s) {
        for (int i = 0; i < s.length(); i++) {
            int cur = s.charAt(i) - 'a';
            ++v.count;
            if (v.sons[cur] == null) {
                v.sons[cur] = new Trie();
            }
            v = v.sons[cur];
        }
        v.isEnd = true;
    }

    private void dfs(Trie v, Trie par, int count) {
        for (int i = 0; i < MAX_L; i++) {
            if (v.sons[i] != null) {
                dfs(v.sons[i], v, count + (v.count == 1 ? 0 : 1));
            }
        }
        for (int i = k; i > 0; i--) {
            if (v.isEnd || i == 1) {
                v.F[i] = Math.min(v.F[i], v.F[i - 1] + count);
            }
        }
        if (par != null) {
            for (int i = k; i > 0; i--) {
                for (int j = 0; j <= i; j++) {
                    par.F[i] = Math.min(par.F[i], par.F[i - j] + v.F[j]);
                }
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            int n = in.nextInt();
            k = in.nextInt();
            Trie root = new Trie();
            for (int i = 0; i < n; i++) {
                add(root, in.next());
            }
            dfs(root, null, 0);
            out.println(root.F[k]);
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
