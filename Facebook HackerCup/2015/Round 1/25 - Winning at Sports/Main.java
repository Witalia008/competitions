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
    private static final int MAXN = 2005;
    private static final int MOD = 1_000_000_007;
    private static long[][] F = new long[MAXN][MAXN];
    private static long[][] G = new long[MAXN][MAXN];
    static {
        F[1][0] = 1;
        G[0][0] = 1;
        for (int i = 1; i < MAXN; i++) {
            for (int j = 0; j <= i; j++) {
                if (i != j) {
                    calc(F, i, j, 1);
                }
                calc(G, i, j, 0);
            }
        }
    }

    private static void calc(long[][] f, int i, int j, int d) {
        if (j > 0) {
            f[i][j] = add(f[i][j], f[i][j - 1]);
        }
        if (i > j + d) {
            f[i][j] = add(f[i][j], f[i - 1][j]);
        }
    }

    private static long add(long a, long b) {
        return (a + b) % MOD;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            String[] inp = in.next().split("-");
            int a = Integer.parseInt(inp[0]);
            int b = Integer.parseInt(inp[1]);
            out.println(F[a][b] + " " + G[b][b]);
        }
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

}
